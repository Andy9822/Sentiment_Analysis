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
