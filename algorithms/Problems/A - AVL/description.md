## Write a program for AVL tree having functions for the following operations:

- Insert an element (no duplicates are allowed);
- Delete an existing element;
- Traverse the AVL (in-order, pre-order, and post-order)

## INPUT:

- Line 1 contains an integer NQ, the number of queries.
- The next NQ lines contain queries and are of the form ‘i x’ (Insert x into an AVL tree) or ‘d x’ (Delete x from an AVL tree).

## OUTPUT:

- For each query, print value of an unbalanced node (if any) at which rotation is being applied.
- The last three lines print ‘Preorder traversal’, ‘Inorder traversal’, and ‘Postorder traversal’ of an AVL tree that results after the execution of all NQ queries.

## SAMPLE INPUT:
8
i 1
i 2
i 3
i 4
i 5
i 6
d 4
d 5

## SAMPLE OUTPUT:
1
3
2
6
2 1 6 3 
1 2 3 6 
1 3 6 2