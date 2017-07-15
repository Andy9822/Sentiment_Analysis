#include "classHash.h"

HashTable::HashTable(int tam)
{
    tamanho = tam;
    numItens = 0;
    for (int i = 0; i < tamanho; i++)
        myWords.push_back(NULL);
}

///Setters & Getters
int HashTable::getTam()
{
    return tamanho;
}

int HashTable::getItens()
{
    return numItens;
}

std::vector<Word*> HashTable::getRealItems()
{
    return myWords;
}

int HashTable::setItens(int itens)
{
    if (itens <= tamanho)
    {
        numItens = itens;
        return 1;
    }

    return 0;
}

///Methods
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

int HashTable::chaveDivisao(int chave, int tamTabela) ///Retorna um valor associado � chave passada
{
    return (chave & 0x7FFFFFFF) % tamTabela;
}

int HashTable::sondagemLinear(int pos,int i, int tamTabela)  ///Se h� colis�o, procura pelo elemento nas pr�ximas posi��es da Tabela Hash
{

    return ( ((pos + i) & 0x7FFFFFFF) % tamTabela );
}

Word ** HashTable::getWord(std::string palavra,int position)  ///Retorna o Objeto Word correspondente � string passada
{

    int newPos;
    Word ** ptWord;
    for (int i = 0; i < getTam(); i++)
    {
        newPos = sondagemLinear(position,i,getTam());

        if(myWords[newPos] == NULL )
        {

            ptWord = &(myWords[newPos]);
            break;
        }

        else if(myWords[newPos]->sameString(palavra) )
        {

            ptWord = &(myWords[newPos]);
            break;
        }
    }
    return ptWord;
}

Word * HashTable::getRealWord(std::string palavra) {
    int position = chaveDivisao(valorString(palavra),getTam());
    return *(getWord(palavra, position));
}

void HashTable::updateWord(std::string str,int position,float value,int ocurrences, int linha)  ///Atualiza o Objeto Word correspondente � string
{
    Word ** palavra = getWord(str,position);
    if( (*palavra) != NULL)
    {
        (*palavra)->updateWord(value, linha);
    }
    else
    {
        (*palavra) = new Word(str,ocurrences,value, linha);
        setItens(getItens() +1);
    }
    palavra = NULL;
}

void HashTable::insertWord(std::string nome,float value,int linha)  ///Atualizar� ou criar� um Objeto Word com a string e valor passados
{
    int position = chaveDivisao(valorString(nome),getTam());
    updateWord(nome,position,value,1, linha);
}

float HashTable::valueWord(std::string palavra)  ///Retorna o valor do Objeto Word correspondente � string passada
{
    Word ** ptWord = getWord(palavra,chaveDivisao(valorString(palavra),getTam()));
    if (*ptWord == NULL)
        return 2;
    else {
        float valor = (*ptWord)->getValor();
        return valor;
    }
}

void HashTable::showNames()  ///M�todo que mostra toda a tabela Hash
{

    for(int i = 0; i < getTam(); i++)
    {

        if(myWords[i] != NULL)
        {

            std::cout << "palavra  = " << myWords[i]->getString() <<"  valor = " << myWords[i]->getValor() <<"  ocorrencias = " << myWords[i]->getOcorrencias() << std::endl;
            for(int j = 0; j < (int) myWords[i]->getLinhas().size(); j++)
            {
                std::cout << myWords[i]->getLinhas()[j] << " ";
            }
            std::cout << std::endl;
        }
        else
        {

            std::cout << "NULL"<< std::endl;
        }
    }
    std::cout << std::endl;

}

HashTable::~HashTable(void)
{
    std::cout << "Vector ... deleting" << std::endl<< std::endl;
    for (int i = 0; i < tamanho; i++){

        if (myWords[i] != NULL)
        {
            delete myWords[i];
            std::cout <<i+1 << "a posicao desalocada \n";

        }
        else
            std::cout << "NULL" << std::endl;
    }

    std::cout << std::endl<< "Vector ... deleted" << std::endl;
    myWords.clear();
}
