#include "classHash.h"

Word::Word(std::string str, int ocurrences, float value){
        this->palavra = str;
        this->ocorrencias = ocurrences;
        this->valor = value;
}

///Getters & Setters
int Word::getOcorrencias(){
    return this->ocorrencias;
}

float Word::getValor(){
    return this->valor;
}

std::string Word::getString(){
    return this->palavra;
}

///Methods
void Word::updateWord(float value){ ///Recebe um novo valor para a palavra e recalcula o seu valor total fazendo uma média

    this->valor = ((this->ocorrencias * this->valor) + value) / (this->ocorrencias + 1 );
    this->ocorrencias += 1;

}

bool Word::sameString(std::string str){///Retorna se a string passada equivale à palavra do Objeto Word

    if( this->palavra.compare(str) == 0){

        return true;
    }

    return false;
}

bool Word::isRadixWord(std::string radical){///Retorna se a string passada é radical da palavra do Objeto Word

    if (radical.size() > this->palavra.size()){

        return false;
    }

    for(int i = 0; i < ((int) (radical.size())) ; i++){

        if( radical[i] != this->palavra[i] ){

            return false;
        }

    }

    return true;
}
