#include <iostream>
#include <queue>
using namespace std;

// Classe No de cada elemento da arvore binaria
class Node
{
    private:

        int data; // Numero armazenado
        Node *left; // No esquerdo
        Node *right; // No direito
    
    public:

        // Construtor do No
        Node(int data)
        {
            this->data = data;
            left = nullptr;
            right = nullptr;
        }

        // Retorna o valor atual do No
        int getData()
        {
            return data;
        }

        // Retorna o proximo No da esquerda
        Node *getLeft()
        {
            return left;
        }

        // Retorna o proximo No da direita
        Node *getRight()
        {
            return right;
        }

        // Insere o valor do No da esquerda
        void setLeft(Node *left)
        {
            this->left = left;
        }
        
        // Insere o valor do No da direita
        void setRight(Node *right)
        {
            this->right = right;
        }
};

// Classe da Arvore de Busca Binaria
class BinarySearchTree
{
    private:

        Node *root = nullptr;
        queue<int> nums;

        // Metodo que retorna um ponteiro da posicao em que o No sera inserido por meio de sucessivas recursoes se precisar
        Node *insertHelper(Node *root, Node *node)
        {
            int data = node->getData(); // Armazena o valor do No que sera inserido

            // Se a raiz estiver vazia, define esta raiz com o No que sera inserido
            if(root == nullptr)
            {
                root = node;
                return root;
            }
            else if(data < root->getData()) // Se o valor do No que sera inserido for menor que o valor da raiz, o lado esquerdo da raiz recebe o No que sera inserido
            {
                root->setLeft(insertHelper(root->getLeft(), node));
            }
            else // Se o valor do No que sera inserido for maior que o valor da raiz, o lado direito da raiz recebe o No que sera inserido
            {   
                root->setRight(insertHelper(root->getRight(), node));
            }

            return root;
        }

        // Metodo que insere no vetor de numeros os valores em Pre Ordem
        void preOrder(Node *root)
        {
            if(root != nullptr)
            {   
                nums.push(root->getData());
                preOrder(root->getLeft());
                preOrder(root->getRight());
            }
        }

        // Metodo que insere no vetor de numeros os valores em Em Ordem
        void inOrder(Node *root)
        {
            if(root != nullptr)
            {
                inOrder(root->getLeft());
                nums.push(root->getData());
                inOrder(root->getRight());
            }
        }

        // Metodo que insere no vetor de numeros os valores em Pos Ordem
        void postOrder(Node *root)
        {
            if(root != nullptr)
            {
                postOrder(root->getLeft());
                postOrder(root->getRight());
                nums.push(root->getData());
            }
        }

        // Metodo que imprime a mensagem ja formatada
        void printOrder(string message)
        {
            cout << message;

            while(nums.size() > 1)
            {
                cout << nums.front() << " ";
                nums.pop(); 
            }
            
            cout << nums.front() << endl;
            nums.pop();
        }

    public:

        BinarySearchTree() {}
        ~BinarySearchTree() {}

        // Seta o ponteiro do No da raiz
        void insert(Node *node)
        {
            root = insertHelper(root, node);
        }

        // Chama os metodos que imprimem os valores da arvore de busca binaria em pre, em e pos ordem
        void print()
        {   
            preOrder(root);
            printOrder("Pre order : ");

            inOrder(root);
            printOrder("In order  : ");

            postOrder(root);
            printOrder("Post order: ");
        }
};

int main()
{
    int numInputs;
    int input;
    BinarySearchTree *tree = new BinarySearchTree();

    cin >> numInputs;

    // Insere os valores na arvore de busca binaria
    for(int i = 0; i < numInputs; i++)
    {
        cin >> input;
        tree->insert(new Node(input));
    }

    tree->print(); // Chama o metodo para imprimir os valores da arvore de busca binaria em pre, em e pos ordem

    delete tree;

    return 0;
}