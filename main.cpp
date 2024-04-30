#include <iostream>
using namespace std;

struct Node {
	Node* left = nullptr;
	Node* right = nullptr;
	int value = 0;
};
struct Tree {
	int size = 0;
	Node* root = nullptr;

	bool isLeaf(Node* node) {
		if (!count()) return false;
		if ((node->right == nullptr) and (node->left == nullptr)) {
			return true;
		}
		else {
			return false;
		}
	}
	Node* goToParent(int value) {
		Node* current = root;
		Node* parent = nullptr;
		while (current != nullptr) {
			if (value == current->value) {
				return parent;
			}
			else if (value < current->value) {
				parent = current;
				current = current->left;
			}
			else if (value > current->value) {
				parent = current;
				current = current->right;
			}
		}
		return nullptr;
	}
	Node* goTo(int value) {
		Node* current = root;
		Node* parent = nullptr;
		while (current != nullptr) {
			if (value == current->value) {
				return current;
			}
			else if (value < current->value) {
				parent = current;
				current = current->left;
			}
			else if (value > current->value) {
				parent = current;
				current = current->right;
			}
		}
		return nullptr;
	}

	void add(int value) {
		Node* newNode = new Node;
		newNode->value = value;
		size++;
		if (count() == 1) {
			root = newNode;
			return;
		}
		Node* current = root;
		while (true) {
			if (value < current->value) {
				if (current->left != nullptr) {
					current = current->left;
				}
				else {
					current->left = newNode;
					return;
				}
			}
			else if (value > current->value) {
				if (current->right != nullptr) {
					current = current->right;
				}
				else {
					current->right = newNode;
					return;
				}
			}
			else if (value == current->value) {
				delete newNode;
				size--;
				return;
			}
		}
	}
	void remove(int value) {
		Node* deleteNodeParent = nullptr;
		Node* deleteNode = root;
		while (deleteNode != nullptr) {
			if (deleteNode->value == value) {
				break;
			}
			deleteNodeParent = deleteNode;
			if (value < deleteNode->value) {
				deleteNode = deleteNode->left;
			}
			else if (value > deleteNode->value) {
				deleteNode = deleteNode->right;
			}
		}
		while (true) {
			if (deleteNode == nullptr) return;
			if ((deleteNode->left == nullptr) and (deleteNode->right == nullptr)) {
				if (deleteNodeParent != nullptr) {
					if (deleteNodeParent->left == deleteNode) deleteNodeParent->left = nullptr;
					if (deleteNodeParent->right == deleteNode) deleteNodeParent->right = nullptr;
				}
				if (root == deleteNode) root = nullptr;
				delete deleteNode;
				size--;
				return;
			}
			else if ((deleteNode->left != nullptr) and (deleteNode->right == nullptr)) {
				if (deleteNodeParent != nullptr) {
					if (deleteNodeParent->left == deleteNode) deleteNodeParent->left = deleteNode->left;
					if (deleteNodeParent->right == deleteNode) deleteNodeParent->right = deleteNode->left;
				}
				if (root == deleteNode) root = deleteNode->left;
				delete deleteNode;
				size--;
				return;
			}
			else if ((deleteNode->left == nullptr) and (deleteNode->right != nullptr)) {
				if (deleteNodeParent != nullptr) {
					if (deleteNodeParent->left == deleteNode) deleteNodeParent->left = deleteNode->right;
					if (deleteNodeParent->right == deleteNode) deleteNodeParent->right = deleteNode->right;
				}
				if (root == deleteNode) root = deleteNode->right;
				delete deleteNode;
				size--;
				return;
			}
			else if ((deleteNode->left != nullptr) and (deleteNode->right != nullptr)) {
				Node* current = deleteNode;
				Node* currentParent = deleteNode;
				current = current->right;
				while (current->left != nullptr) {
					currentParent = current;
					current = current->left;
				}
				deleteNode->value = current->value;
				deleteNodeParent = currentParent;
				deleteNode = current;
			}
		}
	}
	void clear(Node* current) {
		if (current == nullptr) return;
		clear(current->left);
		clear(current->right);
		delete current;
		size--;
	}
	void clear() {
		clear(root);
		root = nullptr;
	}
	bool contains(int value) {
		if (goTo(value) != nullptr) {
			return true;
		}
		else {
			return false;
		}
	}
	int count() {
		return size;
	}
};
void main() {
	Tree tree;
	int input = 0;
	cout << "Enter sequence of numbers (sequence end sign 0):" << endl;
	cin >> input;
	while (input) {
		tree.add(input);
		cin >> input;
	}

	//убрать
	cout << "Enter numbers to remove (sequence end sign 0):" << endl;
	cin >> input;
	while (input) {
		tree.remove(input);
		cin >> input;
	}

	cout << "Enter numbers to search (sequence end sign 0):" << endl;
	cin >> input;
	while (input) {
		if (tree.contains(input)) {
			cout << "This number is on the tree" << endl;
		}
		else {
			cout << "This number is NOT on the tree" << endl;
		}
		cin >> input;
	}
	tree.clear();
}