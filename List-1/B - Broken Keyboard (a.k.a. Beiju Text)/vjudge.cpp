#include <iostream>
#define DEFAULT_SIZE 100

using namespace std;

// Implementacao do no da pilha com lista ligada
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

        // Metodo de acesso ao proximo no
        Link<E> *getNext()
        {
            return next;
        }

        // Metodo que seta o proximo no
        void setNext(Link<E> *nextval)
        {
            next = nextval;
        }
        
        // Metodo de acesso ao elemento do no
        const E &getElement() const
        {
            return element;
        }

        // Metodo que seta o elemento do no
        E setElement(E it)
        {
            element = it;
        }

};

// Implementacao da pilha com lista ligada
template <typename E> class LStack
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

        // Metodo que limpa a pilha
        void clear()
        {
            while(top != NULL)
            {
                Link<E> *temp = top;
                top = top->getNext();
                delete temp;
            }
            size = 0;   
        };

        // Metodo que insere um elemento na pilha
        void push(const E &it)
        {
            top = new Link<E>(it, top);
            size++;
        };

        // Metodo que remove um elemento da pilha
        E pop()
        {
            E it = top->getElement();
            Link<E> *ltemp = top->getNext();
            delete top;
            top = ltemp;
            size--;
            return it;
        };

        // Metodo que retorna o elemento do topo da pilha
        const E &topValue() const
        {
            return top->getElement();
        };

        // Metodo que retorna o tamanho da pilha
        int length() const
        {
            return size;
        };

        // Metodo que move todos os elementos da pilha para outra pilha
        void moveStack(LStack<E> &stack)
        {
            while(this->length() != 0)
            {
                stack.push(this->topValue());
                this->pop();
            }
        }

        // Metodo que move todos os elementos da pilha para uma string
        void moveStackString(string &text)
        {
            while(this->length() != 0)
            {   
                if(this->topValue() != "")
                {   
                    text += this->topValue();
                }
                this->pop();
            }
        }

        // Metodo que imprime todos os elementos da pilha
        void printStack()
        {
            Link<E> *a = top;
            while(a != NULL)
            {
                cout << a->getElement() << " ";
                a = a->getNext();
            }

            cout << "\n-----------------\n";
        }
};

template <typename E> class LQueue
{
    private:

        Link<E> *front;
        Link<E> *rear;
        int size;

    public:

        LQueue(int sz = DEFAULT_SIZE)
        {
            front = rear = new Link<E>();
            size = 0;
        }

        ~LQueue()
        {
            clear();
            delete front;
        }

        void clear()
        {
            while (front->getNext() != NULL)
            {
                Link<E> *temp = front->getNext();
                front->setNext(temp->getNext());
                delete temp;
            }
            rear = front;
            size = 0;

        }

        void insert(const E &it)
        {
            rear->setNext(new Link<E>(it, NULL));
            rear = rear->getNext();
            size++;
        }

        E remove()
        {
            E it = front->getNext()->getElement();
            Link<E> *ltemp = front->getNext();
            front->setNext(ltemp->getNext());
            delete ltemp;
            size--;
            return it;
        }

        const E &frontValue() const
        {
            return (front->getNext())->getElement();
        }

        int length() const
        {
            return size;
        }

        // Metodo que move todos os elementos da fila para outra pilha
        void moveQueue(LStack<E> &stack)
        {
            while(this->length() != 0)
            {
                stack.push(this->frontValue());
                this->remove();
            }
        }

        // Metodo que imprime todos os elementos da fila. somente pra debug
        void printQueue()
        {
            Link<E> *a = front->getNext();
            while(a != NULL)
            {
                cout << a->getElement() << " ";
                a = a->getNext();
            }

            cout << "\n-----------------\n";
        }

};

string beijuText(string text);

int main()
{
    string input, result;

    // enquanto houver entrada de dados, o loop continua
    while(getline(cin, input))
    {
        cout << beijuText(input) << endl; // imprime o resultado da função beijuText
    }

    return 0;
}

string beijuText(string text)
{
    char character;
    bool state = false; // tem 2 estados: empilha na pilha Normal e enfileira na fila Beiju
    string finalText = "";
    LStack<string> textNormal;
    LQueue<string> textBeiju;
    LStack<string> textAll;
    string strText;
    
    int lenText = text.length();

    // percorre a string de entrada
    for(int i = 0; i < lenText; i++)
    {
        character = text[i];
        
        if(!state && character == '[') // se nao houve mudanca de estado e o caractere for '[', muda o estado atual e empilha o texto
        {
            state = true; // muda de estado
            textNormal.push(strText); // empilha
            strText = "";
        }
        else if(state && character == ']') // se ja houve mudanca de estado e o caractere for ']', muda o estado atual e endileira o texto
        {
            state = false; // muda de estado
            textBeiju.insert(strText); // enfileira
            strText = "";
        }
        else if(state && character == '[') // se ja houve mudanca de estado e o caractere for '[', permanece no estado atual e enfileira o texto
        {
            textBeiju.insert(strText);
            strText = "";
        }

        if(!state && character != ']') // pilha nao mudou de estado e caractere nao é ']', continua a empilhar na pilha normal
        {
            strText += character;
        }
        else if(state && character != '[') // pilha mudou de estado e caractere não é '[', enfileira na fila Beiju
        {
            strText += character;
        }
    }

    // se houve mudanca de estado da pilha, insere o texto na fila Beiju
    if(state)
    {
        textBeiju.insert(strText);
    }
    else
    {
        textNormal.push(strText);
    }

    textNormal.moveStack(textAll); // move todos os elementos da pilha normal para a pilha final
    textBeiju.moveQueue(textAll); // move todos os elementos da fila Beiju para a pilha final
    textAll.moveStackString(finalText); // move todos os elementos da pilha final para a string final

    return finalText;
}