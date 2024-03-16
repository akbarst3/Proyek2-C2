#include "231511086.h"

std::vector<Question> readQuestionsFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "Gagal membuka file." << std::endl;
        exit(1);
    }

    std::vector<Question> questions;
    std::string line;
    Question currentQuestion;

    while (std::getline(file, line)) {
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

void saveAnswersToFile(const std::vector<Question>& questions, const std::string& filename) {
    std::ofstream answerFile(filename);

    if (!answerFile.is_open()) {
        std::cout << "Gagal membuka file jawaban." << std::endl;
        exit(1);
    }

    char answer;
    for (size_t i = 0; i < questions.size(); ++i) {
        std::cout << questions[i].question << std::endl;
        for (size_t j = 0; j < questions[i].options.size(); ++j) {
            std::cout << questions[i].options[j] << std::endl;
        }
        std::cout << "Jawaban Anda (A/B/C/D): ";
        std::cin >> answer;

        if (answer == 'A' || answer == 'B' || answer == 'C' || answer == 'D') {
            answerFile << answer << std::endl;
        } else {
            std::cout << "Jawaban tidak valid." << std::endl;
            answerFile << "Invalid" << std::endl;
        }
    }

    answerFile.close();

    std::cout << "Jawaban telah disimpan dalam file " << filename << std::endl;
}
