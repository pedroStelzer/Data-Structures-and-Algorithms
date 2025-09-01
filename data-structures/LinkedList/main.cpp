#include <iostream>
#include "SinglyLinkedList.h"

using namespace std;

int main()
{
    SLinkedList s;
    int option;
    int key1, k1, data1;

    do
    {
        cout << "\nWhat operation do you want to perform? Select option number. Enter 0 to exit." << endl;
        cout << "1. Append Node" << endl;
        cout << "2. Prepend Node" << endl;
        cout << "3. Insert Node" << endl;
        cout << "4. Delete Node" << endl;
        cout << "5. Update Node" << endl;
        cout << "6. Print" << endl;
        cout << "7. Clear Screen" << endl;

        cin >> option;

        Node* n1 = new Node();

        switch(option)
        {
            case 0:
                break;

            case 1:
                cout << "Append Node Operation" << endl;
                cout << "Enter key and data of the Node to be appended" << endl;

                cin >> key1;
                cin >> data1;

                n1->key = key1;
                n1->data = data1;

                s.appendNode(n1);
                break;
            
            case 2:
                cout << "Prepend Node Operation" << endl;
                cout << "Enter key and data of the Node to be prepended" << endl;

                cin >> key1;
                cin >> data1;

                n1->key = key1;
                n1->data = data1;

                s.prependNode(n1);
                break;
            
            case 3:
                cout << "Insert Node after operation" << endl;
                cout << "Enter key of existing Node after which you want to insert this new node: " << endl;

                cin >> k1;

                cout << "Enter key and data of the new node: " << endl;

                cin >> key1;
                cin >> data1;

                n1->key = key1;
                n1->data = data1;

                s.insertNode(k1, n1);
                break;
            
            case 4:
                cout << "Delete Node operation" << endl;
                cout << "Enter key of the Node to be deleted: " << endl;

                cin >> k1;

                s.deleteNode(k1);
                break;
            
            case 5:
                cout << "Update Node operation" << endl;
                cout << "Enter key and new data to be updated: " << endl;

                cin >> key1;
                cin >> data1;

                s.updateNode(key1, data1);
                break;

            case 6:
                s.print();
                break;

            case 7:
                system("cls");
                break;
            
            default:
                cout << "Enter proper option number" << endl;

        }
    } while(option != 0);

    return 0;
}
