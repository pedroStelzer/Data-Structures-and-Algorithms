#include <iostream>
#include "AStack.h"
#include <vector>

using namespace std;

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3);

int main()
{
    vector<int> h1, h2, h3;
    AStack<int> cylinderSyzes(3);
    int input;
    int maxHeigth = 0;

    for(int i = 0; i < 3; i++)
    {
        cin >> input;
        cylinderSyzes.push(input);
    }

    for(int i = 0; i < cylinderSyzes.getElement(0); i++)
    {
        cin >> input;
        h1.push_back(input);
    }

    cylinderSyzes.pop();

    for(int i = 0; i < cylinderSyzes.getElement(1); i++)
    {
        cin >> input;
        h2.push_back(input);
    }

    cylinderSyzes.pop();

    for(int i = 0; i < cylinderSyzes.getElement(2); i++)
    {
        cin >> input;
        h3.push_back(input);
    }

    cylinderSyzes.pop();

    maxHeigth = equalStacks(h1, h2, h3);

    cout << maxHeigth << endl;

    return 0;
}

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) 
{
    bool halt = false;
    int sum1, sum2, sum3;
    int maxHeigth = 0;

    AStack<int> stack1(h1.size());
    AStack<int> stack2(h2.size());
    AStack<int> stack3(h3.size());

    for(int i = 1; i < h1.size()+1; i++)
    {
        stack1.push(h1[h1.size()-i]);
    }

    for(int i = 1; i < h2.size()+1; i++)
    {
        stack2.push(h2[h2.size()-i]);
    }
    
    for(int i = 1; i < h3.size()+1; i++)
    {
        stack3.push(h3[h3.size()-i]);
    }
    
    sum1 = stack1.sum();
    sum2 = stack2.sum();
    sum3 = stack3.sum();
    
    while(!halt)
    {   
        if(sum1 == sum2 && sum2 == sum3 && sum1 <= maxHeigth) 
        {
            halt = true;
        }
        else if(sum1 == sum2 && sum2 == sum3) 
        {
            maxHeigth = sum1;
        }
        else
        {
            if(sum1 >= sum2 && sum1 >= sum3) 
            {
                sum1 -= stack1.pop();
            }
            else if(sum2 >= sum3) 
            {
                sum2 -= stack2.pop();
            }
            else 
            {
                sum3 -= stack3.pop();
            }
        }
    }

    return maxHeigth;
}