#include "231511086.h"

using namespace std;

int main() {
  string questionFile = "../Assets/folder-soal/mater.txt";

  vector<Question> questions = readQuestionsFromFile(questionFile);

  // Buat array untuk menyimpan jawaban
  char answers[MAX_QUESTIONS];

  // Simpan jawaban pengguna ke dalam array
  saveAnswersToFile(questions, answers);

  // Cetak jawaban
  for (int i = 0; i < questions.size(); ++i) {
    cout << "Pertanyaan " << (i + 1) << ": " << answers[i] << endl;
  }

  /*cek hasil jawaban di array
  for (int i = 0;i < questions.size(); i++) {
    cout << answers[i];
  } */

  system("PAUSE");
  return 0;
}
