#include "tools.h"

using namespace std;

int main()
{
    vector<string> lineWords;
    string line, phrase;
    ifstream myfile ("input.txt");

    HashTable tabela(24);
    cout << "Tamanho da Tabela Hash = " <<tabela.getTam() << endl ;

    if (! myfile.is_open())
    {
        cout << "Unable to open file";
        exit(EXIT_FAILURE);
    }

    while ( getline (myfile,line) )
    {
        lineWords = splitStr(line); /// Separa em um vector cada palavra da linha
        for(int i = 1; i < (int) lineWords.size(); i++)
        {
            tabela.insertWord(lineWords[i],(float) atof(lineWords[0].c_str())); /// Insere palavra por palavra do vector na Tabela Hash
        }
    }

    myfile.close();
    tabela.showNames();

    cout << "Numero de palavras = " << tabela.getItens() << endl << endl;
    //std::getline(std::cin, phrase);
    //std::cout << phraseNote(phrase, &tabela);
    cout << "Palavras mais Positivas" << endl << endl;
    nPositives(8, &tabela);
    cout << endl;
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
