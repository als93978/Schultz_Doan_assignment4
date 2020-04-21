#ifndef BINARYTREE_H
#define BINARY_H

#include "ItemType.h"

struct TreeType {
    ItemType key;
    TreeType *left;
    TreeType *right;
};

class BinaryTree {
    TreeType *root;

 public:
    // Author: David Doan
    BinaryTree(); // constructor

    // Author: David Doan
    ~BinaryTree(); // destructor

    // Author: David Doan
    void clearAll(TreeType *tree); // recursive function for the destructor

    // Author: David Doan
    void insert(ItemType key); // inserts a node with the value of key into the tree

    // Author: David Doan
    void putItem(ItemType item, TreeType *&tree); // recursive function for the insert function

    // Author: Austin Schultz
    void deleteItem(ItemType key);

    // Author: Austin Schultz
    bool searchAndDelete(TreeType*& node, ItemType key);
    
    // Author: Austin Schultz
    void deleteNode(TreeType*& targetNode);

    // Author: Austin Schultz
    ItemType getPredecessor(TreeType*& node) const;
    
    // Author: Austin Schultz
    void retrieve(ItemType &item, bool &found) const;

    // Author: Austin Schultz
    void search(TreeType* node, ItemType& item, bool& found) const;
    
    // Author: David Doan
    void preOrder() const; // prints out the binary tree in pre-order traversal

    // Author: David Doan
    void preOrderTraversal(TreeType* node) const; // recursive function for the pre-order function

    // Author: Austin Schultz
    void inOrder() const;

    // Author: Austin Schultz
    void inOrderTraversal(TreeType* node) const;
    
    // Author: Austin Schultz
    void postOrder() const;

    // Author: Austin Schultz
    void postOrderTraversal(TreeType* node) const;
    
    // Author: David Doan
    int getLength() const; // returns the length of the tree

    // Author: Austin Schultz
    int calculateLength(TreeType* node) const; // calculates the length
    
    // Author: David Doan
    void getSameLevelNonsiblings(ItemType &key); // this function gets the values that are in the same level and not siblings

    // Author: David Doan
    void printSameLevelNonsiblings(TreeType *&tree, ItemType &item, int level, bool &found); // recursive function that prints the values that are in the same level and not siblings

    // Author: David Doan
    int findLevel(ItemType &item, TreeType *&tree, int level); // a recursive function that finds the level that the items are in
};

#endif
