#ifndef STACK_H
#define STACK_H
#define DEFAUL_CAPACITY 100

#include <iostream>
using namespace std;

template <typename E> class Stack
{
    private:

        int top;
        int capacity;
        E *arr;

    public:

        Stack(int c = DEFAUL_CAPACITY)
        {
            top = -1;
            capacity = c;
            arr = new E[capacity];
        }

        ~Stack()
        {
            delete [] arr;
        }

        bool isEmpty()
        {
            if(top == -1)
                return true;
            else
                return false;
        }

        bool isFull()
        {
            if(top == capacity-1)
                return true;
            else
                return false;
        }

        void push(E element)
        {
            if(isFull())
            {
                cout << "Stack Overflow" << endl;
            }
            else
            {
                top++;

                arr[top] = element;
            }
        }

        E pop()
        {
            if(isEmpty())
            {
                cout << "Stack Underflow" << endl;
            }
            else
            {
                int topValue = top;
                top--;
                return arr[topValue];
            }
        }

        int count()
        {
            return top+1;
        }

        E peek(int pos)
        {
            if(isEmpty())
                cout << "Stack Underflow" << endl;

            if(pos > capacity)
                cout << "Position not allowed. Maximum capacity is " << capacity << endl;
            else
                return arr[pos];
        }

        void change(int pos, E element)
        {
            arr[pos] = element;

            cout << "Element changed at location " << pos << " successfully" << endl;
        }

        E topElement()
        {
            if(isEmpty())
                cout << "Stack Underflow" << endl;
            else
                return arr[top];
        }

        void display()
        {
            cout << "Elements in the stack:" << endl << endl;

            for(int i = top+1; i > 0; i--)
            {
                cout << arr[i-1] << endl;
            }  
        }
};

#endif // STACK_H