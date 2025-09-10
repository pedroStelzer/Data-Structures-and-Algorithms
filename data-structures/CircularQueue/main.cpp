#include <iostream>
#include "CircularQueue.h"

using namespace std;

int main()
{
    CircularQueue<int> queue(5);
    int option;
    int position, value;

    do
    {
        cout << "\nWhat operation do you want to perform? Select option number. Enter 0 to exit." << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Is Empty?" << endl;
        cout << "4. Is Full?" << endl;
        cout << "5. Count" << endl;
        cout << "6. Display" << endl;
        cout << "7. Clear Screen" << endl;

        cin >> option;

        switch(option)
        {
            case 0:
                break;

            case 1:
                cout << "Enter an item to enqueue in the Queue" << endl;
                cin >> value;
                queue.enqueue(value);
                break;
            
            case 2:
                cout << "Dequeued Value: " << queue.dequeue() << endl;
                break;
            
            case 3:
                if(queue.isEmpty())
                    cout << "Queue is Empty" << endl;
                else
                    cout << "Queue is not Empty" << endl;
                break;
            
            case 4:
                if(queue.isFull())
                    cout << "Queue is Full" << endl;
                else
                    cout << "Queue is not Full" << endl;
                break;

            case 5:
                cout << "Number of items in the Queue are " << queue.count() << endl;
                break;

            case 6:
                queue.display();
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
