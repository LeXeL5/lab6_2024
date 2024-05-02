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
	Node* goTo(int value) {
		Node* current = root;
		while (current != nullptr) {
			if (value == current->value) {
				return current;
			}
			else if (value < current->value) {
				current = current->left;
			}
			else {
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
		Node* parent = nullptr;
		Node* current = root;
		while (current != nullptr) {
			if (value == current->value) {
				break;
			}
			parent = current;
			if (value < current->value) {
				current = current->left;
			}
			else {
				current = current->right;
			}
		}
		if (current == nullptr) return;
		
		if ((current->right != nullptr) && (current->left != nullptr)) {
			parent = current;
			Node* min = current->right;
			while (min->left != nullptr) {
				parent = min;
				min = min->left;
			}
			current->value = min->value;
			current = min;
		}
		if (current != root) {
			Node* child = nullptr;
			if (current->left != nullptr) {
				child = current->left;
			}
			else child = current->right;
			if (parent->left == current) {
				parent->left = child;
			}
			else if (parent->right == current) {
				parent->right = child;
			}
		}
		else {
			root = current->left;
		}
		delete current;
		size--;
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