/*Struct Untuk menginput data dosen dan membuat Password*/
//nanti akan berbentuk fil txt

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// fungsi untuk membuat password di generate dari string yang sudah tertera
string generatePassword(int length) {
    string password = "";
    const string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int charLength = characters.length();

    srand(time(0));

    for (int i = 0; i < length; ++i) {
        password += characters[rand() % charLength];
    }

    return password;
}

int main() {
    int dosenEntries;

    cout << "Masukkan jumlah Dosen yang ingin ditambahkan: ";
    cin >> dosenEntries;
    cin.ignore(); // Clear input buffer

    ofstream outFile("data_dosen.txt", ios::app); // Buka file untuk menulis

    for (int i = 0; i < dosenEntries; ++i) {
        string nama, nip;

        cout << "\nMasukkan Nama Dosen: ";
        getline(cin, nama);

        cout << "Masukkan NIP Dosen: ";
        getline(cin, nip);

        // generate password
        string password = generatePassword(8);

        // Format data sesuai permintaan
        string data = "Nama: " + nama + "\nNIP: " + nip + "\nPassword: " + password + "\n\n";

        // Simpan data ke dalam file
        if (outFile.is_open()) {
            outFile << data;
            cout << "Data berhasil ditambahkan." << endl;
        } else {
            cout << "Gagal membuka file." << endl;
            return 1;
        }
    }

    outFile.close(); // Tutup file

    return 0;
}
