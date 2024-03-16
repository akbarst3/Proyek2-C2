#include "231511086.h"

int main() {
    std::string questionFile = "../Assets/folder-soal/PTIK.txt";
    std::string answerFile = "../Assets/folder-jawab-mhsw/jawaban_ptik.txt";

    std::vector<Question> questions = readQuestionsFromFile(questionFile);

    saveAnswersToFile(questions, answerFile);

    return 0;
}
