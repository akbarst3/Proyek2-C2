#include "231511085/231511085.h"
#include "231511086/231511086.h"
#include "user.h"
#include <string>

int main()
{
    string full_path;
    string answers;
    vector<Question> questions;
    string folder_path = "Assets/folder-soal";
    vector<string> files;
    user loggedUser = loginMhs();
    char choice;
    if (loggedUser.nama == "")
    {
        cout << "Login gagal" << endl;
        main();
    }
    else
    {
        choice = dashboard(loggedUser);
    }

    switch (choice)
    {
    case '1':
        system("cls");

        full_path = chooseFile(folder_path);

        questions = readQuestionsFromFile(full_path);
        
        saveAnswersToFile(questions, answers);

        /* Menampilkan jawaban yang disimpan
        cout << "Jawaban yang disimpan: " << answers << endl;
        */

        system("PAUSE");

    case '2':
        system("cls");
        main();
        break;
    }
}
