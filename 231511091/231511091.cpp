#include "231511091.h"
#

// Fungsi Caesar Cipher
void CaesarCipherEnkrip(string &plaintext, int shift) {

    string cipher = "";
    string add = "x";
    for (char c : plaintext) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = ((c - base) + shift) % 26 + base;
        }
        cipher += c + add;
    }
    plaintext = cipher;

}

void createFile(string hasilEnkrip, string namaFile, string user) {
    string path;
    if(user == "dosen"){
        path = "assets/folder-kunci-jawaban/";
        namaFile = "kunjaw" + namaFile;
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
