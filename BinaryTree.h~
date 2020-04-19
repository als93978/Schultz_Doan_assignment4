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
    int length;

 public:
    // Author: David Doan
    BinaryTree();

    // Author: David Doan
    ~BinaryTree();

    // Author: David Doan
    void clearAll(TreeType *tree);

    // Author: David Doan
    void insert(ItemType key);

    // Author: David Doan
    void putItem(ItemType item, TreeType *&tree);

    // Author: Austin Schultz
    void deleteItem(ItemType key);

    // Author: Austin Schultz
    void retrieve(ItemType &item, bool &found) const;

    // Author: Austin Schultz
    void search(TreeType* node, ItemType& item, bool& found) const;
    
    // Author: David Doan
    void preOrder() const;

    // Author: David Doan
    void preOrderTraversal(TreeType* node) const;

    // Author: Austin Schultz
    void inOrder() const;

    // Author: Austin Schultz
    void inOrderTraversal(TreeType* node) const;
    
    // Author: Austin Schultz
    void postOrder() const;

    // Author: Austin Schultz
    void postOrderTraversal(TreeType* node) const;
    
    // Author: David Doan
    int getLength() const;

    // Author: Austin Schultz
    void getSameLevelNonsiblings(ItemType &key);
};

#endif
