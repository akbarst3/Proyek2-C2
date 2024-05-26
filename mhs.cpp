#include "231511085/231511085.h"
#include "231511086/231511086.h"
#include "231511088/231511088.h"
#include "231511091/231511091.h"
#include "231511078/231511078.h"
#include "user.h"
#include <string>

int main()
{
    string full_path;
    string answers;
    vector<Question> questions;
    string folder_path = "Assets/folder-soal";
    vector<string> files;
    user loggedUser;

    do
    {
        loggedUser = loginMhs();
        char choice;
        if (loggedUser.nama == "")
        {
            cout << "Login gagal, silakan coba lagi." << endl;
        }
        else
        {
            do
            {
                jawaban *headPlain = nullptr;
                jawaban *headKunjaw = nullptr;
                jawaban *headKey = nullptr;
                string topik;
                int jumlahSoal;
                choice = dashboard(loggedUser);
                switch (choice)
                {
                case '1':
                    system("cls");
                    full_path = chooseFile(folder_path);
                    questions = readQuestionsFromFile(full_path);
                    jumlahSoal = questions.size();
                    saveAnswersToLinkedList(questions, headPlain);
                    topik = getTopik(full_path);
                    toLowerCase(topik);
                    CaesarCipherEnkrip(headPlain, jumlahSoal);
                    buatkey(topik, headKey);
                    CaesarCipherEnkrip(headKey, jumlahSoal);
                    headPlain = PlayfairCipher(headPlain, headKey);
                    cout << "-----------------" << endl;
                    createFile(headPlain, "mhs", loggedUser.id + "_" + topik);
                    system("PAUSE");
                    topik = "Assets/folder-kunci-jawaban/kunjaw" + topik + ".txt";
                    bacafile(topik, headKunjaw);
                    nilai(headKunjaw, headPlain, jumlahSoal);
                    system("pause");
                    break;

                case '2':
                    loggedUser.nama = "";
                    system("cls");
                    break;

                default:
                    cout << "---Karakter yang diinputkan tidak valid---" << endl;
                    system("pause");
                    system("cls");
                    break;
                    freeMemory(&headKey);
                    freeMemory(&headKunjaw);
                    freeMemory(&headPlain);
                }
            } while (choice == '1');
        }
    } while (loggedUser.nama == "");
}