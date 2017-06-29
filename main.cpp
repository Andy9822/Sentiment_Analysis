#include <iostream>
#include "classHash.h"

using namespace std;

int main()
{
    HashTable tabela(5);

    cout << "tamanho eh " <<tabela.getTam() << endl;


    if (tabela.setItens(4))
        cout << "numero elementos " <<tabela.getItens() << endl;





    return 0;
}
