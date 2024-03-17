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

void createFile(string hasilEnkrip, string namaFile, string user) {
    string path;
    if(user == "dosen"){
        path = "assets/folder-kunci-jawaban/";
    } else {
        path  = "assets/folder-jawab-mhsw/";
    }
    ofstream file( path + namaFile + ".txt");
    if (file.is_open()) {
        file << hasilEnkrip;
        file.close();
        cout << "File berhasil dibuat!\n";
    } else {
        cerr << "File gagal dibuat!\n";
    }
}

