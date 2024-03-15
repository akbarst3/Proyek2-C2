#include "231511091.h"

// Fungsi untuk melakukan enkripsi menggunakan Caesar Cipher dengan geser 

string CaesarCipherEnkrip(string plaintext[]) {
    string ciphertext = "";
    for (int i = 0; i < sizeof(plaintext) / sizeof(plaintext[0]); ++i) {
        string word = plaintext[i];
        for (char& c : word) {
            if (isalpha(c)) {
                if (islower(c)) {
                    c = 'a' + (c - 'a' + 3) % 26;
                } else {
                    c = 'A' + (c - 'A' + 3) % 26;
                }
            }
            ciphertext += c;
        }
        if (i != sizeof(plaintext) / sizeof(plaintext[0]) - 1) {
            ciphertext += " ";
        }
    }
    return ciphertext;
}

string jawaban[5];


int main (){
    for (int i = 0; i < 5; i++)
    {
         jawaban[i] += 'X';
    }
    

    
}


