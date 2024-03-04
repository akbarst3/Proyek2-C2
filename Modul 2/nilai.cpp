#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Membaca kunci jawaban dari file
    vector<string> kunci_jawaban;
    ifstream kunciFile("../folder-kunci-jawaban/kunjawPTIK.txt");

    if (kunciFile.is_open()) {
        string jawaban;
        while (getline(kunciFile, jawaban)) {
            kunci_jawaban.push_back(jawaban);
        }
        kunciFile.close();
    } else {
        cout << "Gagal membuka file kunci jawaban." << endl;
        return 1;
    }

    // Membaca jawaban pengguna dari file
    vector<string> jawaban_pengguna;
    ifstream jawabanFile("jawaban_pengguna.txt");

    if (jawabanFile.is_open()) {
        string jawaban;
        while (getline(jawabanFile, jawaban)) {
            jawaban_pengguna.push_back(jawaban);
        }
        jawabanFile.close();
    } else {
        cout << "Gagal membuka file jawaban pengguna." << endl;
        return 1;
    }

    // Memeriksa kebenaran jawaban dan memberikan poin
    int poin = 0;
    if (kunci_jawaban.size() == jawaban_pengguna.size()) {
        for (size_t i = 0; i < kunci_jawaban.size(); ++i) {
            if (kunci_jawaban[i] == jawaban_pengguna[i]) {
                poin += 10;
                cout << "Jawaban untuk soal " << (i+1) << " benar!" << endl;
            } else {
                cout << "Jawaban untuk soal " << (i+1) << " salah!" << endl;
            }
        }
    } else {
        cout << "Jumlah soal dalam kunci jawaban dan jawaban pengguna tidak sama." << endl;
        return 1;
    }

    // Menampilkan total poin
    cout << "Total poin: " << poin << endl;

    return 0;
}