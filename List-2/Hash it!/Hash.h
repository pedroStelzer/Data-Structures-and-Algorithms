#ifndef HASHTABLE_H
#define HASHTABLE_H

using namespace std;

template <typename Type> class HashTable
{
    private:

        int size;
        int numElements;
        int key;
        Type value;
        Type *Array;

        int hash(int num)
        {

        };

        int hash(string element)
        {

        };

        int hashFind(Type element)
        {

        };

    public:

        HashTable(int h_size)
        {
            size = h_size;
            Array = new Type[size];

        };

        ~HashTable()
        {
            delete [] Array;
        };

        int getNumElements()
        {
            return numElements;
        }

        void clear()
        {

        };

        void insert(Type element)
        {

        };

        Type remove(Type element)
        {

        };

        Type find(Type element)
        {
            return hashFind(element);
        };

        int lenght()
        {
            return size;
        };

};

#endif // HASHTABLE_H