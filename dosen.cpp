#include "user.h"
#include "231511078/231511078.h"
#include "231511085/231511085.h"
#include "231511088/231511088.h"
#include "231511091/231511091.h"

int main()
{
    user loggedUser = loginDosen();
    char choice;
    if (loggedUser.nama == "")
    {
        cout << "Login gagal" << endl;
        main();
    }
    else
    {
        string mataUjian;
        int jumlahSoal;
        jawaban *headKunjaw;
        jawaban *headkey;
        choice = dashboard(loggedUser);
        for (;;)
        {
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
                buatKunjaw(headKunjaw, mataUjian, jumlahSoal);
                toLowerCase(mataUjian);
                CaesarCipherEnkrip(headKunjaw, jumlahSoal);
                buatkey (mataUjian, headkey);
                CaesarCipherEnkrip(headkey, jumlahSoal);
                deleteSameChar(headkey);
                headKunjaw = PlayfairCipher(headKunjaw, headkey);
                createFile(headKunjaw, mataUjian, "dosen");
                break;
            case '2':
                system("cls");
                break;
            default:
                cout << "---Karakter yang diinputkan tidak valid---" << endl;
                system("cls");
            }
            if (choice != 1)
            {
                break;
            }
        }
    }
}