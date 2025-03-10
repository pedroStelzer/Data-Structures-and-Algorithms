#ifndef NODE_H
#define NODE_H

using namespace std;

class Node
{
    private:

        int data;
        Node *left;
        Node *right;
    
    public:

        Node(int data)
        {
            this->data = data;
            left = nullptr;
            right = nullptr;
        }

        int getData()
        {
            return data;
        }

        Node *getLeft()
        {
            return left;
        }

        Node *getRight()
        {
            return right;
        }

        void setLeft(Node *left)
        {
            this->left = left;
        }
        
        void setRight(Node *right)
        {
            this->right = right;
        }
};

#endif // NODE_H