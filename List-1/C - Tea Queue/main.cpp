#include <iostream>

using namespace std;

int secondGetsTea(int secComes, int secLeaves);

int main()
{
    int numCases;
    int numStudents;
    int secComes;
    int secLeaves;
    int secGetsTea;

    cin >> numCases;

    for(int i = 0; i < numCases; i++)
    {
        cin >> numStudents;

        for(int j = 0; j < numStudents; j++)
        {
            cin >> secComes;
            cin >> secLeaves;

            secGetsTea = secondGetsTea(secComes, secLeaves);

            if(j+1 < numStudents)
            {
                cout << secGetsTea << " ";
            }
            else
            {
                cout << secGetsTea << endl;
            }
        }
    }

    return 0;
}

int secondGetsTea(int secComes, int secLeaves)
{
    int secGetsTea = 0;

    return secGetsTea;
}