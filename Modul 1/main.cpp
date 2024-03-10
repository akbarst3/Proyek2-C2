#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Format data dosen
struct Dosen {
    string nama;
    string NIP;
    string password;
};

// Format data mahasiswa
struct Mahasiswa {
    string nama;
    string NIM;
    string password;
};

// Untuk mencocokan data dosen
bool loginDosen(const string& NIP, const string& password) {
    ifstream file("data_dosen.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            if (line.find("NIP: " + NIP) != string::npos) {
                getline(file, line); // Baca password
                if (line.find("Password: " + password) != string::npos) {
                    file.close();
                    return true;
                }
            }
        }
        file.close();
    }
    return false;
}

// Untuk mencocokan data mahasiswa
bool loginMahasiswa(const string& NIM, const string& password) {
    ifstream file("data_mahasiswa.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            if (line.find("NIM: " + NIM) != string::npos) {
                getline(file, line); // Baca password
                if (line.find("Password: " + password) != string::npos) {
                    file.close();
                    return true;
                }
            }
        }
        file.close();
    }
    return false;
}
// Sebelumnya udah punya 2 file teks yang berisi data dosen dan mahasiswa jadi dibaca disisni

// buat login bakal ditanya dulu akan login sebagai apa
int main() {
    string role;
    cout << "Anda akan registrasi sebagai (dosen/mahasiswa): ";
    cin >> role;

// ini kalau dosen
    if (role == "dosen") {
        string NIP, password;
        cout << "Masukkan NIP: ";
        cin >> NIP;
        cout << "Masukkan password: ";
        cin >> password;

        if (loginDosen(NIP, password)) {
            cout << "Login berhasil" << endl;
        } else {
            cout << "Login gagal. NIP atau password salah." << endl;
        }

// ini kalau mahasiswa
    } else if (role == "mahasiswa") {
        string NIM, password;
        cout << "Masukkan NIM: ";
        cin >> NIM;
        cout << "Masukkan password: ";
        cin >> password;

        if (loginMahasiswa(NIM, password)) {
            cout << "Login berhasil" << endl;
        } else {
            cout << "Login gagal. NIM atau password salah." << endl;
        }
    } else {
        cout << "Peran yang dimasukkan tidak valid." << endl; //ini kalau masukin selain dosen atau mahasiswa
    }

    return 0;
}
