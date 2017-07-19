#include "tools.h"
#include <algorithm>
#include <string>
#include <conio.h>
#include <fstream>

using namespace std;

bool checkAlpha(string str){
    for(int i = 0; i < (int)str.size(); i++)
        if( !isalpha(str[i]))
            return false;
    return true;
}


int main()
{

        vector<string> lineWords, fileContent, filtering, palavrasRadicais,terminais,vianna;
        vector<Word> valuesWords,ocurrencesWords;
        string line, phrase,palavra,tempString, radical,nomeSaida,nomeTSV;
        ifstream myfile ("input.txt");
        ofstream saidaCSV;
        bool firstTsv = true,sortedValues = false,sortedFreq = false;
        int index=0, opt, k;
        HashTable tabela(2);
        Trie arvore;
        //readVocabulary(&tabela,&arvore,fileContent);
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
                if (!alreadyInsideString(filtering, tempString) && checkAlpha(tempString))
                {
                    //cout << "O" << tempString << "O" << endl;
                    tabela.insertWord(tempString,(float) atof(lineWords[0].c_str()), index); /// Insere palavra por palavra do vector na Tabela Hash
                    arvore.insertWord(tempString);
                }
            }
            index++;
        }
        cout << "Sai daqui";
        lineWords.clear();
        filtering.clear();
        tempString.clear();
        line.clear();
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
                classify(splitStr(phrase), &tabela,1);
                phrase.clear();
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
                cout  << "Digite a polaridade, ou digite 5 para ignorar: ";
                cin >> k;
                cout << endl<< "Nota e comentarios com a palavra " << palavra << " :" <<endl;
                std::transform(palavra.begin(), palavra.end(), palavra.begin(), ::tolower);
                searchComments(palavra, &tabela, k, fileContent);
                palavra.clear();
                cout <<endl <<endl<< "Press any key to Continue... ";
                getch();
                break;
            case 6:
                cout <<"Digite o radical pelo qual quer procurar palavras :  ";
                cin >> radical;
                std::transform(radical.begin(), radical.end(), radical.begin(), ::tolower);
                cout <<endl <<"Palavras com radical " <<radical << " :"<<endl<< endl;
                terminais = arvore.radixWords(radical);
                for(int i = 0; i < (int)terminais.size(); i++){
                    cout << terminais[i]<<endl;
                }
                radical.clear();
                palavrasRadicais.clear();
                terminais.clear();
                cout <<endl <<endl<< "Press any key to Continue... ";
                getch();
                break;
            case 7:
                cout << "Digite o nome do arquivo de entrada TSV com a extensao .tsv no final" <<endl;
                cin >>nomeTSV;
                myfile.open(nomeTSV.c_str());
                if ( myfile.is_open()){
                    cout << "Digite o nome de arquivo de saída com o .csv no final" <<endl;
                    cin >>nomeSaida;
                    saidaCSV.open(nomeSaida.c_str());
                while(std::getline(myfile, line))       // '\n' is the default delimiter
                {

                    vianna = splitStr(line);
                    if(!firstTsv)
                    {
                        saidaCSV << vianna[0] << "," << classify(vianna, &tabela,0) <<"\n";
                    }
                    else
                        firstTsv = false;
                    vianna.clear();
                }
                cout << "\nO arquivo " << nomeSaida<< " foi gerado com sucesso!" << endl;
                }
                else{
                    cout << "Arquivo inexistente, nao foi gerada nenhum output..." << endl;
                }

                nomeSaida.clear();
                nomeTSV.clear();
                line.clear();
                cout <<endl <<endl<< "Press any key to Continue... ";
                getch();
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
