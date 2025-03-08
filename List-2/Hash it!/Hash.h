#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <iostream>

using namespace std;

template <typename Type> class HashTable
{
    private:

        int size;
        int numElements;
        Type *Array;

        int hash(string element)
        {
            int hashNumber = 0;

            for(int i = 0; i < element.size(); i++)
                hashNumber += element[i]*(i+1);

            hashNumber *= 19;

            return hashNumber;
        };

        int hashKey(string element, bool state)
        {
            int key =  hash(element) % size;

            if(state && Array[key] != element)
            {
                for(int i = 1; i < 20; i++)
                {
                    if(Array[key] == "") 
                        return key;
                    else
                        key = (key + i*i + 23*i) % size;
                }
            }
            else if(!state && Array[key] != "")
            {
                for(int i = 1; i < 20; i++)
                {
                    if(Array[key] == element)
                        return key;
                    else
                        key += (i*i + 23*i) % size;
                }
            }
            return -1;
        };

        int hashFind(Type element)
        {
            int key = hash(element);
        };

    public:

        HashTable(int h_size)
        {
            size = h_size;
            Array = new Type[size];
            numElements = 0;
        };

        ~HashTable()
        {
            delete [] Array;
        };

        int getNumElements()
        {
            return numElements;
        };

        Type value(int key)
        {
            return Array[key];
        };

        void insert(Type element)
        {
            int key = hashKey(element, true);

            if(key != -1)
            {
                Array[key] = element;
                numElements++;
            }
            
        };

        void remove(Type element)
        {
            int key = hashKey(element, false);

            if(key != -1)
            {
                Array[key] = "";
                --numElements;    
            }
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