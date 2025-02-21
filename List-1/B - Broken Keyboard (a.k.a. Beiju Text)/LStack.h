#ifndef LSTACK_H
#define LSTACK_H
#define DEFAULT_SIZE 100
#include "Stack.h"
#include "Link.h"

template <typename E> class LStack: public Stack<E>
{
    private:

        Link<E> *top;
        int size;

    public:

        LStack(int sz = DEFAULT_SIZE) 
        {
            top = NULL;
            size = 0;
        }

        ~LStack() 
        {
            clear();
        }

        void push(const E &it)
        {
            top = new Link<E>(it, top);
            size++;
        };

        E pop()
        {
            E it = top->getElement();
            Link<E> *ltemp = top->getNext();
            delete top;
            top = ltemp;
            size--;
            return it;
        };

        const E &topValue() const
        {
            return top->getElement();
        };

        int length() const
        {
            return size;
        };

};

#endif // LSTACK_H