#ifndef LINK_H
#define LINK_H

template <typename E> class Link
{
    private:

        E element;
        Link *next;

    public:

        Link(E it, Link<E> *nextval = NULL)
        {
            element = it;
            next = nextval;
        }

        Link(Link<E> *nextval = NULL)
        {
            next = nextval;
        }

        Link<E> *getNext()
        {
            return next;
        }

        Link<E> setNext(Link<E> nextval)
        {
            next = nextval;
        }

        const E &getElement() const
        {
            return element;
        }

        E setElement(E it)
        {
            element = it;
        }

        /*static Link<E> *freelist = NULL;

        static Link<E> get(E it, Link<E> nextval = NULL)
        {
            if(freelist == NULL)
            {
                return new Link(it, nextval);
            }
            else
            {
                Link<E> temp = freelist;
                freelist = freelist.getNext();
                temp.setELement(it);
                temp.setNext(nextval);
                return temp;
            }
        }*/

        /*void release()
        {
            next = freelist;
            freelist = this;
        }*/

};

#endif // LINK_H