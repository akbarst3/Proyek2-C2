#include "231511078.h"

PlayfairCipher::PlayfairCipher(const std::string& key) : key(key) {
    prepareKey();
    prepareMatrix();
}

void PlayfairCipher::prepareKey() {
    std::string tempKey = key;
    std::transform(tempKey.begin(), tempKey.end(), tempKey.begin(), ::toupper);
    tempKey.erase(std::remove(tempKey.begin(), tempKey.end(), ' '), tempKey.end());
    std::string::iterator end_pos = std::unique(tempKey.begin(), tempKey.end());
    tempKey.erase(end_pos, tempKey.end());
    for (char ch = 'A'; ch <= 'Z'; ++ch) {
        if (ch == 'J') continue; 
        if (tempKey.find(ch) == std::string::npos) {
            tempKey.push_back(ch);
        }
    }
    if (tempKey.length() < 25) {
        for (char ch = 'A'; ch <= 'Z' && tempKey.length() < 25; ++ch) {
            if (ch == 'J') continue;
            if (tempKey.find(ch) == std::string::npos) {
                tempKey.push_back(ch);
            }
        }
    }
    this->key = tempKey.substr(0, 25);
}

void PlayfairCipher::prepareMatrix() {
    int k = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            matrix[i][j] = key[k++];
        }
    }
}

void PlayfairCipher::getCoordinates(char ch, int& row, int& col) {
    if (ch == 'J') ch = 'I';
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (matrix[i][j] == ch) {
                row = i;
                col = j;
                return;
            }
        }
    }
}

std::string PlayfairCipher::fixText(const std::string& text) {
    std::string result = text;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    for (char& ch : result) {
        if (!isalpha(ch)) {
            ch = ' ';
        } else if (ch == 'J') {
            ch = 'I';
        }
    }
    result.erase(std::remove(result.begin(), result.end(), ' '), result.end());
    if (result.length() % 2 != 0) {
        result.push_back('X');
    }
    return result;
}

std::string PlayfairCipher::encrypt(const std::string& plaintext) {
    std::string fixedText = fixText(plaintext);
    std::string ciphertext = "";
    for (size_t i = 0; i < fixedText.length(); i += 2) {
        char ch1 = fixedText[i];
        char ch2 = fixedText[i + 1];
        int row1, col1, row2, col2;
        getCoordinates(ch1, row1, col1);
        getCoordinates(ch2, row2, col2);
        if (row1 == row2) { 
            ciphertext += matrix[row1][(col1 + 1) % 5];
            ciphertext += matrix[row2][(col2 + 1) % 5];
        } else if (col1 == col2) { 
            ciphertext += matrix[(row1 + 1) % 5][col1];
            ciphertext += matrix[(row2 + 1) % 5][col2];
        } else { 
            ciphertext += matrix[row1][col2];
            ciphertext += matrix[row2][col1];
        }
    }
    return ciphertext; //coba
}
