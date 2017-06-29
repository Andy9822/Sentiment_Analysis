#include "classHash.h"

HashTable::HashTable(int tam){
        tamanho = tam;
        numItens = 0;
}

int HashTable::getTam(){
    return tamanho;
}

int HashTable::getItens(){
    return numItens;
}

int HashTable::setItens(int itens){
    if (itens <= tamanho){
        numItens = itens;
        return 1;
    }

    return 0;
}
