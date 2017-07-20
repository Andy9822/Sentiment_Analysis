#include "trie.h"

Trie::Trie()
{
    for (int i =0; i <26; i++ )
        filhos.push_back(NULL);
    help = 0;
}

void Trie::setPrefixo(std::string str)
{
    prefixo = str;
}

void Trie::virouPalavra()
{
    ehPalavra = true;
}

void Trie::insertWord(std::string str)
{
    int cont = 1,index;
    index = (int) str[0] - (int) 'a';
    recursionInsert(&(filhos[index]),str,cont);
}

void Trie::recursionInsert(Trie** nodo,std::string str, int cont)
{
    if(*nodo == NULL)
    {
        (*nodo) = new Trie();
        (*nodo)->ehPalavra = false;
        (*nodo)->prefixo.append(str,0,cont);
        help+=1;
    }

    if( (*nodo)->prefixo.compare(str)!= 0)
        recursionInsert(&((*nodo)->filhos[ ((int) str[cont] - (int) 'a') ]),str,cont+1 );
    else
        (*nodo)->ehPalavra = true;
}

Trie * Trie::getRadixNode(Trie * nodo,std::string str, int cont,bool *flag)
{
    if(nodo == NULL)
        *flag = *flag | false;
    else
    {
        if((int) str.size() == cont)
        {
            *flag = *flag | true;
            return nodo;
        }
        return getRadixNode(nodo->filhos[ (int) str[cont] - (int) 'a' ],str,cont+1,flag);
    }
}


std::vector<std::string> Trie::radixWords(std::string str)
{
    std::vector<std::string> palavras;

    bool flag = false;
    Trie * nodoInicio = getRadixNode(filhos[ (int)str[0] - (int) 'a'  ],str,1,&flag);

    if(flag)
        recursionSearch(nodoInicio,str,palavras);

    return palavras;
}

void Trie::recursionSearch(Trie* nodo,std::string str,std::vector<std::string> &palavras)
{
    if(nodo !=NULL)
    {
        if(nodo->ehPalavra)
            palavras.push_back(nodo->prefixo);
        for(int i = 0; i < 26; i++)
        {
            if(nodo->filhos[i]!=NULL)
            {
                recursionSearch(nodo->filhos[i],str,palavras);
            }
        }
    }
}

Trie::~Trie()
{
    for (int i = 0; i < 26; i++)
        delete filhos[i];
}
