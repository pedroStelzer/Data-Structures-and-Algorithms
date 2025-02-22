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
        Link<E> setNext(Link<E> nextval)
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
                text += this->topValue();
                this->pop();
            }
        }
};

string beijuText(string text);

int main()
{
    string input, result;

    // enquanto houver entrada de dados, o loop continua
    while(cin >> input)
    {
        cout << beijuText(input) << endl; // imprime o resultado da função beijuText
    }

    return 0;
}

string beijuText(string text)
{
    char character;
    bool changeStack = false;
    string finalText = "";
    LStack<char> textNormal;
    LStack<char> textBeiju;
    LStack<char> textAll;
    
    int lenText = text.length();

    // percorre a string de entrada
    for(int i = 0; i < lenText; i++)
    {
        character = text[i];
        
        if(character == '[') // se o caractere for '[', muda a pilha
        {
            changeStack = true;
        }
        else if(character == ']') // se o caractere for ']', volta a pilha ao normal
        {
            changeStack = false;
        }

        if(!changeStack && character != ']') // pilha nao mudou e caractere nao é ']', continua a empilhar na pilha normal
        {
            textNormal.push(character);
        }
        else if(changeStack && character != '[') // pilha mudou e caractere não é '[', empilha na pilha Beiju
        {
            textBeiju.push(character);
        }
    }

    textNormal.moveStack(textAll); // move todos os elementos da pilha normal para a pilha final
    textBeiju.moveStack(textAll); // move todos os elementos da pilha Beiju para a pilha final
    textAll.moveStackString(finalText); // move todos os elementos da pilha final para a string final

    return finalText;
}

/*

You’re typing a long text with a broken keyboard. Well it’s not so badly broken. The only problem
with the keyboard is that sometimes the “home” key or the “end” key gets automatically pressed
(internally).
You’re not aware of this issue, since you’re focusing on the text and did not even turn on the
monitor! After you finished typing, you can see a text on the screen (if you turn on the monitor).
In Chinese, we can call it Beiju. Your task is to find the Beiju text.
Input
There are several test cases. Each test case is a single line containing at least one and at most 100,000
letters, underscores and two special characters ‘[’ and ‘]’. ‘[’ means the “Home” key is pressed
internally, and ‘]’ means the “End” key is pressed internally. The input is terminated by end-of-file
(EOF).
Output
For each case, print the Beiju text on the screen.
Sample Input
This_is_a_[Beiju]_text
[[]][][]Happy_Birthday_to_Tsinghua_University
Sample Output
BeijuThis_is_a__text
Happy_Birthday_to_Tsinghua_University

*/