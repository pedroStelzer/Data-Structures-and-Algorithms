#include <iostream>
using namespace std;

class Node
{
    public:

        int data;
        Node *next;

        Node(int value) : data(value), next(nullptr) {}
};

template <typename T> class Stack
{
    private:

        Node *topNode;
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

        void push(T value)
        {
            Node *newNode = new Node(value);
            newNode->next = topNode;
            topNode = newNode;
            size++;
        };

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
        };

        void dec()
        {
            Node *temp = topNode;

            while(temp != nullptr)
            {
                temp->data--;
                temp = temp->next;
            }
        };

        void debug()
        {
            Node *temp = topNode;
            Stack<char> result;

            while(temp != nullptr)
            {
                result.push(temp->data + '0');
                temp = temp->next;
            }

            while(!result.empty())
                cout << result.pop() << " ";
        }

        T top() 
        {
            if(!empty()) 
                return topNode->data;
        };

        T next()
        {
            if(!empty() && topNode->next != nullptr)
                return topNode->next->data;
        };

        bool empty() 
        {
            return topNode == nullptr;
        };

        int lenght() 
        {
            return size;
        };
};

int main()
{
    Stack<int> nums;
    Stack<char> resultStack;
    string result = "";
    string code;

    cin >> code;

    for(int i = 0; i < code.length(); i++)
    {
        if(code[i] == '1')
        {
            nums.push(1);
        }
        else if(code[i] == 'd')
        {
            int temp = nums.top();
            nums.push(temp);
        }
        else if(code[i] == '+')
        {
            int temp1 = nums.pop();
            int temp2 = nums.pop();

            int sum = temp1 + temp2;

            nums.dec();
            nums.push(sum);
        }
    }

    nums.debug();

    return 0;
}