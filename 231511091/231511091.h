#ifndef HEAD91_H
#define HEAD91_H 
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <cmath>
#include "../user.h"

using namespace std;

void CaesarCipherEnkrip(jawaban* head, int shift);
void createFile(jawaban* head, string user, string namaFile);
void toLowerCase(string &str);
void buatkey(string key, jawaban* &headkey);

#endif

