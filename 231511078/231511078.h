#ifndef HEAD078_H
#define HEAD078_H

#include <string>
#include <iostream>
#include<algorithm>
using namespace std;


void removeSpaces(std::string& str);
void toLowerCase(std::string& str);
void fillDiagraph(std::string& str);
void generateKeyTable(const std::string& key, std::string& table);
void encryptByPlayfairCipher(const std::string& table, const std::string& plainText, std::string& cipherText);
void printMatrix(const std::string& table);

#endif /
