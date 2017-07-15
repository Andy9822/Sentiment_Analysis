#include "tools.h"
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
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
struct byFrequency {
    bool operator()(Word* const a, Word* const b) const {
        return a->getOcorrencias() > b->getOcorrencias();
    }
};

struct byPositives {
    bool operator()(Word* const a, Word* const b) const {
        return a->getValor() > b->getValor();
    }
};

struct byNegatives {
    bool operator()(Word* const a, Word* const b) const {
        return a->getValor() < b->getValor();
    }
};

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
    for(int j = 0; j < (int) nPos.size(); j ++)
    {
        if (nPos[j] != NULL && (int) nPosReturn.size() < n) {
            nPosReturn.push_back(nPos[j]);
        }
        else {
            for (int i = 0; i < (int) nPosReturn.size(); i ++)
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
    std::sort(nPosReturn.begin(), nPosReturn.end(), byPositives());
    for(int k = 0; k < (int) nPosReturn.size(); k++)
    {
        cout << nPosReturn[k]->getValor() << "  " << nPosReturn[k]->getString() << endl;
    }
}

void nNegatives(int n, HashTable * tabela)
{
    vector<Word*> nPos = tabela->getRealItems();
    vector<Word*> nPosReturn;
    for(int j = 0; j < (int) nPos.size(); j ++)
    {
        if (nPos[j] != NULL && (int) nPosReturn.size() < n) {
            nPosReturn.push_back(nPos[j]);
        }
        else {
            for (int i = 0; i < (int) nPosReturn.size(); i ++)
            {
                if (nPos[j] != NULL)
                {
                    if (nPosReturn[i]->getValor() > nPos[j]->getValor() && !alreadyInside(nPosReturn, *nPos[j]))
                    {
                        nPosReturn.erase (nPosReturn.begin()+i);
                        nPosReturn.push_back(nPos[j]);
                    }
                }
            }
        }
    }
    std::sort(nPosReturn.begin(), nPosReturn.end(), byNegatives());
    for(int k = 0; k < (int) nPosReturn.size(); k++)
    {
        cout << nPosReturn[k]->getValor() << "  " << nPosReturn[k]->getString() << endl;
    }
}

void nFrequency(int n, HashTable * tabela)
{
    vector<Word*> nPos = tabela->getRealItems();
    vector<Word*> nPosReturn;
    for(int j = 0; j < (int) nPos.size(); j ++)
    {
        if (nPos[j] != NULL && (int) nPosReturn.size() < n) {
            nPosReturn.push_back(nPos[j]);
        }
        else {
            for (int i = 0; i < (int) nPosReturn.size(); i ++)
            {
                if (nPos[j] != NULL)
                {
                    if (nPosReturn[i]->getOcorrencias() < nPos[j]->getOcorrencias() && !alreadyInside(nPosReturn, *nPos[j]))
                    {
                        nPosReturn.erase (nPosReturn.begin()+i);
                        nPosReturn.push_back(nPos[j]);
                    }
                }
            }
        }
    }
    std::sort(nPosReturn.begin(), nPosReturn.end(), byFrequency());
    for(int k = 0; k < (int) nPosReturn.size(); k++)
    {
        cout << nPosReturn[k]->getString() << " :: Ocorrencias:" << nPosReturn[k]->getOcorrencias() << endl ;
    }
}

void searchComments(string entrada, HashTable * tabela, int pontuacao, vector<string> fileContent)
{
    Word * palavra;
    palavra = tabela->getRealWord(entrada);
    vector<int> linhas = palavra->getLinhas();
    vector<string> lineWords;
    int valor;
    for(std::vector<int>::iterator it = linhas.begin(); it != linhas.end(); ++it)
    {
        if (pontuacao < 6 && pontuacao >= 0)
        {
            lineWords = splitStr(fileContent[*it]);
            istringstream  (lineWords[0]) >> valor;
            if ((valor == pontuacao))
                cout << fileContent[*it] << endl;
        }
        else
            cout << fileContent[*it] << endl;
    }
}

bool alreadyInside(vector<Word*> wordArray, Word word)
{
    for (int i = 0; i < (int) wordArray.size(); i++)
    {
        if(wordArray[i]->getValor() == word.getValor() && wordArray[i]->getString() == word.getString())
            return true;
    }
    return false;
}


