#ifndef CLASSHASH_H_INCLUDED
#define CLASSHASH_H_INCLUDED
#include "classWord.h"

class HashTable{
    private:
        int tamanho;
        int numItens;
        std::vector<Word*> myWords;


    private:
        int valorString(std::string str);
        int chaveDivisao(int chave, int tamTabela);
        int sondagemLinear(int pos,int i, int tamTabela);
        Word ** getWord(std::string palavra,int position);
        void updateWord(std::string palavra,int position,float value,int ocurrences);

    public:
        HashTable(int Tam);
        int getTam();
        int getItens();
        int setItens(int itens);
        void insertWord(std::string nome,float value);
        float valueWord(std::string palavra);
        std::vector<Word*> getRealItems();
        void showNames();
        ~HashTable(void);
};

#endif // CLASSHASH_H_INCLUDED
