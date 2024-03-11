#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <cctype>
#include <algorithm>

using namespace std;

struct pengajar
{
    string nama;
    string nip;
    string password;
};

struct ujian
{
    string pertanyaan;
    string jawaban[4];
};

// PROTOTYPE MODUL
char dashboard(struct pengajar dosen);
ujian *buatSoal(string mataUjian, int jumlahSoal);
string toUpperCase(string str);
void simpanKeFile(const ujian *soalBaru, int jumlahSoal, const string &namaFile, const string &folderPath);

int main()
{
    struct pengajar dosen;
    dosen.nama = "jonner h";
    dosen.nip = "221511088";
    dosen.password = "123456";

    char answer;
    do
    {
        answer = dashboard(dosen);
        if (answer == 'y')
        {
            string mataUjian;
            cout << "Input nama mata ujian : ";
            cin >> mataUjian;
            int jumlahSoal;
            cout << "Jumlah soal : ";
            cin >> jumlahSoal;
            ujian *soalBaru = buatSoal(mataUjian, jumlahSoal);
            string folderPath = "../Assets/folder-soal";

            // Simpan soalBaru ke dalam file
            string namaFile = toUpperCase(mataUjian) + ".txt";
            simpanKeFile(soalBaru, jumlahSoal, namaFile, folderPath);

            // Tampilkan soalBaru (opsional)
            for (int i = 0; i < jumlahSoal; i++)
            {
                cout << i + 1 << ". ";
                cout << soalBaru[i].pertanyaan;
                for (int j = 0; j < 4; j++)
                {
                    cout << " " << char('A' + j) << ". " << soalBaru[i].jawaban[j];
                }
                cout << endl;
            }

            delete[] soalBaru;
        }
    } while (answer == 'n');

    return 0;
}

char dashboard(struct pengajar dosen)
{
    char answer;

    // Tampilkan dashboard
    cout << "------------------------------\n";
    cout << "|                            |\n";
    cout << "|       DASHBOARD DOSEN      |\n";
    cout << "|                            |\n";
    cout << "------------------------------\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Halo, " << dosen.nama << endl;
    cout << "Selamat datang di dasbor dosen" << endl;
    cout << "------------------------------" << endl;
    this_thread::sleep_for(chrono::seconds(1));

    cout << "Buat soal? (y/n)" << endl;
    dsgffrger
    cin >> answer;
    system("cls");

    return answer;
}

ujian *buatSoal(string mataUjian, int jumlahSoal)
{
    struct ujian *soalBaru = new ujian[jumlahSoal];

    cout << "-------------------------------------------------\n";
    cout << "     UJIAN " << toUpperCase(mataUjian) << '\n';
    cout << "-------------------------------------------------\n";
    this_thread::sleep_for(chrono::seconds(1));

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
        cout << endl;
    }

    return soalBaru;
}

string toUpperCase(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

void simpanKeFile(const ujian *soalBaru, int jumlahSoal, const string &namaFile, const string &folderPath)
{
    ofstream file(folderPath + "/" + namaFile);
    if (file.is_open())
    {
        for (int i = 0; i < jumlahSoal; i++)
        {
            file << i + 1 << ". " << soalBaru[i].pertanyaan << endl;
            for (int j = 0; j < 4; j++)
            {
                file << " " << char('A' + j) << ". " << soalBaru[i].jawaban[j] << endl;
            }
            file << endl;
        }
        file.close();
        cout << "Soal telah disimpan ke dalam folder-soal dengan nama file '" << namaFile << "'" << endl;
    }
    else
    {
        cout << "Gagal membuka file untuk penyimpanan." << endl;
    }
}
