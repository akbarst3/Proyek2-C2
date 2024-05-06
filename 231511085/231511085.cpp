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

