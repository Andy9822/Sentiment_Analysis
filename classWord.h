#ifndef CLASSWORD_H_INCLUDED
#define CLASSWORD_H_INCLUDED
#include "imports.h"

class Word{
    private:
        float valor;
        int ocorrencias;
        std::string palavra;



    public:
        Word();
        int getOcorrencias();
        float getValor();
        void updateWord(float value);
        std::string getString();
        void addWord(std::string pal,float value,int ocurrences);
        bool isEmpty();
        bool isRadixWord(std::string radical);
        bool sameString(std::string palavra);
};


#endif // CLASSWORD_H_INCLUDED
