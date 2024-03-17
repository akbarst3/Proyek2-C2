#include "231511078.h"
const string list1 = "abcdefghiklmnopqrstuvwxyz";

void removeSpaces(string& str) {
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
}

void toLowerCase(string& str) {
    for (char& ch : str) {
        if (isupper(ch)) {
            ch = tolower(ch);
        }
    }
}

void fillDiagraph(string& str) {
    for (size_t i = 0; i < str.length(); i += 2) {
        if (i + 1 == str.length() || str[i] == str[i + 1]) {
            str.insert(i + 1, "z");
        }
    }
}

void generateKeyTable(const string& key, string& table) {
    table = key;
    for (char ch : list1) {
        if (table.find(ch) == string::npos) {
            table += ch;
        }
    }
}

void encryptByPlayfairCipher(const string& table, const string& plainText, string& cipherText) {
    cipherText = "";
    for (size_t i = 0; i < plainText.length(); i += 2) {
        char ch1 = plainText[i];
        char ch2 = (i + 1 < plainText.length()) ? plainText[i + 1] : 'x';

        size_t pos1 = table.find(ch1);
        size_t pos2 = table.find(ch2);

        size_t row1 = pos1 / 5;
        size_t col1 = pos1 % 5;
        size_t row2 = pos2 / 5;
        size_t col2 = pos2 % 5;

        if (row1 == row2) {
            cipherText += table[row1 * 5 + (col1 + 1) % 5];
            cipherText += table[row2 * 5 + (col2 + 1) % 5];
        } else if (col1 == col2) {
            cipherText += table[((row1 + 1) % 5) * 5 + col1];
            cipherText += table[((row2 + 1) % 5) * 5 + col2];
        } else {
            cipherText += table[row1 * 5 + col2];
            cipherText += table[row2 * 5 + col1];
        }
    }
}

void printMatrix(const string& table) {
    for (size_t i = 0; i < table.length(); ++i) {
        cout << table[i] << " ";
        if ((i + 1) % 5 == 0) {
            cout << endl;
        }
    }
}
