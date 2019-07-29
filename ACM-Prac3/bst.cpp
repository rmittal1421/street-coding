#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;

	Node(int val, Node* leftN, Node* rightN) {
		data = val;
		left = leftN;
		right = rightN;
	}
};

bool checkLeft(Node* n, int val) {
	if ((n == NULL) || (n->data < val)) return true;
	else return false;
}

bool checkRight(Node* n, int val) {
	if ((n == NULL) || (n->data > val)) return true;
	else return false;
}

bool checkBST(Node* root) {
	if (root == NULL) return true;
	if (checkLeft(root->left, root->data) && checkRight(root->right, root->data)) {
		return checkBST(root->left) && checkBST(root->right);
	} else {
		return false;
	}
}

int main() {
	
	Node* left2 = new Node(6, NULL, NULL);
	Node* right2 = new Node(9, NULL, NULL);
	Node* left1 = new Node(2, NULL, NULL);
	Node* right1 = new Node(3, NULL, NULL);
	Node* left = new Node(2, left1, right1);
	Node* right = new Node(10, left2, right2);
	Node* root = new Node(4, left, right);
	cout << checkBST(root) << endl;
}