#include <iostream>
using namespace std;

// No da arvore AVL
struct Node
{
    int data;
    Node* right;
    Node* left;

    Node(int value) : data(value), right(nullptr), left(nullptr) {};
};

// Classe da arvore AVL
class AvlTree
{
    private:

        Node* root;

        // Metodo de insercao com balanceamento
        Node* insertHelper(Node* root, Node* node)
        {   
            /* Insercao normal de uma BST */
            if(root == nullptr)
            {
                root = node;
                return root;
            }
            else if(node->data < root->data)
                root->left = insertHelper(root->left, node);
            else if(node->data > root->data)
                root->right = insertHelper(root->right, node);
            /* -------------------------- */

            // Calculo do fator de balanceamento
            // altura(esquerda) - altura(direita)
            int bf = getBalanceFactor(root);

            // Rotacao simples a direita
            if(bf > 1 && node->data < root->left->data)
            {
                cout << root->data << endl;
                return rightRotate(root);
            }
            
            // Rotacao simples a esquerda
            if(bf < -1 && node->data > root->right->data)
            {
                cout << root->data << endl;
                return leftRotate(root);
            }
            
            // Rotacao dupla esquerda/direita
            if(bf > 1 && node->data > root->left->data)
            {
                cout << root->data << endl;
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
            
            // Rotacao dupla direita/esquerda
            if(bf < -1 && node->data < root->right->data)
            {
                cout << root->data << endl;
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
            
            return root;
        };

        // Retorna a diferenca entre a altura esquerda e altura direita
        int getBalanceFactor(Node* node)
        {
            if(node == nullptr)
                return -1;
            else
                return (heightHelper(node->left) - heightHelper(node->right));
        };

        // Rotacao simples a esquerda
        Node* leftRotate(Node* root)
        {
            Node* newRoot = root->right;
            Node* nodeAux = newRoot->left;

            newRoot->left = root;
            root->right = nodeAux;

            return newRoot;
        };

        // Rotacao simples a direita
        Node* rightRotate(Node* root)
        {
            Node* newRoot = root->left;
            Node* nodeAux = newRoot->right;

            newRoot->right = root;
            root->left = nodeAux;

            return newRoot; 
        };

        Node* deleteNodeHelper(Node* root, int value)
        {
            if(root == nullptr)
                return root;
            else if(value < root->data)
                root->left = deleteNodeHelper(root->left, value);
            else if(value > root->data)
                root->right = deleteNodeHelper(root->right, value);
            else
            {
                // No com apenas um ou nenhum filho
                if(root->left == nullptr)
                {
                    Node* temp = root->right;
                    delete root;
                    return temp;
                }
                else if(root->right == nullptr)
                {
                    Node* temp = root->left;
                    delete root;
                    return temp;
                }
                else // No com dois filhos
                {
                    Node* temp = minValueNode(root->right);
                    root->data = temp->data;
                    root->right = deleteNodeHelper(root->right, temp->data);
                }
            }

            // Calculo do fator de balancemaento depois da remocao
            int bf = getBalanceFactor(root);

            // Rebalanceamentos
            if(bf == 2 && getBalanceFactor(root->left) >= 0)
            {
                cout << root->data << endl;
                return rightRotate(root);
            }
            else if(bf == 2 && getBalanceFactor(root->left) == -1)
            {
                cout << root->data << endl;
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
            else if(bf == -2 && getBalanceFactor(root->right) <= 0)
            {
                cout << root->data << endl;
                return leftRotate(root);
            }
            else if(bf == -2 && getBalanceFactor(root->right) == 1)
            {
                cout << root->data << endl;
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }

            return root;
        }

        // Retorna o no com menor valor
        Node* minValueNode(Node* node)
        {
            Node* current = node;

            while(current->left != nullptr)
                current = current->left;
            
            return current;
        }

        // Calculo da altura do no
        int heightHelper(Node* target)
        {
            if(target == nullptr) 
                return -1;
            else
            {
                int leftHeight = heightHelper(target->left);
                int rightHeight = heightHelper(target->right);

                if(leftHeight >= rightHeight)
                    return 1+leftHeight;
                else
                    return 1+rightHeight;
            }
        };

        /* Travessias da arvore */
        void preorder(Node* node)
        {
            if(node == nullptr) 
                return;

            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        };

        void inorder(Node* node)
        {
            if(node == nullptr) 
                return;

            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        };
        
        void postorder(Node* node)
        {
            if(node == nullptr) 
                return;

            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        };
        /* -------------------- */

    public:

        // Construtor
        AvlTree() 
        {
            this->root = nullptr;
        };

        // Destrutor
        ~AvlTree()
        {
            destroyTree(this->root);
        }

        // Libera os nos da arvore
        void destroyTree(Node* node)
        {
            if(node != nullptr)
            {
                destroyTree(node->left);
                destroyTree(node->right);
                delete node;
            }
        }

        // Insere um novo no na arvore
        void insert(Node *node) 
        {
            if(search(node->data) == nullptr)
                root = insertHelper(this->root, node);
        };

        // Deleta um no com o valor dado
        void deleteNode(int value)
        {
            root = deleteNodeHelper(this->root, value);
        };

        // Imprime as travessias da arvore
        void printTree()
        {
            preorder(this->root);
            cout << endl;
            inorder(this->root);
            cout << endl;
            postorder(this->root);
            cout << endl;
        };

        // Busca um valor na arvore
        Node* search(int value)
        {
            if(root == nullptr)
                return root;
            else
            {
                Node* temp = root;

                while(temp != nullptr)
                {
                    if(value == temp->data)
                        return temp;
                    else if(value < temp->data)
                        temp = temp->left;
                    else
                        temp = temp->right;
                }

                return nullptr;
            }
        }
        
        // Retorna a altura de um no com o valor dado
        int height(int value)
        {
            Node* target = search(value);

            if(target != nullptr)
                return heightHelper(target);
            else
                return -1;
        };
};

int main()
{
    AvlTree *tree = new AvlTree();

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        char command;
        cin >> command;

        int num;
        cin >> num;

        if(command == 'i')
            tree->insert(new Node(num));
        else if(command == 'd')
            tree->deleteNode(num);
    }

    tree->printTree();

    return 0;
}