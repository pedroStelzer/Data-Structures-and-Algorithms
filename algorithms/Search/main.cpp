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

    int element;

    cout << "Choose an element to find its depth and height: " << endl;
    cin >> element;

    int depth = tree.depth(element);

    if(depth >= 0) cout << "Element " << element << " depth: " << depth << endl;
    else cout << "Element " << element << " not found." << endl;
    
    int height = tree.height(element);

    if(height >= 0) cout << "Element " << element << " height: " << height << endl;
    else cout << "Element " << element << " not found." << endl;

    return 0;
}