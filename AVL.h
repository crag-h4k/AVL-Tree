#pragma once

class AVL
{
public:
	AVL();
	~AVL();
	struct Node{
		int value;
		Node *left;
		Node *right;
		int height;
		Node(int val){
			value = val;
			left = nullptr;
			right = nullptr;
			height = 0;
		}
		void updateHeight(){
			int leftHeight = 0;
			int rightHeight = 0;
			if (left != nullptr){
				leftHeight = left->height;
			}
			else {
				leftHeight = 0;
			}
			if (right != nullptr){
				rightHeight = right->height;
			}
			else {
				rightHeight = 0;
			}

			if (leftHeight > rightHeight) {
				height = leftHeight + 1;
			}
			else {
				height = rightHeight + 1;
			}
		}
	};

	void print();
	void insert(int val);
	Node *rotateLeft(Node *&N);
	Node *rotateRight(Node *&N);
	Node *rotateRightLeft(Node *&N);
	Node *rotateLeftRight(Node *&N);
	void rebalance(Node *&N);



private:
	Node *root;
	void print(Node *leaf, int depth);
	void insert(int val, Node *&leaf);
	void destroyTree(Node *&leaf);
	int getHeightDifference(Node *leaf);
};
