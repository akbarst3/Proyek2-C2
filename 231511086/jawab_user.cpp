#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Fungsi untuk menampilkan soal dari file teks
void displayQuestion(const string& filename) {
    ifstream file(filename.c_str()); // Mengonversi string ke const char*
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "File tidak dapat dibuka." << endl;
    }
}

int main() {
    string soalFilename = "../Assets/folder-soal/PTIK.txt";
    string jawabanFilename = "../Assets/folder-jawab-mhsw/jawaban_mhsw.txt";

    // Menampilkan soal dari file teks
    displayQuestion(soalFilename);

    // Membuka file jawaban untuk penulisan
    ofstream jawabanFile(jawabanFilename.c_str(), ios::trunc); // Mengonversi string ke const char*
    if (!jawabanFile.is_open()) {
        cout << "Gagal membuka file jawaban." << endl;
        return 1;
    }

    // Meminta jawaban dari pengguna dan menyimpannya dalam file jawaban_mhsw.txt
    for (int i = 1; i <= 5; ++i) {
        char jawaban;
        cout << "Jawaban Anda untuk soal " << i << " (a/b/c/d): ";
        cin >> jawaban;

        jawabanFile << jawaban << endl;
    }

    cout << "Jawaban Anda berhasil disimpan dalam file " << jawabanFilename << endl;

    // Menutup file jawaban
    jawabanFile.close();

    return 0;
}

