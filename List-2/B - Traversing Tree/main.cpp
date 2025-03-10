#include "BinarySearchTree.h"
#include "Node.h"
#include <iostream>

using namespace std;

int main()
{
    int numInputs;
    int input;
    BinarySearchTree *tree = new BinarySearchTree();

    cin >> numInputs;

    for(int i = 0; i < numInputs; i++)
    {
        cin >> input;
        tree->insert(new Node(input));
    }

    tree->print();

    delete tree;

    return 0;
}