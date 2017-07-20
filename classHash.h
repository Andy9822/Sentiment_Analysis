#ifndef CLASSHASH_H_INCLUDED
#define CLASSHASH_H_INCLUDED
#include "classWord.h"

class HashTable{
    private:
        typedef std::vector<Word*> wordVector;
        int tamanho;
        int numItens;
        std::vector<Word*> myWords;


    private:
        int valorString(std::string str);
        int chaveDivisao(int chave, int tamTabela);
        int sondagemLinear(int pos,int i, int tamTabela);
        wordVector::iterator getWord(std::string palavra,int position);
        void updateWord(std::string palavra,int position,float value,int ocurrences, std::vector<int> linha);
        Word getPosition(int position);
        void resizeTableInfos();

    public:
        HashTable(int Tam);
        int getTam();   /// Retorna tamanho
        int getItens(); /// Retorna o num de items
        int setItens(int itens);/// Seta o numero de items
        void insertWord(std::string nome,float value, int linha);   /// Insere uma Word na hash
        Word * getRealWord(std::string palavra);    /// Dado uma string retorna o objeto Word da tabela
        float valueWord(std::string palavra);   /// Dado uma palavra retorna sua pontuacao
        std::vector<Word*> getRealItems();  /// Retorna o vector da tabela hash
        void showNames();   /// Mostra tudo da hashtable
        std::vector<std::string> radixStrings(std::string radical);
        std::vector<Word> fillVector(); /// Preenche o vector
        ~HashTable(void);
};

#endif // CLASSHASH_H_INCLUDED
