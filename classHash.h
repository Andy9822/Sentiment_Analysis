#ifndef CLASSHASH_H_INCLUDED
#define CLASSHASH_H_INCLUDED

#include "imports.h"
class HashTable{
    private:
        int tamanho;
        int numItens;



    public:
        HashTable(int Tam);
        int getTam();
        int getItens();
        int setItens(int itens);
};

#endif // CLASSHASH_H_INCLUDED
