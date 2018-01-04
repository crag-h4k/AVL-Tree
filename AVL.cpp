#include "AVL.h"
#include <iostream>
#include <iomanip>

using namespace std;

AVL::AVL(){
	root = nullptr;
}

AVL::~AVL(){
	destroyTree(root);
}

void AVL::destroyTree(Node *&leaf){
	if (leaf != nullptr){
		destroyTree(leaf->left);
		destroyTree(leaf->right);
		delete leaf;
	}
}


void AVL::print(){
	print(root, 0);
}

void AVL::print(Node *leaf, int depth){
	cout << setw(4 * depth) << "";
	if (leaf == nullptr){
		cout << "[empty]" << endl;
	}
	else if ((leaf->right == nullptr) && (leaf->left == nullptr)){
		cout << leaf->value << " [leaf]" << endl;
	}
	else{
		cout << leaf->value << endl;
		print(leaf->right, depth + 1);
		print(leaf->left, depth + 1);
	}
}

void AVL::insert(int val){
	insert(val, root);
}

void AVL::insert(int val, Node *&leaf){
	if (leaf != nullptr){
		if (val < leaf->value){
			insert(val, leaf->left);
			leaf->updateHeight();
			rebalance(leaf);
		}
		else{
			insert(val, leaf->right);
			leaf->updateHeight();
			rebalance(leaf);
		}
	}
	else {
		leaf = new Node(val);
		leaf->updateHeight();
	}
}


AVL::Node* AVL::rotateRight(Node *&N){
	Node *C = N->left;
	N->left = C->right;
	C->right = N;
	N->updateHeight();
	return C;
}

AVL::Node* AVL::rotateLeft(Node *&N){
	Node *C = N->right;
	N->right = C->left;
	C->left = N;
	N->updateHeight();
	return C;
}

AVL::Node* AVL::rotateRightLeft(Node *&N){
	Node *C = N->right;
	N->right = rotateRight(C);
	return rotateLeft(N);
}

AVL::Node* AVL::rotateLeftRight(Node *&N){
	Node *C = N->left;
	N->left = rotateLeft(C);
	return rotateRight(N);
}

int AVL::getHeightDifference(Node *leaf){
	int leftHeight = (leaf->left != nullptr) ? leaf->left->height : 0;
	int rightHeight = (leaf->right != nullptr) ? leaf->right->height : 0;
	return leftHeight - rightHeight;
}

void AVL::rebalance(Node *&N){
	int heightDifference = getHeightDifference(N);

	if (heightDifference > 1){
		if (getHeightDifference(N->left) > 0){
			N = rotateRight(N);
		}
		else{
			N = rotateLeftRight(N);
		}
	}
	else if (heightDifference < -1){
		if (getHeightDifference(N->right) < 0){
			N = rotateLeft(N);
		}
		else{
			N = rotateRightLeft(N);
		}
	}

}
