#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "iostream"
using namespace std;

class Node
{
    public:

        int key;
        int data;
        Node* next;
        Node* previous;

        Node(int k = 0, int d = 0)
        : key(k), data(d), next(nullptr), previous(nullptr) {};
};

class DLinkedList
{
    public:

        Node *head;

        DLinkedList(Node* h = nullptr)
        : head(h) {};

        // 1. Check if node exists using key value
        Node* nodeExist(int k)
        {
            Node* temp = nullptr;
            Node* ptr = head;

            while(ptr != nullptr)
            {
                if(ptr->key == k)
                {
                    temp = ptr;
                }
                ptr = ptr->next;
            }

            return temp;
        }

        // 2. Append a node to the list
        void appendNode(Node* n)
        {
            if(nodeExist(n->key) != nullptr)
            {
                cout << "Node already exists" << endl;
            }
            else
            {
                if(head == nullptr)
                {
                    head = n;
                    cout << "Node appended" << endl;
                }
                else
                {
                    Node* ptr = head;
                    while(ptr->next != nullptr)
                    {
                        ptr = ptr->next;
                    }

                    ptr->next = n;
                    n->previous = ptr;
                    cout << "Node appended" << endl;
                }
            }
        };

        // 3. Attach a node at the start
        void prependNode(Node* n)
        {
            if(nodeExist(n->key) != nullptr)
            {
                cout << "Node already exists" << endl;
            }
            else
            {
                if(head == nullptr)
                {
                    head = n;
                    cout << "Node prepended as head node" << endl;
                }
                else
                {
                    head->previous = n;
                    n->next = head;

                    head = n;
                    cout << "Node prepended" << endl;
                }
            }
        };

        // 4. Insert a note after a particular node in the list
        void insertNode(int k, Node* n)
        {
            Node* ptr = nodeExist(k);
            if(ptr == nullptr)
            {
                cout << "Node does not exists" << endl;
            }
            else
            {
                Node* nextNode = ptr->next;
                // inserting at the end
                if(nextNode == nullptr)
                {
                    ptr->next = n;
                    n->previous = ptr;
                    cout << "Node inserted at the end" << endl;
                }
                else // inserting in between
                {
                    n->next = nextNode;
                    nextNode->previous = n;
                    n->previous = ptr;
                    ptr->next = n;

                    cout << "Node inserted" << endl;
                }
            }
        };

        // 5. Delete a node by unique key
        void deleteNode(int k)
        {
            Node* ptr = nodeExist(k);

            if(ptr == nullptr)
            {
                cout << "Node does not exists" << endl;
            }
            else
            {
                if(head->key == k)
                {
                    head = head->next;
                    cout << "Node unlinked" << endl;
                }
                else
                {
                    Node* nextNode = ptr->next;
                    Node* previousNode = ptr->previous;

                    // deleting at the end

                    if(nextNode == nullptr)
                    {
                        previousNode->next = nullptr;
                        cout << "Node deleted at the end" << endl;
                    }
                    else // deleting in betwenn
                    {
                        previousNode->next = nextNode;
                        nextNode->previous = previousNode;
                        cout << "Node deleted" << endl;
                    }
                }
            }
        };

        // 6. Update a node
        void updateNode(int k, int d)
        {
            Node* ptr = nodeExist(k);

            if(ptr != nullptr)
            {
                ptr->data = d;
                cout << "Node data updated" << endl;
            }
            else
            {
                cout << "Node does not exist" << endl;
            }
        };

        // 7. Printing List
        void print()
        {
            if(head == nullptr)
            {
                cout << "Doubly Linked List is empty";
            }
            else
            {
                cout << "\nDoubly Linked List values: ";
                Node* temp = head;

                while(temp != nullptr)
                {
                    cout << "(" << temp->key << ", " << temp->data << ") <--> ";
                    temp = temp->next;
                }
            }
        }
};

#endif //DOUBLYLINKEDLIST_H