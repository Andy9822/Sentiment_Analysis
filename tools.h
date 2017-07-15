#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

#include "classHash.h"


std::vector<std::string> splitStr(std::string str);
float phraseNote(std::string phrase, HashTable * tabela);
void nPositives(int n, HashTable * tabela);
void nNegatives(int n, HashTable * tabela);
void nFrequency(int n, HashTable * tabela);
void searchComments(std::string palavra, HashTable * tabela, int pontuacao, std::vector<std::string> fileContent);
bool alreadyInside(std::vector<Word*> wordArray, Word word);
#endif // TOOLS_H_INCLUDED
