#ifndef HEAD078_H
#define HEAD078_H
#include "../user.h"

#include <string>
#include <iostream> 
#include <algorithm>
using namespace std;

struct MatrixNode {
    char data;
    MatrixNode* next;
    MatrixNode(char d): data(d), next(nullptr) {}
};

void append(jawaban*& head, char data);
void appendMatrixNode(MatrixNode*& head, char data);
void generateKeyTable(jawaban* key, MatrixNode*& table);
void findPosition(MatrixNode* table, char letter, int& row, int& col);
char getCharAt(MatrixNode* table, int row, int col);
void encryptByPlayfairCipher(MatrixNode* table, jawaban* plainText, jawaban*& cipherText);
jawaban* PlayfairCipher(jawaban* plaintext, jawaban* key);

#endif