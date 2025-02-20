#include <iostream>
#include "LStack.h"
using namespace std;

bool isBalanced(LStack<char> &stack);

int main()
{   

    int numberStrings;
    string s;

    cin >> numberStrings;

    for(int i = 0; i < numberStrings; i++)
    {
        LStack<char> stack;

        cin >> s;

        for(int i = 0; i < s.size()+1; i++)
        {   
            stack.push(s[s.size()-i]);
        }

        // Verifica se a pilha atual esta balanceada
        if(isBalanced(stack))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}

bool isBalanced(LStack<char> &stack)
{
    LStack<char> auxStack;
    char character, auxCharacter;
    int length = 6;

    for(int i = 0; i < length; i++)
    {   
        character = stack.topValue();

        if(character == '(' || character == '[' || character == '{')
        {
            auxStack.push(character);
        }
        else if(character == ')' && auxCharacter == '(')
        {
            auxStack.pop();
        }
        else if(character == ']' && auxCharacter == '[')
        {
            auxStack.pop();
        }
        else if(character == '}' && auxCharacter == '{')
        {
            auxStack.pop();
        }
        else
        {
            return false;
        }

        if(auxStack.length() == 0)
        {
            return true;
        }

        stack.pop();
        auxCharacter = auxStack.topValue();
    }

    return false;
}