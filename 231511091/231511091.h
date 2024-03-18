#ifndef HEAD91_H
#define HEAD91_H 
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;

void CaesarCipherEnkrip(string &plaintext, int shift);
void createFile(string hasilEnkrip, string namaFile, string user);
void removeSpaces(string &str);
void toLowerCase(string &str);
void firstEncryption(string &plaintext, int shift, string &key);

#endif
