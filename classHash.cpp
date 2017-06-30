#include "classHash.h"

HashTable::HashTable(int tam){
        tamanho = tam;
        numItens = 0;
        myWords.assign( tamanho, Word() );
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

void HashTable::newWord(Word * emptyWord,std::string palavra, float value,int ocurrences){

    setItens(getItens() + 1);
    (*emptyWord).addWord(palavra,value,ocurrences);
}

int HashTable::valorString(std::string str) ///Retorna um valor associado a uma string (31 e 7 como valores primos arbitrarios, podendo ser qualquer outro primo)
{
    int i,valor = 7;
    int tam = str.size();
    for(i = 0; i < tam; i++)
    {
        valor = 31 * valor + (int) str[i];
    }
    return valor;
}

int HashTable::chaveDivisao(int chave, int tamTabela) ///Retorna um valor associado à chave passada
{
    return (chave & 0x7FFFFFFF) % tamTabela;
}

int HashTable::sondagemLinear(int pos,int i, int tamTabela){

    return ( ((pos + i) & 0x7FFFFFFF) % tamTabela );
}

Word * HashTable::getWord(std::string palavra,int position){

    int newPos;
    Word * ptWord;
    for (int i = 0; i < HashTable::getTam(); i++)
    {
        newPos = sondagemLinear(position,i,getTam());

        if(myWords[newPos].getString().compare(palavra) == 0 ){

            ptWord = (&(myWords[newPos]));;
            break;
        }

        else if(myWords[newPos].isEmpty()){

            ptWord = (&(myWords[newPos]));
            break;
        }
    }
    return ptWord;
}

void HashTable::updateWord(std::string str,int position,float value,int ocurrences){

    Word * palavra = getWord(str,position);

    if( (*palavra).getString().compare(str) == 0 ){

            (*palavra).updateWord(value);
    }
    else if( (*palavra).isEmpty()){

            newWord( (palavra),str,value,ocurrences);
    }
    palavra = NULL;
}

void HashTable::insertWord(std::string nome,float value){
    int position = chaveDivisao(valorString(nome),getTam());
    updateWord(nome,position,value,1);
}

float HashTable::valueWord(std::string palavra){

    Word * ptWord = getWord(palavra,chaveDivisao(valorString(palavra),getTam()));
    float valor = (*ptWord).getValor();
    ptWord = NULL;
    return valor;
}

void HashTable::showNames(){

    for(int i = 0; i < getTam(); i++){
        std::cout << "palavra  = " << myWords[i].getString() <<"  valor = " << myWords[i].getValor() <<"  ocorrencias = " << myWords[i].getOcorrencias() << std::endl;
    }
    std::cout << std::endl;

}

HashTable::~HashTable(void) {
   std::cout << "Word_Objects no Vector = " << myWords.size() << std::endl;
   std::cout << "Vector is being deleted" << std::endl;
   myWords.clear();
   std::cout << "Word_Objects no Vector = " << myWords.size() << std::endl;
}

