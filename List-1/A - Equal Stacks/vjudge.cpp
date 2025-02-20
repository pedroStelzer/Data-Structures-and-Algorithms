#include <iostream>
#include <vector>
#define DEFAULT_SIZE 100
using namespace std;

template <typename E> class Stack
{
    private:

        void operator = (const Stack &) {}
        Stack(const Stack &) {}

    public:

        Stack() {}
        virtual ~Stack() {}
        virtual void clear() = 0;
        virtual void push(const E &it) = 0;
        virtual E pop() = 0;
        virtual const E &topValue() const = 0;
        virtual int length() const = 0;
};

// Implementacao da pilha com array e metodos extras
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

        // Metodo que retorna o elemento a partir de um indice
        int getElement(int index) const
        {
            return listArray[index];
        }

        // Metodo que retorna a soma dos elementos da pilha. OBS: A pilha deve ser de inteiros
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

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3);

int main()
{
    vector<int> h1, h2, h3;
    AStack<int> cylinderSyzes(3);
    int input, result;

    // Preenche as pilhas com os valores fornecidos pelo usuario
    for(int i = 0; i < 3; i++)
    {
        cin >> input;
        cylinderSyzes.push(input);
    }

    for(int i = 0; i < cylinderSyzes.getElement(0); i++)
    {
        cin >> input;
        h1.push_back(input);
    }

    cylinderSyzes.pop();

    for(int i = 0; i < cylinderSyzes.getElement(1); i++)
    {
        cin >> input;
        h2.push_back(input);
    }

    cylinderSyzes.pop();

    for(int i = 0; i < cylinderSyzes.getElement(2); i++)
    {
        cin >> input;
        h3.push_back(input);
    }

    cylinderSyzes.pop();

    // Chama a funcao que calcula a altura maxima que as pilhas podem ter
    result = equalStacks(h1, h2, h3);

    cout << result << endl;

    return 0;
}

// Funcao que retorna a altura maxima que as pilhas podem ter quando suas alturas sao iguais
int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) 
{
    bool halt = false;      // Variavel de controle
    int sum1, sum2, sum3;   // Variaveis que armazenam a soma dos elementos das pilhas
    int maxHeigth = 0;      // Variavel que armazena a altura maxima que as pilhas podem ter

    // Instancia as pilhas
    AStack<int> stack1(h1.size());
    AStack<int> stack2(h2.size());
    AStack<int> stack3(h3.size());

    // Preenche as pilhas
    for(int i = 1; i < h1.size()+1; i++)
    {
        stack1.push(h1[h1.size()-i]); // Inverte a ordem dos elementos
    }

    for(int i = 1; i < h2.size()+1; i++)
    {
        stack2.push(h2[h2.size()-i]);
    }
    
    for(int i = 1; i < h3.size()+1; i++)
    {
        stack3.push(h3[h3.size()-i]);
    }
    
    // Calcula a soma dos elementos das pilhas
    sum1 = stack1.sum();
    sum2 = stack2.sum();
    sum3 = stack3.sum();
    
    while(!halt)
    {   
        // Se as alturas das pilhas forem iguais e menores/iguais a altura maxima, quer dizer que a altura maxima foi encontrada
        if(sum1 == sum2 && sum2 == sum3 && sum1 <= maxHeigth) 
        {
            halt = true;
        }
        else if(sum1 == sum2 && sum2 == sum3) // Se a altura maxima ainda nao foi encontrada, atualiza a nova altura maxima
        {
            maxHeigth = sum1;
        }
        else // Se as alturas das pilhas forem diferentes, remove o elemento da pilha com a maior altura
        {   

            if(sum1 >= sum2 && sum1 >= sum3) 
            {
                sum1 -= stack1.pop(); // Ja subtrai o elemento removido da soma para nao precisar percorrer a pilha novamente
            }
            else if(sum2 >= sum3) 
            {
                sum2 -= stack2.pop();
            }
            else 
            {
                sum3 -= stack3.pop();
            }
        }
    }

    return maxHeigth;
}