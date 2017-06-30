#include "classHash.h"

using namespace std;

int main()
{
    HashTable tabela(5);

    cout << "Tamanho da Tabela Hash = " <<tabela.getTam() << endl ;
    tabela.insertWord("Andy",4);
    tabela.insertWord("Andy",2);
    tabela.insertWord("Leo",1);
    tabela.insertWord("Bravo",1);
    tabela.insertWord("Bravo",10);
    cout << "Numero de palavras = " << tabela.getItens() << endl << endl;

    cout << "Valor de Andy = " << tabela.valueWord("Andy") << endl;
    cout << "Valor de Leo = " << tabela.valueWord("Leo") << endl;
    cout << "Valor de Bravo = " << tabela.valueWord("Bravo") << endl;
    cout << endl;
    tabela.showNames();





    return 0;
}
