#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED


#include "classHash.h"

class Trie{

//private:
public:
    std::vector<Trie*> filhos;
    std::string prefixo;
    bool ehPalavra;
int help;


public:
    Trie();
    void insertWord(std::string str);
    void recursionInsert(Trie** nodo,std::string str, int cont);
    void setPrefixo(std::string str);
    void virouPalavra();
    Trie* getRadixNode(Trie * nodo,std::string str, int cont,bool *flag);
    std::vector<std::string> radixWords(std::string str);
    void recursionSearch(Trie* nodo,std::string str,std::vector<std::string> &palavras);
    ~Trie();

};

#endif // TRIE_H_INCLUDED
