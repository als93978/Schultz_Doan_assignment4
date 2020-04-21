#include <iostream>
#include "BinaryTree.h"

using namespace std;

BinaryTree::BinaryTree() {
    root = nullptr;
}

BinaryTree::~BinaryTree() {
    clearAll(root);
}

void BinaryTree::clearAll(TreeType *tree) {
    if (tree == nullptr)
	return;

    // essentially, do a postorder traversal because its the most efficient.
    // go to the children first, delete those, and then delete the parents.
    // so the leaves will be deleted first, then all the other nodes up to
    // and including the root.
    clearAll(tree->left); // left subtree
    clearAll(tree->right); // right subtree
    delete tree;
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

	else if (item.compareTo(tree->key) == GREATER) {
	    putItem(item, tree->right); // insert in right subtree
	}

	else {
	    cout << "\nItem already exists" << endl;
	    //delete tree;
	    return;
	}
    }
}

void BinaryTree::deleteItem(ItemType key) {
    searchAndDelete(root, key);
}

bool BinaryTree::searchAndDelete(TreeType*& node, ItemType key) {
    if(node == nullptr) { // item does not exist
	cout << "\nItem not in tree." << endl;
	
	return false;
    }
	
    else if(key.compareTo(node->key) == EQUAL) { // found the node, now delete it
	deleteNode(node);

	return true;
    }

    else {
	if(key.compareTo(node->key) == LESS) // item is in left subtree, go there
	    searchAndDelete(node->left, key);

	else if(key.compareTo(node->key) == GREATER) // item is in right subtree, go there
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
    // keep going right until we get to null
    if(node->right == nullptr)
	return node->key;
    else
    	return getPredecessor(node->right);
}

void BinaryTree::retrieve(ItemType& item, bool& found) const {
    search(root, item, found);
}

void BinaryTree::search(TreeType* node, ItemType& item, bool& found) const {
    if(node == nullptr) { // item does not exist
	cout << "\nItem not in tree." << endl;

	found = false;
    }
	
    else if(item.compareTo(node->key) == EQUAL) { // item found
	cout << "\nItem found in tree." << endl;
	found = true;
    }

    else {
	if(item.compareTo(node->key) == LESS) // item is in left subtree, go there
	    search(node->left, item, found);

	else if(item.compareTo(node->key) == GREATER) // item is in right subtree, go there
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
	inOrderTraversal(node->left); // go to left subtree first

	cout << node->key.getValue() << " "; // then the node

	inOrderTraversal(node->right); // then the right subtree
    }
}

void BinaryTree::postOrder() const {
    postOrderTraversal(root);
    cout << endl;
}

void BinaryTree::postOrderTraversal(TreeType* node) const {
    if(node != nullptr) {
	postOrderTraversal(node->left); // go to left subtree
	
	postOrderTraversal(node->right); // then the right subtree
	
	cout << node->key.getValue() << " "; // and then the node
    }
}

int BinaryTree::getLength() const {
    return calculateLength(root);
}

int BinaryTree::calculateLength(TreeType* node) const {
    if(node == nullptr) {
	return 0;
    }

    // the size/length of a BST is defined recursively as the size/length of the
    // left subtree + the right subtree and the size of the root, which is 1.
    return calculateLength(node->left) + calculateLength(node->right) + 1;
}

void BinaryTree::getSameLevelNonsiblings(ItemType &key) {
    bool found = false;
    int val = findLevel(key, root, 0);
    printSameLevelNonsiblings(root, key, val + 1, found);

    if (!found) {
	cout << "No same level non siblings found" << endl;
    }
}

void BinaryTree::printSameLevelNonsiblings(TreeType *&tree, ItemType &item, int level, bool &found) {
    if (level < 2 || tree == nullptr) {
	return;
    }

    if (level == 2) {
	if (tree->left == nullptr) {
	    return;
	}

	if (tree->right == nullptr) {
	    return;
	}

	if (tree->left->key.getValue() == item.getValue() || tree->right->key.getValue() == item.getValue()) { // if values are siblings
	    return;
	}
	 
	if (tree->left != nullptr && tree->left->key.getValue() != item.getValue()) {
	    cout << tree->left->key.getValue() << " "; // prints value in the left subtree that is nonsibling
	    found = true;
	}

	if (tree->right != nullptr && tree->right->key.getValue() != item.getValue()) {
	    cout << tree->right->key.getValue() << " "; // prints value in the right subtree that is nonsibling
	    found = true;
	}
    }

    else if (level > 2) {
	printSameLevelNonsiblings(tree->left, item, level-1, found);
	printSameLevelNonsiblings(tree->right, item, level-1, found);
    }
}

int BinaryTree::findLevel(ItemType &item, TreeType *&tree, int level) {
    if (tree == nullptr) {
	return 0;
    }

    if (tree->key.getValue() == item.getValue()) {
	return level;
    }

    int traverseLevel = findLevel(item, tree->left, level + 1);

    if (traverseLevel != 0) {
	return traverseLevel;
    }

    else {
	return findLevel(item, tree->right, level + 1);
    }
}
