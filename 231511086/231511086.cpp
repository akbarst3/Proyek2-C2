#include "231511086.h"

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
