#include "user.h"
#include "231511078/231511078.h"
#include "231511085/231511085.h"
#include "231511088/231511088.h"
#include "231511091/231511091.h"

int main()
{
    user loggedUser;

    do
    {
        loggedUser = loginDosen();
        if (loggedUser.nama == "")
        {
            cout << "Login gagal, silakan coba lagi." << endl;
        }
    } while (loggedUser.nama == "");

    string mataUjian;
    int jumlahSoal;
    jawaban *headKunjaw = NULL;
    jawaban *headKey = NULL;
    char choice;

    do
    {
        choice = dashboardDosen(loggedUser);
        switch (choice)
        {
        case '1':
            system("cls");
            cout << "Nama mata ujian: ";
            cin >> mataUjian;
            cout << "Jumlah soal: ";
            cin >> jumlahSoal;
            system("cls");
            buatSoal(mataUjian, jumlahSoal);
            buatKunjaw(&headKunjaw, mataUjian, jumlahSoal);
            toLowerCase(mataUjian);
            CaesarCipherEnkrip(headKunjaw, jumlahSoal);
            buatkey(mataUjian, headKey);
            CaesarCipherEnkrip(headKey, jumlahSoal);
            headKunjaw = PlayfairCipher(headKunjaw, headKey);
            createFile(headKunjaw, "dosen", mataUjian);
            system("pause");
            break;

        case '2':
            system("cls");
            break;

        default:
            cout << "---Karakter yang diinputkan tidak valid---" << endl;
            system("PAUSE");
            system("cls");
            break;
        }
    } while (choice == '1');

    while (headKunjaw != NULL && headKey != NULL)
    {
        delete headKunjaw;
        delete headKey;
        headKunjaw = headKunjaw->next;
        headKey = headKey->next;
    }
    return 0;
}