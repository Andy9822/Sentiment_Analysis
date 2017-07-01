#include "classHash.h"

Word::Word(){
        palavra = "";
        ocorrencias = 0;
        valor = 0;
}

///Getters & Setters
int Word::getOcorrencias(){
    return ocorrencias;
}

float Word::getValor(){
    return valor;
}

std::string Word::getString(){
    return palavra;
}

void Word::updateWord(float value){

    valor = ((ocorrencias * valor) + value) / (ocorrencias + 1 );
    ocorrencias += 1;

}

bool Word::isEmpty(){

    if(palavra.compare("") == 0){
        return 1;
    }

    else{
        return 0;
    }

}

///Methods
void Word::addWord(std::string pal, float value,int ocurrences){ ///Inicializa de fato um Objeto Word com os dados passados
    palavra = pal;
    ocorrencias = ocurrences;
    valor = value;
}

bool Word::sameString(std::string str){///Retorna se a string passada equivale à palavra do Objeto Word

    if( palavra.compare(str) == 0){

        return true;
    }

    return false;
}

bool Word::isRadixWord(std::string radical){///Retorna se a string passada é radical da palavra do Objeto Word

    if (radical.size() > palavra.size()){

        return false;
    }

    for(int i = 0; i < ((int) (radical.size())) ; i++){

        if( radical[i] != palavra[i] ){

            return false;
        }

    }

    return true;
}
