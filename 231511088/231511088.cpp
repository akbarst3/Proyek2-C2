#include "231511088.h"

char dashboardDosen(user dosen)
{
    system("cls");
    char answer;
    cout << "------------------------------\n";
    cout << "|       DASHBOARD DOSEN      |\n";
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
    ujian *head = NULL;
    soalBaru(&head, jumlahSoal);
    cin.ignore();
    simpanKeFile(head, mataUjian, jumlahSoal);
    // Bebaskan memori
    while (head != NULL)
    {
        ujian *temp = head;
        head = head->next;
        delete temp;
    }
}

void toUpperCase(string *str)
{
    transform(str->begin(), str->end(), str->begin(), ::toupper);
}

void soalBaru(ujian **head, int jumlahSoal)
{
    for (int i = 0; i < jumlahSoal; i++)
    {
        cin.ignore();
        ujian *soal = new ujian();
        soal->next = NULL;
        soal->opsi = NULL;
        cout << i + 1 << ". ";
        getline(cin, soal->pertanyaan);

        jawaban *headOpsi = NULL;
        jawaban *lastOpsi = NULL;
        for (int j = 0; j < 4; j++)
        {
            jawaban *opsiJawab = (jawaban*)malloc(sizeof(jawaban));
            opsiJawab->next = NULL;
            cout << " " << char('a' + j) << ". ";
            cin >> opsiJawab->data;

            if (headOpsi == NULL)
            {
                headOpsi = opsiJawab;
            }
            else
            {
                lastOpsi->next = opsiJawab;
            }
            lastOpsi = opsiJawab;
        }
        soal->opsi = headOpsi;

        if (*head == NULL)
        {
            *head = soal;
        }
        else
        {
            ujian *temp = *head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = soal;
        }
    }
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
            jawaban *tempOpsi = temp->opsi;
            int j = 0;
            while (tempOpsi != NULL)
            {
                file << " " << char('A' + j) << ". " << tempOpsi->data << endl;
                tempOpsi = tempOpsi->next;
                j++;
            }
            file << "\n";
            temp = temp->next;
            i++;
        }
        file.close();
        cout << "Soal telah disimpan ke dalam folder-soal dengan nama file '" << namaFile << ".txt'" << endl;
    }
    else
    {
        cout << "Gagal membuka file untuk penyimpanan." << endl;
    }
}

void buatKunjaw(jawaban *headKunjaw, string mataUjian, int jumlahSoal)
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
        bool valid = 0;
        for (char c : format)
        {
            if (temp == c)
            {
                kunjaw->data = temp;
                valid = 1;
            }
        }
        if (!valid)
        {
            cout << "Input salah! (a/b/c/d)" << endl;
            continue;
        }
        else
        {
            nomor++;
        }

        if (headKunjaw == NULL)
        {
            headKunjaw = kunjaw;
        }
        else
        {
            jawaban *temp = headKunjaw;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = kunjaw;
        }
    }
}