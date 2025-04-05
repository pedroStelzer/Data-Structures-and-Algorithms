#include <iostream>
using namespace std;

// No da lista encadeada usado na implementacao da pilha
class Node
{
    public:

        int data;
        Node *next;

        Node(int value) : data(value), next(nullptr) {}
};

// Pilha implementada com lista encadeada
template <typename T> class Stack
{
    private:

        Node *topNode; // Ponteiro para o topo da pilha
        int size;

    public:

        Stack() : size(0), topNode(nullptr) {};
        ~Stack()
        {
            while(!this->empty())
            {
                this->pop();
            }
        };

        // Adiciona um elemento no topo da pilha
        void push(T value)
        {
            Node *newNode = new Node(value);
            newNode->next = topNode;
            topNode = newNode;
            size++;
        };

        // Remove o elemento do topo da pilha e retorna o valor
        T pop()
        {
            if(!this->empty())
            {
                Node *temp = topNode;
                topNode = topNode->next;
                T value = temp->data;
                delete temp;
                size--;
                return value;
            }
            return T(); // Retorna um valor padrão se a pilha estiver vazia
        };

        // Acrescenta 1 a todos os elementos da pilha
        void add()
        {
            Node *temp = topNode;

            while(temp != nullptr)
            {
                temp->data++;
                temp = temp->next;
            }
        };

        // Debug para verificar os elementos da pilha
        void debug()
        {
            Node *temp = topNode;

            cout << "\n\n Comecou debug \n\n";

            while(temp != nullptr)
            {
                cout << temp->data;
                temp = temp->next;
            }

            cout << "\n\n Terminou debug \n\n";
        }

        // Retorna o elemento do topo da pilha
        T top() 
        {
            if(!empty()) 
                return topNode->data;
        };

        // Retorna o proximo elemento da pilha
        T next()
        {
            if(!empty() && topNode->next != nullptr)
                return topNode->next->data;
        };

        // Verifica se a pilha esta vazia
        bool empty() 
        {
            return topNode == nullptr;
        };

        // Retorna o tamanho da pilha
        int lenght() 
        {
            return size;
        };
};


/*
    Minha ideia inicial era fazer o caminho inverso. Ja possuindo os valores da pilha,
    eu posso fazer o caminho inverso e dicidir qual comando executar ('d', '+', '1').
    
    Acredito que o problema esteja no comando '+' porque utilizando a abordagem reversa,
    nao tem como saber ao certo quais sao os dois valores 'a' e 'b' que preciso retirar de
    um valor 'x' do topo da pilha. Para, so entao adicionar os valores 'a' e 'b' na pilha.

    Ate o momento, o programa retira o valor do topo da pilha e decrementa em uma unidade.
    Mas isso nao eh uma garantia, pode ser que seja mais vantajoso dividir por dois ou
    separar por outros valores. Acho que a melhor abordagem era fazer o caminho normal mesmo.
*/

int main()
{
    Stack<int> nums;
    Stack<char> resultStack;
    string result = "";
    int numElements = 0;

    cin >> numElements;

    // Le os valores da pilha
    for(int i = 0; i < numElements; i++)
    {   
        int num;
        cin >> num;
        nums.push(num);
    }

    while(!nums.empty())
    {
        // O comando so vai ser 'd' se o topo e o tamnho da pilha for maior que 1 e o proximo elemento for igual ao topo.
        // Dessa forma, eh mais vantajoso utilizar o comando 'd'.
        if(nums.lenght() > 1 && (nums.top() == nums.next()))
        {
            nums.pop();
            resultStack.push('d');
        }
        else if(nums.top() > 1) // Se o elemento do topo for maior que 1, entao eh mais vantajoso usar o comando '+'
        {
            int temp = nums.pop()-1; // Remove o elemento do topo e diminui 1
            nums.add(); // Adiciona 1 a todos os elementos da pilha

            nums.push(temp); // Adiciona o elemento de volta na pilha
            nums.push(1); // Adiciona o 1 na pilha

            resultStack.push('+');
        }
        else if(nums.top() == 1) // Se o elemento do topo for igual a 1, adiciona '1' na pilha e remove o elemento do topo
        {
            nums.pop();
            resultStack.push('1');
        }
        else // Se sobrar algum 0, remove ele
        {
            nums.pop();
        }
    }

    // Adiciona os elementos da pilha no resultado final para formatacao
    while(!resultStack.empty()) result += resultStack.pop();

    cout << result;

    return 0;
}