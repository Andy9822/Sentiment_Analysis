#include "tools.h"

using namespace std;

vector<string> splitStr(string str) ///Dado um string de entrada, retorna um vector com todas as palavras da string (string.split() implementado na mão)
{

    istringstream iss(str);
    vector<string> palavras;
    while (iss)
    {
        string word;
        iss >> word;
        palavras.push_back(word);
    }

    return palavras;
}

float phraseNote(std::string phrase, HashTable * tabela)
{
    vector<string> linePhrase;
    linePhrase = splitStr(phrase);
    float totalValue = 0;
    for(int j = 0; j < (int) linePhrase.size()-1; j++)
    {
        totalValue += tabela->valueWord(linePhrase[j]);
    }
    return totalValue/(linePhrase.size()-1);
}
