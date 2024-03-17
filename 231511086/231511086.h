#ifndef HEAD086_H
#define HEAD086_H
#define MAX_QUESTIONS 100

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Question {
  string question;
  vector<string> options;
};

vector<Question> readQuestionsFromFile(const string& filename);
void saveAnswersToFile(const vector<Question>& questions, char answers[]);

#endif
