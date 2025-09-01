#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H
#include "Node/Node.h"
#include "iostream"
using namespace std;

class SLinkedList
{
    public:

        Node *head;

        SLinkedList(Node* h = nullptr)
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
                n->next = head;
                head = n;
                cout << "Node prepended" << endl;
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
                if(nodeExist(n->key) != nullptr)
                {
                    cout << "Node already exists" << endl;
                }
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    cout << "Node inserted" << endl;
                }
            }
        };

        // 5. Delete a node by unique key
        void deleteNode(int k)
        {
            if(head == nullptr)
            {
                cout << "Singly Linked List already empty" << endl;
            }
            else if(head != nullptr)
            {
                if(head->key == k)
                {
                    head = head->next;
                    cout << "Node unlinked" << endl;
                }
                else
                {
                    Node* temp = nullptr;
                    Node* prev = head;
                    Node* current = head->next;

                    while(current != nullptr)
                    {
                        if(current->key == k)
                        {
                            temp = current;
                            current = nullptr;
                        }
                        else
                        {
                            prev = prev->next;
                            current = current->next;
                        }
                    }

                    if(temp != nullptr)
                    {
                        prev->next = temp->next;
                        cout << "Node unlinked" << endl;
                    }
                    else
                    {
                        cout << "Node does not exist" << endl;
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
                cout << "Singly Linked List is empty";
            }
            else
            {
                cout << "\nSingly Linked List values: ";
                Node* temp = head;

                while(temp != nullptr)
                {
                    cout << "(" << temp->key << ", " << temp->data << ") --> ";
                    temp = temp->next;
                }
            }
        }
};

#endif //SINGLYLINKEDLIST_H
