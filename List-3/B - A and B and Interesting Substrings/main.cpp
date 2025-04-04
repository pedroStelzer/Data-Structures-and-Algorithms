#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    unordered_map<char, long long> alphabet;
    unordered_map<char, unordered_map<long long, long long>> preSums;
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
    long long prev = 0;

    for(long long i = 0; i < lenghtString; i++)
    {
        sum += alphabet[s[i]];

        cout << "sum - alphabet[s[i]]: " << sum - alphabet[s[i]] << " prev:" << prev << endl;
        
        if(preSums.find(s[i]) != preSums.end() && preSums[s[i]].find(prev) != preSums[s[i]].end())
        {
            count += preSums[s[i]][prev];
            preSums[s[i]][sum]++;
        }
        else if(preSums[s[i]].find(sum) == preSums[s[i]].end())
        {
            preSums[s[i]][sum] = 1;
        }preSums[s[i]][sum] = 0;

        prev = sum;

        /*bool find = false;

        for(long long j = 0; j < letras.size() && !find; j++) if(s[i] == letras[j]) find = true;

        if(!find) letras.push_back(s[i]);*/
    }

    for(long long i = 0; i < preSums.size(); i++)
    {
        char letra = i+'a';
        long long len = preSums[letra].size();

        for(int j = 0; j < len; j++)
        {
            cout << letra << ": " << preSums[letra][j] << endl;
        }
    }

    cout << count;

    return 0;
};