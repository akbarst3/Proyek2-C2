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

// Fungsi untuk mencocokan data dengan jenis yang ditentukan (dosen atau mahasiswa)
bool login(const string& id, const string& password, const string& filename, const string& id_label) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            if (line.find(id_label + id) != string::npos) {
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

// Fungsi utama
int main() {
    string role;
    cout << "Anda akan registrasi sebagai (dosen/mahasiswa): ";
    cin >> role;

    if (role == "dosen" || role == "mahasiswa") {
        string id, password;
        string filename = (role == "dosen") ? "data_dosen.txt" : "data_mahasiswa.txt";
        string id_label = (role == "dosen") ? "NIP: " : "NIM: ";
        cout << "Masukkan " << ((role == "dosen") ? "NIP" : "NIM") << ": ";
        cin >> id;
        cout << "Masukkan password: ";
        cin >> password;

        if (login(id, password, filename, id_label)) {
            cout << "Login berhasil" << endl;
        } else {
            cout << "Login gagal. " << ((role == "dosen") ? "NIP" : "NIM") << " atau password salah." << endl;
        }
    } else {
        cout << "Peran yang dimasukkan tidak valid." << endl;
    }

    return 0;
}
