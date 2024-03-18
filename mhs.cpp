#include "231511085/231511085.h"
#include "231511086/231511086.h"
#include "user.h"

int main()
{
    string full_path;
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

        // Buat array untuk menyimpan jawaban
        char answers[MAX_QUESTIONS];

        // Simpan jawaban pengguna ke dalam array
        saveAnswersToFile(questions, answers);

        // Cetak jawaban
        for (int i = 0; i < questions.size(); ++i)
        {
            cout << "Pertanyaan " << (i + 1) << ": " << answers[i] << endl;
        }

        /*cek hasil jawaban di array
        for (int i = 0;i < questions.size(); i++) {
          cout << answers[i];
        } */

        system("PAUSE");
        

        case '2':
        system("cls");
        main();
        break;
    }
    
    


}

