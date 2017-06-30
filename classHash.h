#ifndef CLASSHASH_H_INCLUDED
#define CLASSHASH_H_INCLUDED
#include "classWord.h"

class HashTable{
    private:
        int tamanho;
        int numItens;
        std::vector<Word> myWords;


    private:
        int valorString(std::string str);
        int chaveDivisao(int chave, int tamTabela);
        void updateWord(std::string palavra,int position,float value,int ocurrences);
        int sondagemLinear(int pos,int i, int tamTabela);
        void newWord(Word *emptyWord,std::string palavra, float value,int ocurrences);
        Word * getWord(std::string palavra,int position);

    public:
        float valueWord(std::string palavra);
        void insertWord(std::string nome,float value);
        void showNames();
        HashTable(int Tam);
        int getTam();
        int getItens();
        int setItens(int itens);
        ~HashTable(void);
};

#endif // CLASSHASH_H_INCLUDED
