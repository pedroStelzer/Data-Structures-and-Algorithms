#ifndef QUEUE_H
#define QUEUE_H
#define DEFAULT_CAPACITY 100

#include <iostream>
using namespace std;

template <typename E> class Queue
{
    private:

        E* arr;
        int front;
        int rear;
        int capacity;

    public:

        Queue(int c = DEFAULT_CAPACITY)
        {
            front = -1;
            rear = -1;
            capacity = c;
            arr = new E(capacity);
        }

        ~Queue()
        {
            delete [] arr;
        }

        bool isEmpty()
        {
            if(front == -1 && rear == -1)
                return true;
            else
                return false;
        }

        bool isFull()
        {
            if(rear == capacity-1)
                return true;
            else
                return false;
        }

        void enqueue(E element)
        {
            if(isFull())
            {
                cout << "Queue is Full" << endl;
                return;
            }
            else if(isEmpty())
            {
                rear = 0;
                front = 0;
            }
            else
            {
                rear++;
            }
            
            arr[rear] = element;
        }

        E dequeue()
        {
            E element;

            if(isEmpty())
            {
                cout << "Queue is Empty" << endl;
            }
            else if(front == rear)
            {
                element = arr[front];
                front = -1;
                rear = -1;
                return element;
            }
            else
            {
                element = arr[front];
                front++;
                return element;
            }
        }

        int count()
        {
            return rear-front+1;
        }

        void display()
        {
            cout << "All values in the Queue are: " << endl;

            for(int i = front; i < rear+1; i++)
            {
                cout << arr[i] << " ";
            }

            cout << endl;
        }
};

#endif // QUEUE_H