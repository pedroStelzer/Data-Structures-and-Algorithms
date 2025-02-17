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
            top = size;
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
            for(int i = 0; i < maxSize-top; i++)
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
            //Assert(top != maxSize, "Stack is full");
            listArray[--top] = it;
        }

        E pop() 
        {
            //Assert(top != 0, "Stack is empty");
            return listArray[top++];
        }

        const E &topValue() const 
        {
            //Assert(top != 0, "Stack is empty");
            return listArray[top - 1];
        }

        int length() const 
        {
            return maxSize-top;
        }

        void Assert(bool condition, const char* message) const {
            if (!condition) {
                std::cerr << "Assertion failed: " << message << std::endl;
                std::exit(EXIT_FAILURE);
            }
        }
};

#endif // ASTACK_H