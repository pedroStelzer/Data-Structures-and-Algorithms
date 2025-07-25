#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* right;
    Node* left;

    Node(int value) : data(value), right(nullptr), left(nullptr) {};
};

class AvlTree
{
    private:

        Node* root;

        Node* insert_helper(Node* root, Node* node)
        {
            if(root == nullptr)
            {
                root = node;
                return root;
            }
            else if(node->data < root->data)
                root->left = insert_helper(root->left, node);
            else
                root->right = insert_helper(root->right, node);

            return root;
        };

        /*
        Node* search_helper(Node* current, int value)
        {
            if(current == nullptr) 
                return nullptr;

            if(current->data == value) 
                return current;

            Node* found = search_helper(current->left, value);

            if (found != nullptr) 
                return found;

            return search_helper(current->right, value);
        };*/

        int depth_helper(Node* root, Node* target, int currentDepth = 0)
        {
            if(root == nullptr) 
                return -1;

            if(root == target) 
                return currentDepth;

            int left = depth_helper(root->left, target, currentDepth+1);

            if(left != -1) 
                return left;

            int right = depth_helper(root->right, target, currentDepth+1);

            return right;
        };

        int height_helper(Node* target)
        {
            if(target == nullptr) return -1;

            int leftHeight = height_helper(target->left);
            int rightHeight = height_helper(target->right);

            if(leftHeight >= rightHeight)
                return 1+leftHeight;
            else
                return 1+rightHeight;
        };

        void preorder(Node* node)
        {
            if(node == nullptr) return;

            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        };

        void inorder(Node* node)
        {
            if(node == nullptr) return;

            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        };
        
        void postorder(Node* node)
        {
            if(node == nullptr) return;

            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        };

    public:

        AvlTree() {this->root = nullptr;};

        void insert(Node *node) {root = insert_helper(this->root, node);};

        void print_tree()
        {
            int n;

            cout << "Choose which traversal order to display the tree: " << endl << endl;
            cout << "(1) Pre-order" << endl;
            cout << "(2) In-order" << endl;
            cout << "(3) Post-order" << endl << endl;

            cin >> n;

            switch(n)
            {
                case 1:
                    preorder(this->root);
                    break;
                
                case 2:
                    inorder(this->root);
                    break;
                
                case 3:
                    postorder(this->root);
                    break;
                
                default:
                    break;
            }
        };

        /*void search(int value)
        {
            if(search_helper(this->root, value) != nullptr)
                cout << "Element " << value << " is in the tree." << endl; 
            else
                cout << "Element " << value << " is not in the tree." << endl;
        };

        int height(int value)
        {
            Node* target = search_helper(this->root, value);

            if(target != nullptr)
                return height_helper(target);
            else
                return -1;
        };

        int depth(int value)
        {
            Node* target = search_helper(this->root, value);

            if(target != nullptr) 
                return depth_helper(this->root, target);
            else 
                return -1;
        };*/
};

#endif //AVLTREE_H