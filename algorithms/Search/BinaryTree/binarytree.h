#ifndef BINARYTREE_H
#define BINARYTREE_H

using namespace std;

template <typename E> struct Node
{
    E data;
    Node right;
    Node left;

    Node(E value) : data(value), right(nullptr), left(nullptr) {};
};

template <typename E> class BinaryTree
{
    private:

        Node<E>* root;

    public:

        BinaryTree(Node<E>* root) : root(nullptr) {this->root = root};
};

#endif //BINARYTREE_H