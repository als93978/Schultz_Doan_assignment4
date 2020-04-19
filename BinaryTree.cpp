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

void BinaryTree::deleteItem(ItemType key) {
    searchAndDelete(root, key);
}

bool BinaryTree::searchAndDelete(TreeType*& node, ItemType key) {
    if(node == nullptr)
	return false;
	
    else if(key.compareTo(node->key) == EQUAL) {
	deleteNode(node);

	return true;
    }

    else {
	if(key.compareTo(node->key) == LESS)
	    searchAndDelete(node->left, key);

	else if(key.compareTo(node->key) == GREATER)
	    searchAndDelete(node->right, key);
    }

    return false;
}

void BinaryTree::deleteNode(TreeType*& targetNode) {
    TreeType* temp = targetNode;

    // targetNode has two children
    if(targetNode->left != nullptr && targetNode->right != nullptr) {
        ItemType predecessorItem = getPredecessor(targetNode->left);
	targetNode->key = predecessorItem;
	searchAndDelete(targetNode->left, predecessorItem);
    }
    
    // targetNode has one child
    else if(targetNode->left != nullptr) {
	targetNode = targetNode->left;

	delete temp;
    }

    // targetNode has one child
    else if(targetNode->right != nullptr) {
	targetNode = targetNode->right;

	delete temp;
    }

    // targetNode has no children
    else {
	targetNode = nullptr;
	    
	delete temp;
    }
}

ItemType BinaryTree::getPredecessor(TreeType*& node) const {
    if(node->right == nullptr)
	return node->key;
    else
    	return getPredecessor(node->right);
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

