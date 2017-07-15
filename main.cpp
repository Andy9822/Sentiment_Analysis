#include "tools.h"

using namespace std;

int main()
{
    vector<string> lineWords;
    vector<string> fileContent;
    string line, phrase;
    ifstream myfile ("input.txt");
    int index=0;

    HashTable tabela(25);
    cout << "Tamanho da Tabela Hash = " <<tabela.getTam() << endl ;


    if (! myfile.is_open())
    {
        cout << "Unable to open file";
        exit(EXIT_FAILURE);
    }

    while ( getline (myfile,line) )
    {
        fileContent.push_back(line);
        lineWords = splitStr(line); /// Separa em um vector cada palavra da linha
        for(int i = 1; i < (int) lineWords.size() -1; i++)
        {
            tabela.insertWord(lineWords[i],(float) atof(lineWords[0].c_str()), index); /// Insere palavra por palavra do vector na Tabela Hash
        }
        index++;
    }
    //for(std::vector<string> :: iterator it = fileContent.begin(); it != fileContent.end(); ++it)
    //    cout << *it <<endl;

    myfile.close();
    tabela.showNames();

    int opt;
    int k;
    string palavra;
    cout << endl;
    cout << "========= MENU ==========" << endl;
    cout << "1 - Classificar novo comentario" << endl;
    cout << "2 - Mostrar os K mais positivos" << endl;
    cout << "3 - Mostrar os K mais negativos" << endl;
    cout << "4 - Mostrar os K mais frequentes" << endl;
    cout << "5 - Buscar comentarios associados a uma palavra" << endl;
    cout << "6 - Buscar palavras por radical" << endl;
    cout << "7 - Teste a partir de um arquivo" << endl;
    cout << "0 - Sair" << endl;
    cout << "==========================" << endl;
    cout << endl << "Digite sua opcao: ";
    cin >> opt;
    cout << endl;
    switch(opt)
    {
        case 0:
            cout << "Saindo do programa" << endl;
            exit(EXIT_SUCCESS);
            break;
        case 1:
            // classificar
            break;
        case 2:
            cout << endl <<"Digite o K: ";
            cin >> k;
            nPositives(k, &tabela);
            break;
        case 3:
            cout << endl <<"Digite o K: ";
            cin >> k;
            nNegatives(k, &tabela);
            break;
        case 4:
            cout << endl <<"Digite o K: ";
            cin >> k;
            nFrequency(k, &tabela);
            break;
        case 5:
            cout << endl << "Digite a palavra: ";
            cin >> palavra;
            cout << endl << "Digite a polaridade, ou digite 6 para ignorar: ";
            cin >> k;
            searchComments(palavra, &tabela, k, fileContent);
            break;
        case 6:
            break;
        case 7:
            break;
        default:
            break;
    }
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
