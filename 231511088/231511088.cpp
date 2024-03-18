#include "231511088.h"

char dashboard(user dosen)
{
    system("cls");
    char answer;
    // Tampilkan dashboard
    cout << "------------------------------\n";
    cout << "|                            |\n";
    cout << "|       DASHBOARD DOSEN      |\n";
    cout << "|                            |\n";
    cout << "------------------------------\n";
    cout << "Selamat datang di dasbor dosen" << endl;
    cout << dosen.nama << endl;
    cout << dosen.id << endl;
    cout << "------------------------------" << endl;
    cout << "(1) Buat soal" << endl;
    cout << "(2) Logout" << endl;
    cin >> answer;
    return answer;
}

void toUpperCase(string *str)
{
    transform(str->begin(), str->end(), str->begin(), ::toupper);
}

void buatSoal(string *mataUjian, int jumlahSoal, ujian *soalBaru)
{
    toUpperCase(*(&mataUjian));
    cout << "-------------------------------------------------\n";
    cout << "     UJIAN " << *mataUjian << '\n';
    cout << "-------------------------------------------------\n";
    cin.ignore();

    for (int i = 0; i < jumlahSoal; i++)
    {
        cout << i + 1 << ". ";
        getline(cin, soalBaru[i].pertanyaan);
        for (int j = 0; j < 4; j++)
        {
            cout << " " << char('a' + j) << ". ";
            getline(cin, soalBaru[i].jawaban[j]);
        }
        cout << endl
             << endl;
    }
    simpanKeFile(soalBaru, *mataUjian, jumlahSoal);
}

void simpanKeFile(ujian *soalBaru, string namaFile, int jumlahSoal)
{
    ofstream file("assets/folder-soal/" + namaFile + ".txt");
    if (file.is_open())
    {
        for (int i = 0; i < jumlahSoal; i++)
        {
            file << i + 1 << ". " << soalBaru[i].pertanyaan << endl;
            for (int j = 0; j < 4; j++)
            {
                file << " " << char('A' + j) << ". " << soalBaru[i].jawaban[j] << " ";
            }
            file << endl
                 << endl;
        }
        file.close();
        cout << "Soal telah disimpan ke dalam folder-soal dengan nama file '" << namaFile << ".txt'" << endl;
    }
    else
    {
        cout << "Gagal membuka file untuk penyimpanan." << endl;
    }
}

void buatKunjaw(string *kunjaw, string mataUjian, int jumlahSoal)
{
    char temp;
    string format = "abcd";
    cout << "Buat Kunci Jawaban " << mataUjian
         << " (a/b/c/d)" << endl;
    int soal = 1;
    while (soal <= jumlahSoal)
    {
        cout << soal << ". ";
        cin >> temp;
        bool valid = 0;
        for (char c : format)
        {
            if (temp == c)
            {
                *kunjaw += temp;
                valid = 1;
            }
        }
        if (!valid)
        {
            cout << "Input salah! (a/b/c/d)" << endl;
        } else {
            soal++;
        }
    }
}