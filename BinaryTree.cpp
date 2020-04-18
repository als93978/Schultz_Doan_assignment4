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
	clearAll(tree->left); // left subtree
    }

    if (tree->right == nullptr) {
	clearAll(tree->right); // right subtree
    }

    delete tree;
    return;
}

void BinaryTree::insert(ItemType key) {
    putItem(key, root);
}

void BinaryTree::putItem(ItemType item, TreeType *&tree) {
    if (tree == nullptr) { // insertion position found
	tree = new TreeType;
	tree->right = nullptr;
	tree->left = nullptr;
	tree->key = item;
    }

    else {
	
	if (item.compareTo(tree->key) == LESS) {
	    putItem(item, tree->left); // insert in left subtree
	}
	
	if (item.compareTo(tree->key) == EQUAL) {
	    cout << "\nItem already exists" << endl;
	    delete tree;
	}

	if (item.compareTo(tree->key) == GREATER) {
	    putItem(item, tree->right); // insert in right subtree
	}
    }
}

void BinaryTree::retrieve(ItemType& item, bool& found) const {
    search(root, item, found);
}

void BinaryTree::search(TreeType* node, ItemType& item, bool& found) const {
    if(node == nullptr)
	found = false;

    else if(item.compareTo(node->key) == EQUAL)
	found = true;

    else {
	if(item.compareTo(node->key) == LESS)
	    search(node->left, item, found);

	else if(item.compareTo(node->key) == GREATER)
	    search(node->right, item, found);
    }
}

void BinaryTree::preOrder() const {
    preOrderTraversal(root);
    cout << endl;
}

void BinaryTree::preOrderTraversal(TreeType* node) const {
    if (node != nullptr) {
	cout << node->key.getValue() << " ";
	preOrderTraversal(node->left); // traverse the left subtree
	preOrderTraversal(node->right); // traverse the right subtree
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

void BinaryTree::postOrder() const {
    postOrderTraversal(root);
    cout << endl;
}

void BinaryTree::postOrderTraversal(TreeType* node) const {
    if(node != nullptr) {
	postOrderTraversal(node->left);
	
	postOrderTraversal(node->right);
	
	cout << node->key.getValue() << " ";
    }
}

int BinaryTree::getLength() const {
    return length;
}
