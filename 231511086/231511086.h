#ifndef HEAD086_H
#define HEAD086_H
#define MAX_QUESTIONS 100

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Question {
  std::string question;
  std::vector<std::string> options;
};

std::vector<Question> readQuestionsFromFile(const std::string& filename);
void saveAnswersToFile(const std::vector<Question>& questions, char answers[]);

#endif
