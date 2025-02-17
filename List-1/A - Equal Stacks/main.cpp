#include <iostream>
#include "AStack.h"
using namespace std;


int main()
{
    AStack<int> cylinderSyzes(3);
    int input;
    int maxHeigth = 0;

    for(int i = 0; i < 3; i++)
    {
        cin >> input;
        cylinderSyzes.push(input);
    }

    AStack<int> h1(cylinderSyzes.getElement(2));
    AStack<int> h2(cylinderSyzes.getElement(1));
    AStack<int> h3(cylinderSyzes.getElement(0));

    for(int j = 0; j < cylinderSyzes.getElement(2); j++)
    {
        cin >> input;
        h1.push(input);
    }

    for(int j = 0; j < cylinderSyzes.getElement(1); j++)
    {
        cin >> input;
        h2.push(input);
    }

    for(int j = 0; j < cylinderSyzes.getElement(0); j++)
    {
        cin >> input;
        h3.push(input);
    }

    bool halt = false;
    int sum1, sum2, sum3;
    while(not halt)
    {   
        sum1 = h1.sum();
        sum2 = h2.sum();
        sum3 = h3.sum();

        if(sum1 == 0 || sum2 == 0 || sum3 == 0 || (sum1 == sum2 && sum2 == sum3 && sum1 <= maxHeigth)) {halt = true;}
        else if(sum1 == sum2 && sum2 == sum3) {maxHeigth = sum1;}
        else
        {
            if(sum1 >= sum2 && sum1 >= sum3) {h1.pop();}
            else if(sum2 >= sum3) {h2.pop();}
            else {h3.pop();}
        }
    }

    cout << maxHeigth << endl;

    return 0;
}