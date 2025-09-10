#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H
#define DEFAULT_CAPACITY 100

#include <iostream>
using namespace std;

template <typename E> class CircularQueue
{
    private:

        E* arr;
        int front;
        int rear;
        int capacity;
        int itemCount;

    public:

        CircularQueue(int c = DEFAULT_CAPACITY)
        {
            front = -1;
            rear = -1;
            capacity = c;
            itemCount = 0;
            arr = new E(capacity);
        }

        ~CircularQueue()
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
            if((rear+1)%capacity == front)
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
                rear = (rear+1)%capacity;
            }
            
            arr[rear] = element;
            itemCount++;
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
                itemCount--;
                return element;
            }
            else
            {
                element = arr[front];
                front = (front+1)%capacity;
                itemCount--;
                return element;
            }
        }

        int count()
        {
            return itemCount;
        }

        void display()
        {
            cout << "All values in the Queue are: " << endl;

            for(int i = 0, j = front; i != count(); i++, j = (j+1)%capacity)
                cout << arr[j] << " ";

            cout << endl;
        }
};

#endif // CIRCULARQUEUE_H