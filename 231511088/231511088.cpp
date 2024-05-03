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

void buatSoal(string mataUjian, int jumlahSoal)
{
    toUpperCase(&mataUjian);
    cout << "-------------------------------------------------\n";
    cout << "     UJIAN " << mataUjian << '\n';
    cout << "-------------------------------------------------\n";
    ujian *head;
    soalBaru(head, jumlahSoal);
    cin.ignore();
    simpanKeFile(head, mataUjian, jumlahSoal);
}

void toUpperCase(string *str)
{
    transform(str->begin(), str->end(), str->begin(), ::toupper);
}

void soalBaru(ujian *head, int jumlahSoal)
{
    opsi *headOpsi;
    for (int i = 0; i < jumlahSoal; i++)
    {
        ujian *soal = (ujian *)malloc(sizeof(ujian));
        if (soal == NULL)
        {
            cout << "Memori Full\n";
            return;
        }
        soal->next = NULL;
        cout << i + 1 << ". ";
        getline(cin, soal->pertanyaan);
        for (int j = 0; j < 4; j++)
        {
            opsi *jawaban = (opsi *)malloc(sizeof(opsi));
            if (jawaban == NULL)
            {
                cout << "Memori Full\n";
                return;
            }
            jawaban->next = NULL;
            cout << " " << char('a' + j) << ". ";
            getline(cin, jawaban->opsiJwb);
            if (headOpsi == NULL)
            {
                headOpsi = jawaban;
            }
            else
            {
                opsi *temp = headOpsi;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = jawaban;
            }
        }
        cout << "\n\n";
        if (head == NULL)
        {
            head = soal;
        }
        else
        {
            ujian *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = soal;
        }
    }
    head->opsi = headOpsi;
}

void simpanKeFile(ujian *head, string namaFile, int jumlahSoal)
{
    ofstream file("assets/folder-soal/" + namaFile + ".txt");
    ujian *temp = head;
    if (file.is_open())
    {
        int i = 0;
        while (temp != NULL)
        {
            file << i + 1 << ". " << temp->pertanyaan << endl;
            opsi *tempOpsi = temp->opsi;
            int j = 0;
            while (tempOpsi != NULL)
            {
                file << " " << char('A' + j) << ". " << tempOpsi->opsiJwb << " ";
                j++;
                tempOpsi = tempOpsi->next;
            }
            file << "\n\n";
            temp = temp->next;
        }
        file.close();
        cout << "Soal telah disimpan ke dalam folder-soal dengan nama file '" << namaFile << ".txt'" << endl;
    }
    else
    {
        cout << "Gagal membuka file untuk penyimpanan." << endl;
    }
}

void buatKunjaw(opsi *headKunjaw, string mataUjian, int jumlahSoal)
{
    char temp;
    string format = "abcd";
    toUpperCase(&mataUjian);
    cout << "Buat Kunci Jawaban " << mataUjian << "(a/b/c/d)\n";
    int nomor = 1;
    while (nomor <= jumlahSoal)
    {
        opsi *jawaban = (opsi *)malloc(sizeof(opsi));
        if (jawaban == NULL)
        {
            cout << "Memori Full\n";
            return;
        }
        jawaban->next = NULL;
        cout << nomor << ". ";
        cin >> temp;
        bool valid = 0;
        for (char c : format)
        {
            if (temp == c)
            {
                jawaban->opsiJwb = temp;
                valid = 1;
            }
        }
        if (!valid)
        {
            cout << "Input salah! (a/b/c/d)" << endl;
        }
        else
        {
            nomor++;
        }
        
        if (headKunjaw == NULL)
        {
            headKunjaw = jawaban;
        }
        else
        {
            opsi *temp = headKunjaw;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = jawaban;
        }
    }
}