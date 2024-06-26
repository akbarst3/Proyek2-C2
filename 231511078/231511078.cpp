#include "231511078.h"

string list1 = "abcdefghiklmnopqrstuvwxyz"; 

void append(jawaban*& head, char data) {
    jawaban* newNode = new jawaban(data);
    if (!head) {
        head = newNode;
        return;
    }
    jawaban* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void appendMatrixNode(MatrixNode*& head, char data) {
    MatrixNode* newNode = new MatrixNode(data);
    if (!head) {
        head = newNode;
        return;
    }
    MatrixNode* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void generateKeyTable(jawaban* key, MatrixNode*& table) {
    jawaban* temp = key;
    while (temp) {
        bool flag = false;
        MatrixNode* mTemp = table;
        while (mTemp) {
            if (mTemp->data == temp->data) {
                flag = true;
                break;
            }
            mTemp = mTemp->next;
        }
        if (!flag) {
            appendMatrixNode(table, temp->data);
        }
        temp = temp->next;
    }
    for (char ch : list1) {
        bool flag = false;
        MatrixNode* mTemp = table;
        while (mTemp) {
            if (mTemp->data == ch) {
                flag = true;
                break;
            }
            mTemp = mTemp->next;
        }
        if (!flag) {
            appendMatrixNode(table, ch);
        }
    }
}

void findPosition(MatrixNode* table, char letter, int& row, int& col) {
    MatrixNode* temp = table;
    int index = 0;
    while (temp) {
        if (temp->data == letter) {
            row = index / 5;
            col = index % 5;
            return;
        }
        temp = temp->next;
        index++;
    }
}

char getCharAt(MatrixNode* table, int row, int col) {
    MatrixNode* temp = table;
    int index = 0;
    while (temp) {
        if (index == row * 5 + col) {
            return temp->data;
        }
        temp = temp->next;
        index++;
    }
    return '\0';
}

void fillDiagraph(jawaban*& head) {
    jawaban* temp = head; 
    jawaban* prev = nullptr; 
    int count = 0; 

    while (temp && temp->next) { 
        count++; 
        if (temp->data == temp->next->data) { 
            jawaban* newNode = new jawaban('z'); 
            newNode->next = temp->next; 
            temp->next = newNode; 
            prev = newNode; 
            temp = newNode->next; 
            count++; 
        } else {
            prev = temp; 
            temp = temp->next; 
        }
    }

    if (temp) {
        count++;
    }

    if (count % 2 != 0) {
        append(prev, 'z'); 
    }
}

void replaceJWithI(jawaban* head) {
    jawaban* temp = head; 
    while (temp != nullptr) { 
        if (temp->data == 'j') { 
            temp->data = 'i'; 
        }
        temp = temp->next; 
    }
}


void encryptByPlayfairCipher(MatrixNode* table, jawaban* plainText, jawaban*& cipherText) {
    jawaban* temp = plainText;
    while (temp && temp->next) {
        int row1, col1, row2, col2;
        findPosition(table, temp->data, row1, col1);
        findPosition(table, temp->next->data, row2, col2);
        if (row1 == row2) {
            append(cipherText, getCharAt(table, row1, (col1 + 1) % 5));
            append(cipherText, getCharAt(table, row2, (col2 + 1) % 5));
        } else if (col1 == col2) {
            append(cipherText, getCharAt(table, (row1 + 1) % 5, col1));
            append(cipherText, getCharAt(table, (row2 + 1) % 5, col2));
        } else {
            append(cipherText, getCharAt(table, row1, col2));
            append(cipherText, getCharAt(table, row2, col1));
        }
        temp = temp->next->next;
    }
}

jawaban* PlayfairCipher(jawaban* plaintext, jawaban* key) {
    replaceJWithI(key);

    replaceJWithI(plaintext);
    fillDiagraph(plaintext);

    MatrixNode* table = nullptr;
    generateKeyTable(key, table);

    jawaban* cipherText = nullptr;

    encryptByPlayfairCipher(table, plaintext, cipherText);
    return cipherText;
}
