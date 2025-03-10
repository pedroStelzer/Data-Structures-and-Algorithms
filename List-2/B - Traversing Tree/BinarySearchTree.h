#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "Node.h"
#include <iostream>
#include <queue>
using namespace std;

class BinarySearchTree
{
    private:

        Node *root = nullptr;
        queue<int> nums;

        Node *insertHelper(Node *root, Node *node)
        {
            int data = node->getData();

            if(root == nullptr)
            {
                root = node;
                return root;
            }
            else if(data < root->getData())
            {
                root->setLeft(insertHelper(root->getLeft(), node));
            }
            else
            {   
                root->setRight(insertHelper(root->getRight(), node));
            }

            return root;
        }

        void preOrder(Node *root)
        {
            if(root != nullptr)
            {   
                nums.push(root->getData());
                preOrder(root->getLeft());
                preOrder(root->getRight());
            }
        }

        void inOrder(Node *root)
        {
            if(root != nullptr)
            {
                inOrder(root->getLeft());
                nums.push(root->getData());
                inOrder(root->getRight());
            }
        }

        void postOrder(Node *root)
        {
            if(root != nullptr)
            {
                postOrder(root->getLeft());
                postOrder(root->getRight());
                nums.push(root->getData());
            }
        }

        void printOrder(string message)
        {
            cout << message;

            while(nums.size() > 1)
            {
                cout << nums.front() << " ";
                nums.pop(); 
            }
            
            cout << nums.front() << endl;
            nums.pop();
        }

    public:

        BinarySearchTree() {}
        ~BinarySearchTree() {}

        void insert(Node *node)
        {
            root = insertHelper(root, node);
        }

        void print()
        {   
            preOrder(root);
            printOrder("Pre order : ");

            inOrder(root);
            printOrder("In order  : ");

            postOrder(root);
            printOrder("Post order: ");
        }
};

#endif // BINARYSEARCHTREE_H