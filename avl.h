#ifndef _AVL_H
#define _AVL_H

struct avlNode
{
    int data;
    avlNode* left;
    avlNode* right;
    int height;
    avlNode(int data);
};

typedef avlNode* avlNodePtr;

class AvlTree
{
private:
    avlNodePtr root;
public:
    AvlTree();
    avlNodePtr insert(avlNodePtr, avlNodePtr);
    avlNodePtr insert(int);

    avlNodePtr rotateRight(avlNodePtr);
    avlNodePtr rotateLeft(avlNodePtr);
    avlNodePtr rotateLeftRight(avlNodePtr);
    avlNodePtr rotateRightLeft(avlNodePtr);

    bool search(int, avlNodePtr);
    bool search(int);

    avlNodePtr remove(int, avlNodePtr);
    avlNodePtr remove(int);

    int findMin(avlNodePtr);
    int findMin();
    avlNodePtr findMinPtr(avlNodePtr);

    void print();
    void inorder();
    void inorder(avlNodePtr);

};

#endif