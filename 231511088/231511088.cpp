#include "231511088.h"

char dashboardDosen(user dosen)
{
    system("cls");
    char answer;
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
    soalBaru *head = NULL;
    tulisSoal(&head, jumlahSoal);
    cin.ignore();
    simpanKeFile(head, mataUjian, jumlahSoal);
    system("pause");
    // Bebaskan memori
    while (head != NULL)
    {
        soalBaru *temp = head;
        head = head->next;
        delete temp;
    }
}

void toUpperCase(string *str)
{
    transform(str->begin(), str->end(), str->begin(), ::toupper);
}

void tulisSoal(soalBaru **head, int jumlahSoal)
{
    cin.ignore();
    for (int i = 0; i < jumlahSoal; i++)
    {
        soalBaru *soal = new soalBaru();
        soal->next = NULL;
        soal->opsi = NULL;
        cout << i + 1 << ". ";
        getline(cin, soal->pertanyaan);

        opsiJawaban *headOpsi = NULL;
        opsiJawaban *lastOpsi = NULL;
        for (int j = 0; j < 4; j++)
        {
            opsiJawaban *opsi = new opsiJawaban();
            opsi->next = NULL;
            cout << " " << char('a' + j) << ". ";
            getline(cin, opsi->data);

            if (headOpsi == NULL)
            {
                headOpsi = opsi;
            }
            else
            {
                lastOpsi->next = opsi;
            }
            lastOpsi = opsi;
        }
        soal->opsi = headOpsi;

        if (*head == NULL)
        {
            *head = soal;
        }
        else
        {
            soalBaru *temp = *head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = soal;
        }
        if (i < jumlahSoal - 1)
        {
            cout << endl;
        }
    }
}

void simpanKeFile(soalBaru *head, string namaFile, int jumlahSoal)
{
    ofstream file("assets/folder-soal/" + namaFile + ".txt");
    soalBaru *temp = head;
    if (file.is_open())
    {
        int i = 0;
        while (temp != NULL)
        {
            file << i + 1 << ". " << temp->pertanyaan << endl;
            opsiJawaban *tempOpsi = temp->opsi;
            int j = 0;
            while (tempOpsi != NULL)
            {
                file << " " << char('A' + j) << ". " << tempOpsi->data << " ";
                tempOpsi = tempOpsi->next;
                j++;
            }
            file << "\n\n";
            temp = temp->next;
            i++;
        }
        file.close();
        cout << "Soal telah disimpan ke dalam folder-soal dengan nama file '" << namaFile << ".txt'" << endl
             << endl;
    }
    else
    {
        cout << "Gagal membuka file untuk penyimpanan." << endl;
    }
}

void buatKunjaw(jawaban **headKunjaw, string mataUjian, int jumlahSoal)
{
    char temp;
    string format = "abcd";
    toUpperCase(&mataUjian);
    cout << "Buat Kunci Jawaban " << mataUjian << "(a/b/c/d)\n";
    int nomor = 1;
    while (nomor <= jumlahSoal)
    {
        jawaban *kunjaw = (jawaban *)malloc(sizeof(jawaban));
        kunjaw->next = NULL;
        cout << nomor << ". ";
        cin >> temp;
        bool valid = false;
        for (char c : format)
        {
            if (temp == c)
            {
                kunjaw->data = temp;
                valid = true;
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

        if (*headKunjaw == NULL)
        {
            *headKunjaw = kunjaw;
        }
        else
        {
            jawaban *temp = *headKunjaw;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = kunjaw;
        }
    }
}

void freeMemory(jawaban **head)
{
    while (*head != NULL)
    {
        jawaban *temp = *head;
        *head = (*head)->next;
        delete temp;
    }
}
