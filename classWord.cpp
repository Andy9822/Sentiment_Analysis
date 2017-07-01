#include "classHash.h"

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

bool Word::isEmpty(){

    if(palavra.compare("") == 0){
        return 1;
    }

    else{
        return 0;
    }

}

void Word::addWord(std::string pal, float value,int ocurrences){
    palavra = pal;
    ocorrencias = ocurrences;
    valor = value;
}

bool Word::radixWord(std::string radical){

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
