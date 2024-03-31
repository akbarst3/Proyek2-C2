#include "231511085.h"

user login(const string &id, const string &password, const string &users)
{
    string filename = "assets/folder-users/";
    if (users == "dosen" || users == "mhs")
    {
        filename += (users == "dosen") ? "data_dosen.txt" : "data_mhs.txt";
    }

    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Database file tidak ditemukan atau tidak bisa dibuka.\n";
        return {};
    }

    string line;
    user currentUser;
    bool idMatch = false;
    while (getline(file, line))
    {
        if (line.find("id: " + id) != string::npos)
        {
            idMatch = true;
            // Check the password on the next line
            if (getline(file, line) && line.find("Password: " + password) != string::npos)
            {
                // Password matches, read the name
                if (getline(file, line) && line.find("Nama: ") != string::npos)
                {
                    // Found name
                    currentUser.id = id;
                    currentUser.nama = line.substr(6);
                    file.close();
                    return currentUser;
                }
            }
        }
    }
    file.close();

    if (idMatch)
        cerr << "Password salah.\n";
    else
        cerr << "ID tidak ditemukan.\n";

    return {};
}

user loginMhs()
{
    string nim, password, users = "mhs";
    cout << "------------------------------\n";
    cout << "|                            |\n";
    cout << "|       DASHBOARD LOGIN      |\n";
    cout << "|                            |\n";
    cout << "------------------------------\n";
    cout << "Masukkan NIM: ";
    cin >> nim;
    cout << "Masukkan Password: ";
    cin >> password;
    user userLogged = login(nim, password, users);
    return userLogged;
}

user loginDosen()
{
    string nip, password, users = "dosen";
    cout << "------------------------------\n";
    cout << "|                            |\n";
    cout << "|       DASHBOARD LOGIN      |\n";
    cout << "|                            |\n";
    cout << "------------------------------\n";
    cout << "Masukkan NIP: ";
    cin >> nip;
    cout << "Masukkan Password: ";
    cin >> password;
    user userLogged = login(nip, password, users);
    return userLogged;
}

Grader::Grader(const std::string& kunci_file, const std::string& jawaban_file) : poin(0) {
    bacaKunciJawaban(kunci_file);
    bacaJawabanPengguna(jawaban_file);
}

void Grader::runGrader() {
    periksaJawaban();
    tampilkanPoin();
}

void Grader::bacaKunciJawaban(const std::string& kunci_file) {
    std::ifstream kunciFile(kunci_file);

    if (kunciFile.is_open()) {
        std::string jawaban;
        while (getline(kunciFile, jawaban)) {
            kunci_jawaban.push_back(jawaban);
        }
        kunciFile.close();
    } else {
        std::cout << "Gagal membuka file kunci jawaban." << std::endl;
    }
}

void Grader::bacaJawabanPengguna(const std::string& jawaban_file) {
    std::ifstream jawabanFile(jawaban_file);

    if (jawabanFile.is_open()) {
        std::string jawaban;
        while (getline(jawabanFile, jawaban)) {
            jawaban_pengguna.push_back(jawaban);
        }
        jawabanFile.close();
    } else {
        std::cout << "Gagal membuka file jawaban pengguna." << std::endl;
    }
}

void Grader::periksaJawaban() {
    if (kunci_jawaban.size() == jawaban_pengguna.size()) {
        for (size_t i = 0; i < kunci_jawaban.size(); ++i) {
            if (kunci_jawaban[i] == jawaban_pengguna[i]) {
                poin += 10;
                std::cout << "Jawaban untuk soal " << (i+1) << " benar!" << std::endl;
            } else {
                std::cout << "Jawaban untuk soal " << (i+1) << " salah!" << std::endl;
            }
        }
    } else {
        std::cout << "Jumlah soal dalam kunci jawaban dan jawaban pengguna tidak sama." << std::endl;
    }
}

void Grader::tampilkanPoin() {
    std::cout << "Total poin: " << poin << std::endl;
}
