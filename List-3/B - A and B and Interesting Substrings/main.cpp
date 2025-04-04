#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    unordered_map<char, long long> alphabet;
    unordered_map<char, vector<vector<long long>>> preSums;
    vector<long long> index;
    vector<char> letras;
    string s;
    long long num = 0;

    for(long long i = 0; i < 26; i++)
    {   
        cin >> num;
        char letter = 'a' + i;
        alphabet[letter] += num; 
    }

    cin >> s;

    long long lenghtString = s.length();
    long long count = 0;
    long long sum = 0;

    for(long long i = 0; i < lenghtString; i++)
    {
        sum += alphabet[s[i]];
        vector<long long> temp;

        temp.push_back(i);
        temp.push_back(sum);

        preSums[s[i]].push_back(temp);

        index.push_back(sum);

        bool find = false;

        for(long long j = 0; j < letras.size() && !find; j++) if(s[i] == letras[j]) find = true;

        if(!find) letras.push_back(s[i]);
    }

    for(long long i = 0; i < preSums.size(); i++)
    {
        vector<vector<long long>> list = preSums[letras[i]];
        long long listSize = list.size();

        if(listSize > 1)
        {
            for(long long j = 0; j < listSize-1; j++)
            {
                for(long long k = j; k < listSize-1; k++)
                {
                    if(list[j][1] == index[list[k+1][0]-1])
                        count++;
                }
            }
        }
    }

    cout << count;

    return 0;
};