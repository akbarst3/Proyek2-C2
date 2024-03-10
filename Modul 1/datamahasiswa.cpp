#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// fungsi buat generate password
/**password diambil dari character yang ada*/
string generatePassword(int length) {
    string password = "";
    const string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";//ini characthernya
    int charLength = characters.length();

    srand(time(0));

    for (int i = 0; i < length; ++i) {
        password += characters[rand() % charLength];
    }

    return password;
}

int main() {
    int mhsEntries;

    cout << "Masukkan jumlah Mhasiswaa yang mengikuti ujian: ";
    cin >> mhsEntries;
    cin.ignore(); // Clear input buffer

    ofstream outFile("data_mhs.txt", ios::app); // Open file struct

    for (int i = 0; i < mhsEntries; ++i) {
        string nama, nim;

        cout << "\nMasukkan Nama: ";
        getline(cin, nama);

        cout << "Masukkan NIM: ";
        getline(cin, nim);

        // manggil fungsi password dan bikin password
        string password = generatePassword(8);

        // input nama nim 
        string data = "Nama: " + nama + "\nNIM: " + nim + "\nPassword: " + password + "\n\n";

        // masuk data ke file
        if (outFile.is_open()) {
            outFile << data;
            cout << "Data berhasil ditambahkan." << endl;
        } else {
            cout << "Gagal membuka file." << endl;
            return 1;
        }
    }

    outFile.close(); // tutup file

    return 0;
}
