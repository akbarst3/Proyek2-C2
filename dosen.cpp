#include "user.h"
#include "231511085/231511085.h"
#include "231511088/231511088.h"

int main()
{
    user loggedUser = loginDosen();
    char choice = dashboard(loggedUser);
    string mataUjian;
    int jumlahSoal;
    ujian *soalBaru;
    switch (choice)
    {
    case '1':
        system("cls");
        cout << "Nama mata ujian: ";
        cin >> mataUjian;
        cout << "Jumlah soal: ";
        cin >> jumlahSoal;
        soalBaru = new ujian[jumlahSoal]; // alokasi memori
        buatSoal(mataUjian, jumlahSoal, soalBaru);
        break;
    case '2':
        system("cls");
        main();
        break;
    default:
        cout << "---Karakter yang diinputkan tidak valid---" << endl;
        system("cls");
        main();
    }
    
}