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
            maxSize = size+1;
            queue = new E[maxSize];
            timeQueue = 1;
            front = 1;
            rear = 0;
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

vector<int> secondGetsTea(Queue<Person> &teaQueue);

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

            Person person(secComes, secLeaves);

            teaQueue.insert(person);
            
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

vector<int> secondGetsTea(Queue<Person> &teaQueue)
{
    vector<int> secGetsTea;

    int lenQueue = teaQueue.length();

    //cout << "\n" << lenQueue << endl;

    while(teaQueue.length() > 0)
    {   
        //cout << "\n\n" << teaQueue.length() << "\n\n";
        Person person = teaQueue.remove();

        cout << "\n-----------Inicio Debug-----------\n";

        cout << "tempo queue: " << teaQueue.getTimeQueue() << "\n";
        cout << "tempo pessoa: " << person.getSecLeaves() << "\n";
        
        if(teaQueue.getTimeQueue() <= person.getSecLeaves())
        {
            secGetsTea.push_back(teaQueue.getTimeQueue());
            teaQueue.incrementTimeQueue();

            cout << "\noi\n";
        }
        else
        {   
            cout << "\nkkkkkkkk\n";
            secGetsTea.push_back(0);
        }
        
    }

    cout << "\n-----------Fim Debug-----------\n";
    

    return secGetsTea;
}