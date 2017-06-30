#include "classHash.h"
#include "classWord.h"
#include "imports.h"
using namespace std;

int main()
{
    HashTable tabela(5);

    cout << "tamanho eh " <<tabela.getTam() << endl;


    if (tabela.setItens(4))
        cout << "numero elementos " <<tabela.getItens() << endl << endl;


    Word boa;
    cout <<"Ocorrencias: " << boa.getOcorrencias() << endl << "Valor: " << boa.getValor() << endl << "len string: " << boa.getString().length() << endl << endl;

    boa.addWord("Cry",2);
    boa.updateWord(5);
    boa.updateWord(1);
    boa.updateWord(2);
    cout <<"Ocorrencias: " << boa.getOcorrencias() << endl << "Valor: " << boa.getValor() << endl << "Palavra: " << boa.getString() << endl;




    return 0;
}
