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

};

#endif // LINK_H