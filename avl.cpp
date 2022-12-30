#include<iostream>
#include "avl.h"

using namespace std;

int getHeight(avlNodePtr node)
{
    return (!node)?0:node->height;
}

int getBalance(avlNodePtr node)
{
    return getHeight(node->left)-getHeight(node->right);
}

int max(int a, int b)
{
    if(a>b) return a;
    return b;
}

avlNode::avlNode(int data)
{
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
    this->height = 1;
}

AvlTree::AvlTree()
{
    this->root = nullptr;
}

avlNodePtr AvlTree::insert(avlNodePtr newNode, avlNodePtr root)
{
    if(root == nullptr)
        return newNode;

    if(newNode->data < root->data)
    {
        root->left = insert(newNode, root->left);
    }
    else if(newNode->data > root->data)
    {
        root->right = insert(newNode, root->right);
    }

    root->height = 1+max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    if(balance > 1)
    {
        if(newNode->data<root->left->data)
            root = rotateRight(root);
        else
            root = rotateLeftRight(root);

    }
    else if(balance < -1)
    {
        if(newNode->data<root->right->data)
            root = rotateRightLeft(root);
        else
            root = rotateLeft(root);
    }

    return root;
}

avlNodePtr AvlTree::insert(int data)
{
    cout<<"Inserting : "<<data<<endl;

    avlNodePtr newNode = new avlNode(data);
    this->root = insert(newNode, this->root);
    return this->root;
}

/*
1. Rotate Right

            z                       y
          /   \                   /   \
        y       t4   ----->     x       z
      /   \                   /   \    /  \
    x       t3              t1     t2 t3   t4
  /   \
t1      t2

*/

avlNodePtr AvlTree::rotateRight(avlNodePtr z)
{
    avlNodePtr y = z->left;
    z->left = y->right;
    y->right = z;

    z->height = 1+max(getHeight(z->left), getHeight(z->right));
    y->height = 1+max(getHeight(y->left), getHeight(y->right));

    return y;
}

/*
2. Rotate Left

            z                                  y
          /   \                              /  \
        t1     y                            z    x
              / \       ------->           / \  / \
            t2   x                       t1  t2 t3 t4
                / \
               t3  t4

*/

avlNodePtr AvlTree::rotateLeft(avlNodePtr z)
{
    avlNodePtr y = z->right;
    z->right = y->left;
    y->left = z;

    z->height = 1+max(getHeight(z->left), getHeight(z->right));
    y->height = 1+max(getHeight(y->left), getHeight(y->right));

    return y;
}

/*
3. Rotate Left Right

            z                               z
          /   \                           /   \
        y       t4                       x     t4
      /   \            ----->           / \              ------> (Case 1: Right Rotate -- apply 1 now)
    t1     x                           y   t3
          / \                         / \
        t2   t3                      t1 t2

*/

avlNodePtr AvlTree::rotateLeftRight(avlNodePtr z)
{
    z->left = rotateLeft(z->left);
    return rotateRight(z);
}

/*
4. Rotate Right Left

            z                                   z  
          /   \                               /   \
         t1    y                             t1    x
             /   \        ------->                / \     ------> (Case 2: Left Rotate -- apply 2 now)
            x    t4                              t2  y
           / \                                      / \
         t2  t3                                    t3  t4

*/

avlNodePtr AvlTree::rotateRightLeft(avlNodePtr z)
{
    z->right = rotateRight(z->right);
    return rotateLeft(z);
}

bool AvlTree::search(int data, avlNodePtr root)
{
    if(root == nullptr)
        return false;
    
    if(root->data == data)
        return true;
    
    if(data < root->data)
        return search(data, root->left);
    
    return search(data, root->right);
}

bool AvlTree::search(int data)
{
    bool ret = search(data, this->root);
    if(ret == true)
        cout<<data<<" is Present."<<endl;
    else
        cout<<data<<" is Not present."<<endl;
    return ret;
}

avlNodePtr AvlTree::remove(int data, avlNodePtr root)
{
    if(root == nullptr)
        return nullptr;
    
    if(data < root->data)
    {
        root->left = remove(data, root->left);
    }
    else if(data > root->data)
    {
        root->right = remove(data, root->right);
    }
    else
    {
        if(root->left && root->right)
        {
            avlNodePtr ptr = findMinPtr(root->right);
            root->data = ptr->data;
            root->right = remove(ptr->data, root->right);
        }
        else
        {
            avlNodePtr ptr = root;

            if(!root->left && !root->right)
            {
                delete ptr;
                return nullptr;
            }
            else if(!root->left)
            {
                
                root = root->right;
            }
            else
            {
                root = root->left;
            }
            delete ptr;
        }
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);
    if(balance > 1)
    {
        if(data > root->left->data)
            root = rotateRight(root);
        else
            root = rotateLeftRight(root);
    }
    else if(balance < -1)
    {
        if(data < root->right->data)
            root = rotateLeft(root);
        else
            root = rotateRightLeft(root);
    }

    return root;
}

avlNodePtr AvlTree::remove(int data)
{
    cout<<"Removing "<<data<<endl;
    this->root = remove(data, this->root);
    return this->root;
}

int AvlTree::findMin(avlNodePtr root)
{
    avlNodePtr ret = findMinPtr(root);
    if(ret == nullptr)
    {
        cout<<"Minimum : -1"<<endl;
        return -1;
    }

    cout<<"Minimum : "<<ret->data<<endl;
    return ret->data;
}

int AvlTree::findMin()
{
    return findMin(this->root);
}

avlNodePtr AvlTree::findMinPtr(avlNodePtr root)
{
    avlNodePtr ptr = root;
    while(ptr && ptr->left)
        ptr = ptr->left;
    return ptr;
}

void AvlTree::inorder(avlNodePtr root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void AvlTree::inorder()
{
    inorder(this->root);
}

void AvlTree::print()
{
    inorder();
    cout<<endl;
}