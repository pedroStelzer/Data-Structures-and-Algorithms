#include <iostream>
#include <vector>
#define DEFAULT_SIZE 100
using namespace std;

template <typename E> class Queue
{
    private:

        int timeQueue;
        E *queue;
        int maxSize;
        int front;
        int rear;

    public:


        Queue(int size = DEFAULT_SIZE)
        {
            maxSize = size;
            queue = new E[size];
            timeQueue = 1;
        }

        ~Queue()
        {
            delete [] queue;
        }

        void clear()
        {
            rear = 0;
            front = 1;
        }

        void insert(const E &it)
        {
            rear = (rear+1) % maxSize;
            queue[rear] = it;
        }

        E remove()
        {
            E it = queue[front];
            front = (front+1) % maxSize;
            return it;
        }

        const E &frontValue() const
        {
            return queue[front];
        }

        int length() const
        {
            return ((rear+maxSize) - front + 1) % maxSize;
        }

        void incrementTimeQueue()
        {
            timeQueue++;
        }

        int getTimeQueue()
        {
            return timeQueue;
        }
};

class Person
{
    private:

        int secComes;
        int secLeaves;

    public:

        Person(int p_secComes = 0, int p_secLeaves = 0)
        {
            secComes = p_secComes;
            secLeaves = p_secLeaves;
        }

        ~Person() {}

        int getSecComes()
        {
            return secComes;
        }

        int getSecLeaves()
        {
            return secLeaves;
        }

};

vector<int> secondGetsTea(Queue<Person> teaQueue);

int main()
{
    int numCases;
    int numStudents;
    int secComes;
    int secLeaves;
    

    cin >> numCases;

    for(int i = 0; i < numCases; i++)
    {
        cin >> numStudents;

        Queue<Person> teaQueue(numStudents);
        vector<int> secGetsTea(numStudents);

        for(int j = 0; j < numStudents; j++)
        {
            cin >> secComes;
            cin >> secLeaves;

            Person *persons = new Person[secComes, secLeaves];

            teaQueue.insert(persons[j]);
            
        }

        secGetsTea = secondGetsTea(teaQueue);

        for(int j = 0; j < numStudents; j++)
        {
            cout << secGetsTea[j] << endl;
        }

        /*if(j+1 < numStudents)
        {
            cout << secGetsTea << " ";
        }
        else
        {
            cout << secGetsTea << endl;
        }*/
    }

    return 0;
};

vector<int> secondGetsTea(Queue<Person> teaQueue)
{
    vector<int> secGetsTea;

    for(int i = 0; i < teaQueue.length(); i++)
    {
        Person person = teaQueue.remove();
        
        if(teaQueue.getTimeQueue() <= person.getSecLeaves())
        {
            secGetsTea.push_back(teaQueue.getTimeQueue());
            teaQueue.incrementTimeQueue();
        }
        
    }
    

    return secGetsTea;
}