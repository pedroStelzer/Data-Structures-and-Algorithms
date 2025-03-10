#include <iostream>
#include <string>
#define MAX_SIZE 101 // Tamanho maximo do array estabelecido pela questao
using namespace std;

// Classe da tabela Hash que suporta tipos genericos. Mas na pratica so pode ser usado para string ja que na questao so sera manipulado strings
template <typename Type> class HashTable
{
    private:

        int size;           // Tamanho da tabela Hash
        int numElements;    // Quantidade de elementos na tabela
        Type *Array;        // Array que representa a tabela

        // Funcao hash que converte uma string em um indice na tabela seguindo a formula: h(key) = 19*(ASCII(a1)*1+...+ASCII(an)*n)
        int hash(string element)
        {
            int hashNumber = 0;

            for(int i = 0; i < element.size(); i++)
                hashNumber += element[i]*(i+1);

            hashNumber *= 19;

            return hashNumber;
        };

        // Funcao que retorna a chave gerada ja resolvendo conflitos se tiver
        int hashKey(string element)
        {
            int key =  hash(element) % size;    // Gera uma chave inicial e aplica o modulo para caber no tamanho da tabela
            int newKey = key;

            for(int i = 1; i < 20; i++)     // Tenta inserir o elemento ate 20x, depois disso se considera que nao ha posicao vazia pro elemento
            {   
                if(Array[newKey] == "")     // Se a posicao estiver vazia, retorna a chave para o elemento ser inserido
                    return newKey;
                else
                    newKey = (key + i*i + 23*i) % size;    // Faz um novo hash
            }

            return -1;  // Retorna -1 se nao foi possivel gerar a chave
        };

    public:

        // Construtor
        HashTable(int h_size)
        {
            size = h_size;
            Array = new Type[size];
            numElements = 0;
        };

        // Destrutor
        ~HashTable()
        {
            delete [] Array;
        };

        // Limpa a tabela
        void clear()
        {
            for(int i = 0; i < size; i++)
            {
                Array[i] = "";
            }
            numElements = 0;
        };

        // Retorna o numero atual de elementos na tabela
        int getNumElements()
        {
            return numElements;
        };

        // Retorna o valor armazenado em dada chave fornecida
        Type value(int key)
        {
            return Array[key];
        };

        // Insere um elemento na tabela
        void insert(Type element)
        {
            int key = hashKey(element);

            if(key != -1)
            {
                Array[key] = element;   // Armazena o elemnento na determinada chave
                numElements++;
            }
        };

        // Remove o elemento da tabela
        void remove(int key)
        {
            Array[key] = "";    // Esvazia a posicao
            --numElements;
        };

        // Retorna o tamanho total da tabela
        int lenght()
        {
            return size;
        };

        int hashFind(Type element)
        {
            for(int i = 0; i < size; i++)
            {
                if(Array[i] == element)
                    return i;
            }

            return -1;
        }
};

int main()
{   
    int numCases;
    int numOperations;
    int lenTable;
    int numElements;
    int key;
    string opCode;
    string word = "";
    string operation = "";
    string value = "";
    HashTable<string> table(MAX_SIZE);

    cin >> numCases;

    // -------------------- Realiza as operacoes -------------------- //

    for(int i = 0; i < numCases; i++)
    {   
        cin >> numOperations;

        for(int j = 0; j < numOperations+1; j++)
        {
            getline(cin, operation);

            for(int k = 0; k < 3; k++)
                opCode += operation[k]; // opCode pode receber 'ADD' ou 'DEL'

            // Armazena a palavra em 'word'
            for(int k = 4; k < operation.size(); k++)
                word += operation[k];

            if(word != "")
            {   
                key = table.hashFind(word);
                
                if(opCode == "ADD" && key == -1)    // Se o codigo de operacao for 'ADD' e essa palavra nao for repetida tenta inserir a palavra na tabela
                    table.insert(word);
                else if(opCode == "DEL" && key != -1)    // Se o codigo de operacao for 'DEL' e encontrar a palavra remove a palavra na tabela
                    table.remove(key);
            }
            
            opCode = "";
            word = "";
        }

        numElements = table.getNumElements();

        // -------------------- Imprime na tela as chaves e seus valores da tabela -------------------- //

        cout << numElements << endl;

        for(int key = 0; key < MAX_SIZE; key++)
        {   
            value = table.value(key);   // Consulta o valor da tabela a partir da chave

            if(value != "")
                cout << key << ":" << value << endl;
        }

        table.clear(); // Limpa a tabela para outros casos testes
    }

    return 0;
};