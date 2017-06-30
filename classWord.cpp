#include "classWord.h"

Word::Word(){
        palavra = "";
        ocorrencias = 0;
        valor = 0;
}

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

void Word::addWord(std::string pal, float value){
    palavra = pal;
    ocorrencias = 1;
    valor = value;
}
