#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    Stack<int> stack(10);
    int option;
    int position, value;

    do
    {
        cout << "\nWhat operation do you want to perform? Select option number. Enter 0 to exit." << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Is Empty?" << endl;
        cout << "4. Is Full?" << endl;
        cout << "5. Peek" << endl;
        cout << "6. Count" << endl;
        cout << "7. Change" << endl;
        cout << "8. Top" << endl;
        cout << "9. Display" << endl;
        cout << "10. Clear Screen" << endl;

        cin >> option;

        switch(option)
        {
            case 0:
                break;

            case 1:
                cout << "Enter an item to push in the stack" << endl;
                cin >> value;
                stack.push(value);
                break;
            
            case 2:
                cout << "Poped Value: " << stack.pop() << endl;
                break;
            
            case 3:
                if(stack.isEmpty())
                    cout << "Stack is Empty" << endl;
                else
                    cout << "Stack is not Empty" << endl;
                break;
            
            case 4:
                if(stack.isFull())
                    cout << "Stack is Full" << endl;
                else
                    cout << "Stack is not Full" << endl;
                break;
            
            case 5:
                cout << "Enter position of item you want to peek: " << endl;
                cin >> position;
                cout << "Value at position " << position << " is " << stack.peek(position) << endl;
                break;

            case 6:
                cout << "Number of items in the stack are " << stack.count() << endl;
                break;

            case 7:
                cout << "Enter position of item you want to change: ";
                cin >> position;
                
                cout << "\nEnter item you want to change: ";
                cin >> value;

                stack.change(position, value);
                break;

            case 8:
                cout << "Top item is: " << stack.topElement() << endl;
                break;

            case 9:
                stack.display();
                break;

            case 10:
                system("cls");
                break;
            
            default:
                cout << "Enter proper option number" << endl;

        }
    } while(option != 0);

    return 0;
}
