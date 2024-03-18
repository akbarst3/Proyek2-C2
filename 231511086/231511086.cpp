#include "231511086.h"
#include <dirent.h>
#include <limits>

using namespace std;

vector<Question> readQuestionsFromFile(const string& filename) {
  ifstream file(filename);

  if (!file.is_open()) {
    cout << "Gagal membuka file." << endl;
    exit(1);
  }

  vector<Question> questions;
  string line;
  Question currentQuestion;

  while (getline(file, line)) {
    if (line.empty()) {
      questions.push_back(currentQuestion);
      currentQuestion = Question();
    } else {
      if (currentQuestion.question.empty()) {
        currentQuestion.question = line;
      } else {
        currentQuestion.options.push_back(line);
      }
    }
  }

  if (!currentQuestion.question.empty()) {
    questions.push_back(currentQuestion);
  }

  file.close();

  return questions;
}

void saveAnswersToFile(const vector<Question>& questions, char answers[]) {
  for (size_t i = 0; i < questions.size(); ++i) {
    cout << questions[i].question << endl;
    for (size_t j = 0; j < questions[i].options.size(); ++j) {
      cout << questions[i].options[j] << endl;
    }
    cout << "Jawaban Anda (A/B/C/D): ";
    cin >> answers[i];

    if (answers[i] != 'A' && answers[i] != 'B' && answers[i] != 'C' && answers[i] != 'D') {
      cout << "Jawaban tidak valid." << endl;
      answers[i] = 'I'; // Ganti 'I' dengan karakter lain untuk menandakan jawaban tidak valid
    }
  }
}

char dashboard(user mhs)
{
    system("cls");
    char answer;
    // Tampilkan dashboard
    cout << "------------------------------\n";
    cout << "|                            |\n";
    cout << "|       DASHBOARD MAHASISWA      |\n";
    cout << "|                            |\n";
    cout << "------------------------------\n";
    cout << "Selamat datang di dasbor Mahasiswa" << endl;
    cout << mhs.nama << endl;
    cout << mhs.id << endl;
    cout << "------------------------------" << endl;
    cout << "(1) Kerjakan Soal" << endl;
    cout << "(2) Keluar" << endl;
    cin >> answer;
    return answer;
}

void dapatkanFileDiFolder(const string& pathFolder, vector<string>& files) {
    string fullPath = "Assets/folder-soal/" + pathFolder; // Menggabungkan path relatif dengan folder-soal
    DIR *direktori;
    struct dirent *entri;
    if ((direktori = opendir(fullPath.c_str())) != NULL) {
        while ((entri = readdir(direktori)) != NULL) {
            string namaFile = entri->d_name;
            if (namaFile != "." && namaFile != "..") {
                files.push_back(namaFile);
            }
        }
        closedir(direktori);
    } else {
        cerr << "Error: Tidak dapat membuka direktori." << endl;
    }
}


// Fungsi untuk meminta pengguna memilih file dari daftar
string pilihFile(const vector<string>& files) {
    int pilihan;
    string alamatFile;
    while (true) {
        // Menampilkan menu berdasarkan nama file dalam folder
        cout << "Menu File:" << endl;
        for (size_t i = 0; i < files.size(); ++i) {
            cout << i + 1 << ". " << files[i] << endl;
        }

        cout << "Pilih file (1-" << files.size() << "), atau 0 untuk keluar: ";
        cin >> pilihan;

        if (pilihan == 0) {
            alamatFile = ""; // Jika pengguna memilih keluar
            break;
        } else if (pilihan >= 1 && pilihan <= static_cast<int>(files.size())) {
            alamatFile = files[pilihan - 1]; // Menyimpan alamat file yang dipilih
            break;
        } else {
            cout << "Pilihan tidak valid." << endl;
        }

        // Mengosongkan buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return alamatFile;
}

