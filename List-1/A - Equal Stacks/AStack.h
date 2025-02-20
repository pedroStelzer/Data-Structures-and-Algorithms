#ifndef ASTACK_H
#define ASTACK_H
#define DEFAULT_SIZE 100
#include "Stack.h"

template <typename E> class AStack: public Stack<E> 
{
    private:

        int maxSize;
        int top;
        E *listArray;

    public:

        AStack(int size = DEFAULT_SIZE) 
        {
            maxSize = size;
            top = 0;
            listArray = new E[size];
        }

        ~AStack() 
        {
            delete [] listArray;
        }

        int getElement(int index) const
        {
            return listArray[index];
        }

        int sum() const
        {
            int sum = 0;
            for(int i = 0; i < maxSize; i++)
            {
                sum += listArray[i];
            }
            return sum;
        }

        void clear() 
        {
            top = 0;
        }

        void push(const E &it) 
        {
            listArray[top++] = it;
        }

        E pop() 
        {
            return listArray[--top];
        }

        const E &topValue() const 
        {
            return listArray[top - 1];
        }

        int length() const 
        {
            return top;
        }
};

#endif // ASTACK_H