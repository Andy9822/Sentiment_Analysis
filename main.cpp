#include "tools.h"

using namespace std;

int main()
{

    HashTable tabela(24);
    tabela = inputToHashTable(tabela);


    cout << "Tamanho da Tabela Hash = " <<tabela.getTam() << endl ;
    tabela.showNames();
    cout << "Numero de palavras = " << tabela.getItens() << endl << endl;



    return EXIT_SUCCESS;
}



/*
Word n1,n2,n3,n4,n5,n6;
n1.addWord("imagina",0,1);
n2.addWord("indio",2,1);
n3.addWord("amigo",4,1);
n4.addWord("iato",5,1);
n5.addWord("leo",5,1);
n6.addWord("indiana",1,1);

cout << "Todas as palavras:\n" << n1.getString() << "  "<< n2.getString() << "  "<< n3.getString() << "  "<< n4.getString() << "  "<< n5.getString() << "  "<< n6.getString() << "  " <<endl << endl;

cout << "Palavras com radical \"in\" " << endl;
if(n1.isRadixWord("in")){
    cout << n1.getString()<<endl;
}

if(n2.isRadixWord("in")){
    cout << n2.getString() <<endl;
}
if(n3.isRadixWord("in")){
    cout << n3.getString()<<endl;
}
 if(n4.isRadixWord("in")){
    cout << n4.getString()<<endl;
}

if(n5.isRadixWord("in")){
    cout << n5.getString() <<endl;
}
if(n6.isRadixWord("in")){
    cout << n6.getString()<<endl;
}*/
