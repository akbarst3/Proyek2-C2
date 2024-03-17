#ifndef HEAD078_H
#define HEAD078_H
#include "../231511091/231511091.h"

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

const string list1 = "abcdefghiklmnopqrstuvwxyz";
void generateKeyTable(const string& key, string& table);
void encryptByPlayfairCipher(const string& table, const string& plainText, string& cipherText);
string PlayfairCipher(string& plainText, string& key);

#endif 