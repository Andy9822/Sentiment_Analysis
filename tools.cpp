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

int classify(vector<string> words, HashTable * tabela, int flag)
{
    Word * tempWord;
    float total;
    if (!words.empty())
    {
        for(int i = 0; i < (int) words.size() -1; i++)
        {
            tempWord = tabela->getRealWord(words[i]);
            if (tempWord != NULL)
            {
                total += tempWord->getValor();
            }
            else
            {
                total += 2;
            }
        }
        total = total/(words.size()-1);
        if (flag)
        {
            std::cout << "O valor da frase e: " << total <<endl;
            if (total > 2)
                std::cout << "A frase e positiva" << endl;
            else if (total < 2)
                std::cout << "A frase e negativa" << endl;
            else
                std::cout << "A frase e neutra" << endl;
        }
    }
    else
    {
        if (flag)
        {
            std::cout << "Digite uma frase valida" << endl;
        }
    }

    return (int) total;
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
        if (pontuacao < 5 && pontuacao >= 0)
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

void showMenu(){

    cout << endl;
    cout << "========= MENU ==========" << endl;
    cout << "1 - Classificar novo comentario" << endl;
    cout << "2 - Mostrar os K mais positivos" << endl;
    cout << "3 - Mostrar os K mais negativos" << endl;
    cout << "4 - Mostrar os K mais frequentes" << endl;
    cout << "5 - Buscar comentarios associados a uma palavra" << endl;
    cout << "6 - Buscar palavras por radical" << endl;
    cout << "7 - Teste a partir de um arquivo" << endl;
    cout << "8 - Limpar a tela" << endl;
    cout << "0 - Sair" << endl;
    cout << "==========================" << endl;
    cout << endl << "Digite sua opcao: ";


}

vector<string> fillingFilter()
{
    vector<string> temp;
    temp.push_back(",");
    /*temp.push_back(".");
    temp.push_back("a");
    temp.push_back("o");
    temp.push_back("the");
    temp.push_back("an");
    temp.push_back("and");
    temp.push_back("of");
    temp.push_back("to");
    temp.push_back("'s");
    temp.push_back("is");
    temp.push_back("that");
    temp.push_back("in");
    temp.push_back("it");
    temp.push_back("an");
    temp.push_back("as");
    temp.push_back("this");
    temp.push_back("for");
    temp.push_back("but");
    temp.push_back("its");
    temp.push_back("n't");
    temp.push_back("on");
    temp.push_back("...");*/

    return temp;
}

bool alreadyInsideString (vector<string> lista, string palavra)
{
    for (int i = 0; i < (int) lista.size(); i++)
    {
        if(lista[i] == palavra)
            return true;
    }
    return false;
}
void quickSort(std::vector<Word> &arr, int left, int right, bool flag)
{
    int i = left, j = right;
    float pivot;

    if (flag)
    {
        pivot = arr[(left + right) / 2].getValor();
    }
    else
    {
        pivot = (float) arr[(left + right) / 2].getOcorrencias();
    }

    /* partition */
    while (i <= j)
    {

        if (flag)
        {
            while (arr[i].getValor() < pivot)
                i++;
        }
        else
        {
            while ( (float)arr[i].getOcorrencias() < pivot)
                i++;
        }



        if(flag)
        {
            while (arr[j].getValor() > pivot)
                j--;
        }
        else
        {
            while ((float)arr[j].getOcorrencias() > pivot)
                j--;
        }
        if (i <= j)
        {
            std::swap(arr[i],arr[j]);
            i++;
            j--;
        }
    };

    /* recursion */
    if (left < j)
        quickSort(arr, left, j,flag);
    if (i < right)
        quickSort(arr, i, right,flag);
}
