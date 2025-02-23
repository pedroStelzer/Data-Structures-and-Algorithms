#include <iostream>
#include <vector>
#define DEFAULT_SIZE 100
using namespace std;

// Implementacao da fila
template <typename E> class Queue
{
    private:

        int timeQueue;
        E *queue;
        int maxSize;
        int front;
        int rear;

    public:

        // Construtor
        Queue(int size = DEFAULT_SIZE)
        {
            maxSize = size+1;
            queue = new E[maxSize];
            timeQueue = 1;
            front = 1;
            rear = 0;
        }

        // Destrutor. Libera a memoria alocada
        ~Queue()
        {
            delete [] queue;
        }
        
        // Limbpa a fila, resetando os indices
        void clear()
        {
            rear = 0;
            front = 1;
        }

        // Insere um elemento na fila
        void insert(const E &it)
        {
            rear = (rear+1) % maxSize; // Atualiza o indice do array circular
            queue[rear] = it;
        }

        // Remove um elemento da fila e retorna ele
        E remove()
        {
            E it = queue[front]; // Armazena o elemento
            front = (front+1) % maxSize; // Atualiza o indice do primeiro elemento
            return it;
        }

        // Retorna o valor do primeiro elemento
        const E &frontValue() const
        {
            return queue[front];
        }

        // Retorna o tamanho da fila
        int length() const
        {
            return ((rear+maxSize) - front + 1) % maxSize;
        }

        // Incrementa o tempo da fila
        void incrementTimeQueue()
        {
            timeQueue++;
        }

        // Retorna o tempo atual da fila
        int getTimeQueue()
        {
            return timeQueue;
        }

        // Atualiza o novo valor do tempo
        void setTimeQueue(int time)
        {
            timeQueue = time;
        }
};

// Classe Pessoa que representa uma pessoa na fila do cha
class Person
{
    private:

        int secComes; // Segundo que a pessoa chega na fila
        int secLeaves; // Segundo que a pessoa pode esperar no maximo ate sair da fila

    public:

        // Construtor
        Person(int p_secComes = 0, int p_secLeaves = 0)
        {
            secComes = p_secComes;
            secLeaves = p_secLeaves;
        }

        // Destrutor
        ~Person() {}

        // Retorna o segundo que a pessoa chega na fila
        int getSecComes()
        {
            return secComes;
        }
        
        // Retorna o segundo em que a pessoa pode esperar no maximo ate sair da fila
        int getSecLeaves()
        {
            return secLeaves;
        }
};

// Funcao que retorna um vetor com o exato segundo em que o estudante pegou o cha
vector<int> secondGetsTea(Queue<Person> &teaQueue);

int main()
{
    int numCases, numStudents, secComes, secLeaves;
    
    cin >> numCases;

    for(int i = 0; i < numCases; i++)
    {
        cin >> numStudents;

        Queue<Person> teaQueue(numStudents); // Cria a fila de estudantee
        vector<int> secGetsTea(numStudents); // Vetor que armazena os segundos em que os estudantes conseguiram o cha

        for(int j = 0; j < numStudents; j++)
        {
            cin >> secComes;
            cin >> secLeaves;

            Person person(secComes, secLeaves); // Cria um objeto de Person

            teaQueue.insert(person); // Insere um estudante na fila
        }

        secGetsTea = secondGetsTea(teaQueue); // Chama a funcao para retornar os segundos em que os estuandes conseguem o cha

        // Mostra na tela os segundos que os estudantes conseguiram o cha
        for(int i = 0; i < numStudents; i++)
        {
            if(i+1 < numStudents)
            {
                cout << secGetsTea[i] << " ";
            }
            else
            {
                cout << secGetsTea[i] << endl;
            }
        }
    }

    return 0;
};

// Funcao que retorna um vetor com o exato segundo em que o estudante pegou o cha
vector<int> secondGetsTea(Queue<Person> &teaQueue)
{
    vector<int> secGetsTea;
    Person person = teaQueue.frontValue();

    while(teaQueue.length() > 0)
    {   
        Person person = teaQueue.remove(); // Remove o estudante da fila
        
        if(teaQueue.getTimeQueue() <= person.getSecLeaves() && teaQueue.getTimeQueue() >= person.getSecComes()) // Verifica se o estudante esta no tempo permitido
        {
            secGetsTea.push_back(teaQueue.getTimeQueue()); // Registra o segundo em que o estudante pegou o cha
            teaQueue.incrementTimeQueue(); // Incrmenta o tempo da fila
        }
        else if(teaQueue.getTimeQueue() <= person.getSecLeaves() && teaQueue.getTimeQueue() < person.getSecComes()) // Se houver uma espera muito grande, o tempo da fila sera setado para o novo tempo de chegada do novo aluno da fila
        {   
            teaQueue.setTimeQueue(person.getSecComes()); // seta o novo tempo
            secGetsTea.push_back(teaQueue.getTimeQueue()); // Registra o segundo em que o estudante pegou o cha
            teaQueue.incrementTimeQueue(); // Incrementa o tempo da fila
        }
        else
        {
            secGetsTea.push_back(0); // Se o estudante saiu antes de ter sido atendido, registra o segundo 0 e nao incrementa o tempo da fila
        }
    }
    
    return secGetsTea;
}