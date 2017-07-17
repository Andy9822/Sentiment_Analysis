#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

#include "classHash.h"


std::vector<std::string> splitStr(std::string str);
float phraseNote(std::string phrase, HashTable * tabela);
void searchComments(std::string palavra, HashTable * tabela, int pontuacao, std::vector<std::string> fileContent);
bool alreadyInside(std::vector<Word*> wordArray, Word word);
void classify(std::string entrada, HashTable * tabela);
void showMenu();
std::vector<std::string> fillingFilter();
bool alreadyInsideString (std::vector<std::string> lista, std::string palavra);
void quickSort(std::vector<Word> &arr, int left, int right, bool flag);
#endif // TOOLS_H_INCLUDED
