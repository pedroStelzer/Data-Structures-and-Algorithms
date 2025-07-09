#include <iostream>
#include "BinaryTree/binarytree.h"

using namespace std;

int main()
{
    BinaryTree<int> tree;

    tree.insert(1);
    tree.insert(10);
    tree.insert(9);
    tree.insert(7);
    tree.insert(11);
    tree.insert(18);
    tree.insert(2);

    tree.search(10);
    tree.search(3);

    tree.print_tree();
    
    return 0;
}