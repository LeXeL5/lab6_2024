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
	int count() {
		return size;
	}
	void add(int value) {
		Node* newNode = new Node;
		newNode->value = value;
		size++;
		if (count() == 1){
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
			else {
				if (current->right != nullptr) {
					current = current->right;
				}
				else {
					current->right = newNode;
					return;
				}
			}
		}
	}
	/*void goDeeper(Node* current, int level) {
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
	}*/
	bool recursionContain(Node* current, int value) {
		if (!count()) return false;
		bool flag = false;
		if (current->left != nullptr) {
			flag = recursionContain(current->left, value);
		}
		if (current->right != nullptr) {
			flag = recursionContain(current->right, value);
		}
		if (current->value == value) {
			flag = true;
		}
		return flag;
	}/*
	bool containst(Node* current, int level) {
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
	}*/
};
void main() {
	Tree tree;
	tree.add(3);
	tree.add(2);
	tree.add(1);
	bool ooo = tree.recursionContain(tree.root, 3);
	if (ooo) {
		cout << "wow";
	}

	//tree.goDeeper(tree.root, -1);
}