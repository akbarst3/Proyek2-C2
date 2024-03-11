#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Fungsi untuk membuat matriks Playfair Cipher berdasarkan kunci
vector<vector<char>> generatePlayfairMatrix(const string& key) {
    string alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ"; // Abjad Playfair kecuali 'J'

    // Gabungkan kunci dengan abjad Playfair dan hapus karakter duplikat
    string key_alphabet = key + alphabet;
    key_alphabet.erase(remove_if(key_alphabet.begin(), key_alphabet.end(),
                                  [](char c) { return !isalpha(c); }),
                       key_alphabet.end());
    key_alphabet.erase(remove(key_alphabet.begin(), key_alphabet.end(), 'J'), key_alphabet.end());
    key_alphabet.erase(unique(key_alphabet.begin(), key_alphabet.end()), key_alphabet.end());

    // Buat matriks 5x5 untuk Playfair Cipher
    vector<vector<char>> matrix(5, vector<char>(5));

    // Isi matriks dengan karakter-karakter dari key_alphabet
    int index = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            matrix[i][j] = key_alphabet[index++];
        }
    }

    return matrix;
}

// Fungsi untuk melakukan enkripsi Playfair Cipher
string playfairCipherEncrypt(const string& plaintext, const string& key) {
    // Buat matriks Playfair Cipher berdasarkan kunci
    vector<vector<char>> matrix = generatePlayfairMatrix(key);

    // Implementasi enkripsi Playfair Cipher
    // (Anda perlu menambahkan logika untuk mengambil pasangan karakter dan menggantinya)

    // Kembalikan hasil enkripsi
    return plaintext; // Implementasi sebenarnya akan memproses plaintext dan mengembalikan ciphertext
}

int main() {
    string jawaban, kunci;

    // Input jawaban dan kunci dari pengguna
    cout << "Masukkan jawaban: ";
    getline(cin, jawaban);
    cout << "Masukkan kunci (nama mahasiswa): ";
    getline(cin, kunci);

    // Lakukan enkripsi menggunakan Playfair Cipher
    string hasil_enkripsi = playfairCipherEncrypt(jawaban, kunci);

    // Simpan hasil enkripsi ke dalam file dengan nama "NIM.TXT"
    ofstream outfile("NIM.TXT");
    if (outfile.is_open()) {
        outfile << hasil_enkripsi;
        outfile.close();
        cout << "Enkripsi selesai. Hasil disimpan dalam file NIM.TXT" << endl;
    } else {
        cerr << "Gagal menyimpan hasil enkripsi dalam file." << endl;
        return 1;
    }

    return 0;
}
