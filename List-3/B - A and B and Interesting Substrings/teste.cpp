#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() 
{
    /*
        Tentei bastante implementar a tabela hash, mas não consegui.
        Tive muita dificuldade em implementar um dicionario aninhado, achei complexo.
        Mas vou estudar posteriormente para entender melhor.
        A solução abaixo foi o melhor que consegui fazer.
    */

    // Dicionario aninhado que armazena o caracter como chave e no valor armazena outro dicionario com os valores das pre somas e a sua contagem
    unordered_map<char, unordered_map<long long, int>> table(26);

    // Array para armazenar os valores associados a cada letra do alfabeto
    int alphabet_values[26];

    // Variável para armazenar o resultado final
    long long result = 0;

    // Le os valores associados das letras do alfabeto
    for (int i = 0; i < 26; ++i) 
    {
        int num;
        cin >> num; 
        alphabet_values[i] = num;
    }

    string s;
    cin >> s;

    int len_string = s.size();

    // Armazena os valores acumulados das letras da string
    long long pre_sum[len_string];
    pre_sum[0] = 0; // Inicializa o primeiro valor como 0.

    // Calcula as pre somas acumuladas para cada posicao da string.
    for (int i = 0; i < len_string; ++i) 
    {
        // Soma acumulada: valor atual é a soma do anterior mais o valor da letra atual
        pre_sum[i + 1] = pre_sum[i] + alphabet_values[s[i] - 'a'];
    }

    // Itera sobre cada caractere da string
    for (int i = 0; i < len_string; ++i) {
        
        // Obtem o pre soma ate a posição atual.
        long long num = pre_sum[i];

        // Verifica se a pre soma atual ja existe na tabela hash para o caractere atual
        bool found = table[s[i]].count(num);

        // Se a pre soma foi encontrado, adiciona o valor correspondente ao resultado
        if(found) 
        {
            result += table[s[i]][num];
        }

        // Incrementa o contador para a proxima pre soma na tabela hash
        table[s[i]][pre_sum[i + 1]]++;
    }

    cout << result << endl;
    return 0;
}