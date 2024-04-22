#include <iostream>
using namespace std;

struct Node {
	Node* left = nullptr;
	Node* right = nullptr;
	Node* up = nullptr;
	int value = 0;
};
struct Tree {
	int size = 0;
	Node* root = nullptr;
	Node* current = nullptr;
	int count() {
		return size;
	}
	void add(int value) {
		Node* newNode = new Node;
		newNode->value = value;
		current = root;
		if (!count()) {
			root = newNode;
		}
		else {
			while (newNode->up == nullptr) {
				if (value < current->value) {
					if (current->left != nullptr) {
						current = current->left;
					}
					else {
						current->left = newNode;
						newNode->up = current->left;
					}
				}
				else {
					if (current->right != nullptr) {
						current = current->right;
					}
					else {
						current->right = newNode;
						newNode->up = current->right;
					}
				}
			}
		}
		current = root;
		size++;
	}
	void goDeeper(Node* current, int level) {
		if (!count()) return;
		level++;
		if (current->left != nullptr) {
			goDeeper(current->left, level);
		}
		if (current->right != nullptr) {
			goDeeper(current->right, level);
		}
		cout << "Level: " << level << "\tValue: " << current->value << endl;
		level--;
	}
};
void main() {
	Tree tree;
	tree.add(3);
	tree.add(2);
	tree.add(1);
	tree.goDeeper(tree.root, -1);
}