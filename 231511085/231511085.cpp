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

void bacafile(string path, jawaban *&headkunjaw)
{
    ifstream bacaFile(path);
    if (bacaFile.is_open())
    {
        string temp;
        while (getline(bacaFile, temp))
        {
            jawaban *nodejwb = new jawaban;
            nodejwb->opsiJwb = temp;
            nodejwb->next = NULL;
            if (headkunjaw == NULL)
            {
                headkunjaw = nodejwb;
            }
            else
            {
                jawaban *temp = headkunjaw;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = nodejwb;
            }
        }
        bacaFile.close();
    }
    else
    {
        cout << "Gagal membuka file kunci jawaban." << endl;
        return;
    }
}

void nilai(jawaban *headKunjaw, jawaban *headJawab)
{
    jawaban *tempKunjaw = headKunjaw;
    jawaban *tempJawab = headJawab;
    int jumlahSoal = 0;
    while (tempKunjaw != NULL)
    {
        jumlahSoal++;
        tempKunjaw = tempKunjaw->next;
    }
    int poin = 100 / jumlahSoal;
    int nilai = 0;
    tempKunjaw = headKunjaw; // Reset tempKunjaw to start

    for (int i = 0; i < jumlahSoal && tempJawab != NULL && tempKunjaw != NULL; i++)
    {
        if (tempKunjaw->opsiJwb == tempJawab->opsiJwb)
        {
            nilai += poin;
        }
        tempKunjaw = tempKunjaw->next;
        tempJawab = tempJawab->next;
    }
    cout << "nilai anda : " << nilai << endl;
}

string getTopik(string path)
{
    size_t pos = path.find_last_of('/'); // Mencari posisi terakhir dari '/'
    if (pos == string::npos)
    {
        return path; // Jika '/' tidak ditemukan, kembalikan path asli
    }
    else
    {
        return path.substr(pos + 1); // Kembalikan string setelah karakter '/'
    }
}
