#include "231511085/231511085.h"
#include "231511086/231511086.h"
#include "user.h"

int main()
{
    string folderPath = "Assets/folder-soal";
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
        vector<string> files = dapatkanFileDiFolder(folderPath);

        if (!files.empty())
        {
            cout << "Pilih Soal: " << endl;
            for (size_t i = 0; i < files.size(); ++i)
            {
                cout << i + 1 << ". " << files[i] << endl;
            }

            string alamatFileTerpilih = pilihFile(files);

              if (alamatFileTerpilih.empty())
            {
                cout << "Tidak ada soal yang dipilih." << endl;
            }
            else
            {
                cout << "Soal yang dipilih : " << alamatFileTerpilih << endl;
                string questionFile = alamatFileTerpilih;

                vector<Question> questions = readQuestionsFromFile(questionFile);

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
                return 0;
            }
        }
        else
        {
            cout << "Tidak ada soal yang ditemukan dalam folder tersebut." << endl;
        }
        break;
    }

}