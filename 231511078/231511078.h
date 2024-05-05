#ifndef HEAD078_H
#define HEAD078_H

#include <string>
#include <iostream> 
#include <algorithm>
using namespace std;

struct Node {
  char data;
  Node* next;
};

const string list1 = "abcdefghiklmnopqrstuvwxyz";
Node* newNode(char data);
void generateKeyTable(const string& key, string& table);
void encryptByPlayfairCipher(const string& table, const string& plainText, string& cipherText);
string PlayfairCipher(string& plainText, string& key);

#endif 