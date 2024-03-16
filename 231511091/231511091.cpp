#include "231511091.h"

// Fungsi untuk melakukan enkripsi menggunakan Caesar Cipher dengan geser 

#include "231511091.h"


// Fungsi Caesar Cipher
string CaesarCipherEnkrip(const string plaintext, int shift) {
    string ciphertext = "";

    for (char c : plaintext) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = ((c - base) + shift) % 26 + base;
        }
        ciphertext = ciphertext + c + 'X';
    }

    return ciphertext;
}



