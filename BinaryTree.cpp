#include <iostream>
#include "BinaryTree.h"

using namespace std;

BinaryTree::BinaryTree() {
    length = 0;
    root = nullptr;
}

BinaryTree::~BinaryTree() {
    clearAll(root);
}

void BinaryTree::clearAll(TreeType *tree) {
    if (tree == nullptr) {
	return;
    }

    if (tree->left == nullptr) {
	clearAll(tree->left);
    }

    if (tree->right == nullptr) {
	clearAll(tree->right);
    }

    delete tree;
    return;
}

void BinaryTree::insert(ItemType key) {
    putItem(key, root);
}

void BinaryTree::putItem(ItemType item, TreeType *&tree) {
    if (tree == nullptr) {
	tree = new TreeType;
	tree->right = nullptr;
	tree->left = nullptr;
	tree->key = item;
    }

    else {
	
	if (item.compareTo(tree->key) == LESS) {
	    putItem(item, tree->left);
	}
	
	if (item.compareTo(tree->key) == EQUAL) {
	    cout << "\nItem already exists" << endl;
	    delete tree;
	}

	if (item.compareTo(tree->key) == GREATER) {
	    putItem(item, tree->right);
	}
    }
}

void BinaryTree::inOrder() const {
    inOrderTraversal(root);
    cout << endl;
}

void BinaryTree::inOrderTraversal(TreeType* node) const {
    if(node != nullptr) {
	inOrderTraversal(node->left);

	cout << node->key.getValue() << " ";

	inOrderTraversal(node->right);
    }
}

