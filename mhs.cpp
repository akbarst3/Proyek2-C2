#include "231511085/231511085.h"
#include "231511086/231511086.h"
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
    char choice;

    do {
        loggedUser = loginMhs();
        if (loggedUser.nama == "") {
            cout << "Login gagal, silakan coba lagi." << endl;
        }
    } while (loggedUser.nama == "");

    choice = dashboard(loggedUser);

    string topik;
    string mataUjian;
    int jumlahSoal;
    jawaban *head = NULL;
    jawaban *headKunjaw = NULL;
    jawaban *headKey = NULL;
    switch (choice)
    {
    case '1':
        system("cls");

        full_path = chooseFile(folder_path);
        questions = readQuestionsFromFile(full_path);
        saveAnswersToLinkedList(questions, head);
        printLinkedList(head);
        topik = getTopik(full_path);
        CaesarCipherEnkrip(headKunjaw, jumlahSoal);
        buatkey(mataUjian, headKey);
        CaesarCipherEnkrip(headKey, jumlahSoal);
        headKunjaw = PlayfairCipher(headKunjaw, headKey);
        jawaban* PlayfairCipher(jawaban* plaintext, jawaban* key);
        createFile(head, "mhs", topik);
        system("PAUSE");
        topik = "Assets/folder-kunci-jawaban/kunjaw" + topik;
        bacafile(topik, headKunjaw);
        nilai(headKunjaw, head);
        break;

    case '2':
        system("cls");
        break;
    }
}
