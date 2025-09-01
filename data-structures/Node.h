#ifndef NODE_H
#define NODE_H

class Node
{
    public:

        int key;
        int data;
        Node* next;

        Node(int k = 0, int d = 0)
        : key(k), data(d), next(nullptr) {};
};

#endif //NODE_H
