#include "tools.h"
#include <algorithm>
#include <string>
#include <conio.h>
using namespace std;
int main()
{
    vector<string> lineWords, fileContent, filtering, palavrasRadicais;
    vector<Word> valuesWords,ocurrencesWords;
    string line, phrase,palavra,tempString, radical;
    ifstream myfile ("input.txt");
    int index=0, opt, k;
    bool sortedValues = false;
    bool sortedFreq = false;
    HashTable tabela(25);
    filtering = fillingFilter();

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
            }
        }
        index++;
    }

    lineWords.clear();
    filtering.clear();

    //for(std::vector<string> :: iterator it = fileContent.begin(); it != fileContent.end(); ++it)
    //    cout << *it <<endl;

    myfile.close();
    //tabela.showNames();

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
            classify(phrase, &tabela);
            cout <<endl <<endl<< "Press any key to Continue... ";
            getch();
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
            getch();
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
            getch();
            break;

        case 5:
            cout << endl << "Digite a palavra: ";
            cin >> palavra;
            cout << endl << "Digite a polaridade, ou digite 6 para ignorar: ";
            cin >> k;
            std::transform(palavra.begin(), palavra.end(), palavra.begin(), ::tolower);
            searchComments(palavra, &tabela, k, fileContent);
            cout <<endl <<endl<< "Press any key to Continue... ";
            getch();
            break;
        case 6:
            cout <<"Digite o radical pelo qual quer procurar palavras :  ";
            cin >> radical;
            cout <<endl <<"Palavras com radical " <<radical << " :"<<endl<< endl;
            palavrasRadicais = tabela.radixStrings(radical);
            for(int i=0; i< (int)palavrasRadicais.size(); i++){
                cout<< palavrasRadicais[i] << endl;
            }
            palavrasRadicais.clear();
            cout <<endl <<endl<< "Press any key to Continue... ";
            getch();
            break;
        case 7:
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
}
