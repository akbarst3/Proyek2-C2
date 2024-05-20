#include "user.h"
#include "231511078/231511078.h"
#include "231511085/231511085.h"
#include "231511088/231511088.h"
#include "231511091/231511091.h"
#include "231511086/231511086.h"

int main() {
    user loggedUser;
    char choice;

    do {
        loggedUser = loginDosen();
        if (loggedUser.nama == "") {
            cout << "Login gagal, silakan coba lagi." << endl;
        }
    } while (loggedUser.nama == "");

    string mataUjian;
    int jumlahSoal;
    jawaban *headKunjaw = NULL;
    jawaban *headKey = NULL;

    do {
        choice = dashboardDosen(loggedUser);
        switch (choice) {
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
            system("cls");
        }
    } while (choice == '1');

    delete headKunjaw;
    delete headKey;

    return 0;
}
