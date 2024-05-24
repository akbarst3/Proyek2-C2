#include "user.h"
#include "231511078/231511078.h"
#include "231511085/231511085.h"
#include "231511088/231511088.h"
#include "231511091/231511091.h"

int main()
{
    user loggedUser;
    string mataUjian;
    int jumlahSoal;
    char choice;

    do
    {
        loggedUser = loginDosen();
        if (loggedUser.nama == "")
        {
            cout << "Login gagal, silakan coba lagi." << endl;
        }
        else
        {
            do
            {
                jawaban *headKunjaw = NULL;
                jawaban *headKey = NULL;
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
                    toUpperCase(&mataUjian);
                    createFile(headKunjaw, "dosen", mataUjian);
                    system("pause");
                    break;

                case '2':
                    loggedUser.nama = "";
                    system("cls");
                    break;

                default:
                    cout << "---Karakter yang diinputkan tidak valid---" << endl;
                    choice = '1';
                    system("pause");
                    system("cls");
                    break;
                    freeMemory(&headKey);
                    freeMemory(&headKunjaw);
                }
            }while (choice != '2');
        }
    } while (loggedUser.nama == "");
    return 0;
}
