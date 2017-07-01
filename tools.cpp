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

HashTable inputToHashTable(HashTable tabela) ///Lê linha por linha do .txt de input
{

    vector<string> lineWords;
    string line;
    ifstream myfile ("input.txt");

    if (! myfile.is_open())
    {
        cout << "Unable to open file";
        exit(EXIT_FAILURE);
    }

    while ( getline (myfile,line) )
    {
        lineWords = splitStr(line); /// Separa em um vector cada palavra da linha
        for(int i = 1; i < (int) lineWords.size(); i++)
        {
            tabela.insertWord(lineWords[i],(float) atof(lineWords[0].c_str())); /// Insere palavra por palavra do vector na Tabela Hash
        }
    }
    myfile.close();

    return tabela;
}
