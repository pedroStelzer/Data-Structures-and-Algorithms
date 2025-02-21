#include <iostream>
#include "LStack.h"

using namespace std;

string beijuText(string text);

int main()
{
    string input, result;

    while(cin >> input)
    {
        cout << beijuText(input) << endl;
    }

    return 0;
}

string beijuText(string text)
{
    char character;
    bool changeStack = false;
    LStack<char> textNormal;
    LStack<char> textBeiju;
    LStack<char> textAll;

    for(int i = 0; i < text.length(); i++)
    {
        character = text[i];
        
        if(character == '[')
        {
            changeStack = true;
        }
        else if(character == ']')
        {
            changeStack = false;
        }

        if(!changeStack && character != ']')
        {
            textNormal.push(character);
        }
        else if(changeStack && character != '[')
        {
            textBeiju.push(character);
        }
    }

    int lenStack = textNormal.length();
    for(int i = 0; i < lenStack; i++)
    {
        textAll.push(textNormal.topValue());
        textNormal.pop();
    }

    lenStack = textBeiju.length();
    for(int i = 0; i < lenStack; i++)
    {
        textAll.push(textBeiju.topValue());
        textBeiju.pop();
    }

    lenStack = textAll.length();
    string finalText = "";

    int i = 0;
    while(textAll.length() != 0)
    {
        finalText += textAll.topValue();
        textAll.pop();

        i++;
    }

    return finalText;
}