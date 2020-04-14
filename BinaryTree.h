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
    BinaryTree();
    ~BinaryTree();
    void clearAll(TreeType *tree);
    void insert(ItemType key);
    void putItem(ItemType item, TreeType *&tree);
    void deleteItem(ItemType key);
    void retrieve(ItemType &item, bool &found) const;
    void preOrder() const;
    void inOrder() const;
    void postOrder() const;
    int getLength() const;
    void getSameLevelNonsiblings(ItemType &key);
};

#endif
