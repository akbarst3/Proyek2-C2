#ifndef HEAD078_H
#define HEAD078_H

#include <string>
#include <iostream>
#include<algorithm>
using namespace std;


void removeSpaces(string& str);
void toLowerCase(string& str);
void fillDiagraph(string& str);
void generateKeyTable(const string& key, string& table);
void encryptByPlayfairCipher(const string& table, const string& plainText, string& cipherText);
void printMatrix(const string& table);

#endif /
