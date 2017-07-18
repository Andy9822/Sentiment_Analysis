#include "trie.h"

Trie::Trie(){
    for (int i =0; i <26;i++ ){
        filhos.push_back(NULL);
    }
}

void Trie::setPrefixo(std::string str){
    prefixo = str;
}

void Trie::virouPalavra(){
    ehPalavra = true;
}

void Trie::insertWord(std::string str){
    int cont = 1,index;
    index = (int) str[0] - (int) 'a';
    std::cout << "> " << str<<"\n";
    //std::cout <<"Letra " <<str[0] << "   com indice :" <<index <<"\n";
    recursionInsert(&(filhos[index]),str,cont);
    //std::cout << "Sera que tem  : " <<  filhos[1]->prefixo<<"\n";

}

void Trie::recursionInsert(Trie** nodo,std::string str, int cont){
    if(*nodo == NULL){
      (*nodo) = new Trie();
      (*nodo)->ehPalavra = false;
      (*nodo)->prefixo.append(str,0,cont);
     // std::cout <<"Novo nodo com prefixo = " <<(*nodo)->prefixo << "\n" <<"Letra " <<str[cont] << "   com indice :" <<((int) str[cont] - (int) 'a') <<"\n";

    }

    if( (*nodo)->prefixo.compare(str)!= 0){
        //std::cout <<"Deu tamanho diferente " <<"\n";
        recursionInsert(&((*nodo)->filhos[ ((int) str[cont] - (int) 'a') ]),str,cont+1 );
    }
    else{

      (*nodo)->ehPalavra = true;
      std::cout << "Cheguei aqui raca  "<<str <<"\n";

    }


}

Trie * Trie::getRadixNode(Trie * nodo,std::string str, int cont){

    if(nodo == NULL){
        return nodo;
    }
    if((int) str.size() == cont){
        return nodo;
    }
    getRadixNode(nodo->filhos[ (int) str[cont] - (int) 'a' ],str,cont+1);


}


std::vector<std::string> Trie::radixWords(std::string str){
    std::vector<std::string> palavras;

    Trie * nodoInicio = getRadixNode(filhos[ (int)str[0] - (int) 'a'  ],str,1);

    if(nodoInicio!=NULL)
        recursionSearch(nodoInicio,str,palavras);

    return palavras;
}

void Trie::recursionSearch(Trie* nodo,std::string str,std::vector<std::string> &palavras){
    if(nodo !=NULL){

        if(nodo->ehPalavra)
            palavras.push_back(nodo->prefixo);
        for(int i = 0; i < 26; i++)
            recursionSearch(nodo->filhos[i],str,palavras);
    }


}

Trie::~Trie(){
    for (int i = 0; i < 26; i++){
            delete filhos[i];
    }
    std::cout<< "\nPonteiro deleted";



}
