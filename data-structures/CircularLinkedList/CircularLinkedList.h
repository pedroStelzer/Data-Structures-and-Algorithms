#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H
#include "../Node/Node.h"
#include "iostream"
using namespace std;

class CLinkedList
{
    public:

        Node *head;

        CLinkedList(Node* h = nullptr)
        : head(h) {};

        // 1. Check if node exists using key value
        Node* nodeExist(int k)
        {
            Node* temp = nullptr;
            Node* ptr = head;

            if(ptr == nullptr)
            {
                return temp;
            }
            else
            {
                do
                {
                    if(ptr->key == k)
                    {
                        temp = ptr;
                    }

                    ptr = ptr->next;

                } while(ptr != head);

                return temp;   
            }
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
                    n->next = head;
                    cout << "Node appended" << endl;
                }
                else
                {
                    Node* ptr = head;
                    while(ptr->next != head)
                    {
                        ptr = ptr->next;
                    }

                    ptr->next = n;
                    n->next = head;
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
                    n->next = head;
                    cout << "Node prepended" << endl;
                }
                else
                {
                    Node* ptr = head;

                    while(ptr->next != head)
                    {
                        ptr = ptr->next;
                    }

                    ptr->next = n;

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
                if(nodeExist(n->key) != nullptr)
                {
                    cout << "Node already exists" << endl;
                }
                else
                {
                    if(ptr->next == head)
                    {
                        n->next = head;
                        ptr->next = n;
                        cout << "Node inserted" << endl;
                    }
                    else
                    {
                        n->next = ptr->next;
                        ptr->next = n;
                        cout << "Node inserted" << endl;
                    }
                    
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

                if(ptr == head)
                {
                    if(head->next == nullptr)
                    {
                        head = nullptr;
                        cout << "Head node unlinked... List empty" << endl;
                    }
                    else
                    {
                        Node* ptr1 = head;

                        while(ptr1->next != head)
                        {
                            ptr1 = ptr1->next;
                        }

                        ptr1->next = head->next;
                        head = head->next;
                        cout << "Node unlinked" << endl;
                    }
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

                    prev->next = temp->next;
                    cout << "Node unlinked" << endl;
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
                cout << "Circular Linked List is empty";
            }
            else
            {
                cout << "\nhead address: " << head << endl;
                cout << "Circular Linked List values: ";
                Node* temp = head;

                do
                {
                    cout << "(" << temp->key << ", " << temp->data << ", " << temp->next << ") --> ";
                    temp = temp->next;
                } while(temp != head);
            }
        }
};

#endif //CIRCULARLINKEDLIST_H