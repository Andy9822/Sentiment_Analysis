#ifndef CLASSWORD_H_INCLUDED
#define CLASSWORD_H_INCLUDED
#include "imports.h"

class Word{
    private:
        float valor;
        int ocorrencias;
        std::string palavra;
        std::vector<int> linhas;


    public:
        Word(std::string str, int ocurrences, float value, int linha);
        int getOcorrencias();
        std::vector<int> getLinhas();
        float getValor();
        std::string getString();
        void updateWord(float value, int linha);
        bool sameString(std::string palavra);
        bool isRadixWord(std::string radical);
};


#endif // CLASSWORD_H_INCLUDED
