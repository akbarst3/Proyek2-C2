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
    MatrixNode(char d);
};

string list1 = "abcdefghiklmnopqrstuvwxyz"; 

Node::Node(char d) : data(d), next(nullptr) {}
MatrixNode::MatrixNode(char d) : data(d), next(nullptr) {}

// Function declarations
void append(Node*& head, char data);
void appendMatrixNode(MatrixNode*& head, char data);
void generateKeyTable(Node* key, MatrixNode*& table);
void findPosition(MatrixNode* table, char letter, int& row, int& col);
char getCharAt(MatrixNode* table, int row, int col);
void encryptByPlayfairCipher(MatrixNode* table, Node* plainText, Node*& cipherText);

#endif