#include "trie.h"
#include <algorithm>
#include <string>
//#include <conio.h>

using namespace std;
int main()
{

    vector<string> lineWords, fileContent, filtering, palavrasRadicais;
    vector<Word> valuesWords,ocurrencesWords;
    string line, phrase,palavra,tempString, radical;
    vector<string> terminais,vianna;
    ifstream myfile ("input.txt"), dementes("test.tsv");
    ofstream saidaCSV;
    bool firstTsv = true;

    int index=0, opt, k;
    bool sortedValues = false;
    bool sortedFreq = false;
    HashTable tabela(2);
    filtering = fillingFilter();
    Trie arvore;

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
            tempString = lineWords[i];
            std::transform(tempString.begin(), tempString.end(), tempString.begin(), ::tolower);
            if (!alreadyInsideString(filtering, tempString) )
            {
                tabela.insertWord(tempString,(float) atof(lineWords[0].c_str()), index); /// Insere palavra por palavra do vector na Tabela Hash
                arvore.insertWord(tempString);
            }
        }
        index++;
    }

    lineWords.clear();
    filtering.clear();

    //for(std::vector<string> :: iterator it = fileContent.begin(); it != fileContent.end(); ++it)
    //    cout << *it <<endl;

    myfile.close();
    tabela.showNames();

    showMenu();
    cin >> opt;
    while(opt)
    {

        switch(opt)
        {
        case 1:
            cout << "Digite sua frase: ";
            cin.clear();
            fflush(stdin);
            getline(cin, phrase);
            cout << endl;
            std::transform(phrase.begin(), phrase.end(), phrase.begin(), ::tolower);
            classify(splitStr(phrase), &tabela,1);
            cout <<endl <<endl<< "Press any key to Continue... ";
            //getch();
            break;
        case 2:
        case 3:
            cout  <<"Digite o K: ";
            cin >> k;
            cout << endl;
            if(!sortedValues)
            {
                if(!sortedFreq)
                {
                    valuesWords = tabela.fillVector();
                    ocurrencesWords = valuesWords;
                }
                quickSort(valuesWords,0,(int)valuesWords.size() - 1,1);
                sortedValues = true;
            }

            if (opt == 2)
            {
                cout<<k << " palavras com maior valor:"<<endl;
                for(int i =1 ; i <= k ; i++)
                    cout << valuesWords[(int) valuesWords.size()- i].getString()<<"\t\t" <<valuesWords[(int) valuesWords.size()- i].getValor() << endl;
            }

            else
            {
                cout<<k << " palavras com menor valor:"<<endl;
                for(int i = 0; i < k; i++)
                    cout << valuesWords[i].getString()<<"\t\t" <<valuesWords[i].getValor() << endl;
            }
            cout <<endl <<endl<< "Press any key to Continue... ";
            //getch();
            break;

        case 4:
            cout  <<"Digite o K: ";
            cin >> k;
            cout << endl <<k << " palavras mais frequentes:"<<endl;
            if(!sortedFreq)
            {
                if(!sortedValues)
                {
                    valuesWords = tabela.fillVector();
                    ocurrencesWords = valuesWords;
                }
                quickSort(ocurrencesWords,0,(int)ocurrencesWords.size() - 1,0);
                sortedFreq = true;
            }
            for(int i =1 ; i <= k ; i++)
                cout << ocurrencesWords[(int) ocurrencesWords.size()- i].getString()<< "\t\t" << ocurrencesWords[(int) ocurrencesWords.size()- i].getOcorrencias() << endl;

            cout <<endl <<endl<< "Press any key to Continue... ";
            //getch();
            break;

        case 5:
            cout << endl << "Digite a palavra: ";
            cin >> palavra;
            cout << endl << "Digite a polaridade, ou digite 5 para ignorar: ";
            cin >> k;
            std::transform(palavra.begin(), palavra.end(), palavra.begin(), ::tolower);
            searchComments(palavra, &tabela, k, fileContent);
            cout <<endl <<endl<< "Press any key to Continue... ";
            //getch();
            break;
        case 6:
            cout <<"Digite o radical pelo qual quer procurar palavras :  ";
            cin >> radical;
            std::transform(radical.begin(), radical.end(), radical.begin(), ::tolower);
            cout <<endl <<"Palavras com radical " <<radical << " :"<<endl<< endl;
            terminais = arvore.radixWords(radical);
            for(int i = 0; i < (int)terminais.size(); i++)
                cout << terminais[i]<<endl;
            cout <<endl <<endl<< "Press any key to Continue... ";
            //getch();
            palavrasRadicais = tabela.radixStrings(radical);
            for(int i=0; i< (int)palavrasRadicais.size(); i++)
            {
                cout<< palavrasRadicais[i] << endl;
            }
            palavrasRadicais.clear();
            break;
        case 7:

            saidaCSV.open("saida.csv");
            while(std::getline(dementes, line))       // '\n' is the default delimiter
            {

                vianna = splitStr(line);
                if(!firstTsv)
                {
                    saidaCSV << vianna[0] << ",";
                    cout << "ID: " << vianna[0] << " :" << endl;
                    for(int i =2; i < (int) vianna.size() -1; i++)
                        cout << vianna[i] << "  ";
                    cout << endl;

                    saidaCSV << classify(vianna, &tabela,1) <<"\n";
                }
                else
                    firstTsv = false;
                vianna.clear();
            }
            break;
        case 8:
            system("cls");
            break;
        default:
            break;
        }
        cout << endl;
        showMenu();
        cin >> opt;
    }
    cout <<endl<< "Saindo do programa..." << endl;
    return EXIT_SUCCESS;




    /*
    Trie arvore;
    arvore.insertWord("ba");
    arvore.insertWord("bac");
    arvore.insertWord("dado");
    arvore.insertWord("dacu");
    cout << arvore.filhos[1]->prefixo << endl;
    cout << arvore.filhos[1]->filhos[0]->prefixo << endl;
    cout << arvore.filhos[1]->filhos[0]->filhos[2]->prefixo << endl;

    vector<string> terminais = arvore.radixWords("d");
    cout << "Tamanho dos terminais = " << terminais.size()<<endl;
    for(int i = 0; i < (int)terminais.size();i++)
    cout << terminais[i]<<endl;*/
}
