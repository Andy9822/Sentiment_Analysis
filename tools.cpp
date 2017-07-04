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

void nPositives(int n, HashTable * tabela)
{
    vector<Word*> nPos = tabela->getRealItems();
    vector<Word*> nPosReturn;
    for(int j = 0; j < nPos.size(); j ++)
    {
        if (nPos[j] != NULL && nPosReturn.size() < n) {
            nPosReturn.push_back(nPos[j]);
        }
        else {
            for (int i = 0; i < nPosReturn.size(); i ++)
            {
                if (nPos[j] != NULL)
                {
                    if (nPosReturn[i]->getValor() < nPos[j]->getValor() && !alreadyInside(nPosReturn, *nPos[j]))
                    {
                        nPosReturn.erase (nPosReturn.begin()+i);
                        nPosReturn.push_back(nPos[j]);
                    }
                }
            }
        }
    }
    for(int k = 0; k < nPosReturn.size(); k++)
    {
        cout << nPosReturn[k]->getValor() << "  " << nPosReturn[k]->getString() << endl;
    }
}

bool alreadyInside(vector<Word*> wordArray, Word word)
{
    for (int i = 0; i < wordArray.size(); i++)
    {
        if(wordArray[i]->getValor() == word.getValor() && wordArray[i]->getString() == word.getString())
            return true;
    }
    return false;
}
