#ifndef HEAD086_H
#define HEAD086_H
#define MAX_QUESTIONS 100

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <dirent.h>
#include <limits>
#include <filesystem>
#include "../user.h"

namespace fs = filesystem;
using namespace std;

struct Question {
  string question;
  vector<string> options;
};

vector<Question> readQuestionsFromFile(const string& filename);

void saveAnswersToLinkedList(const vector<Question>& questions, jawaban*& head);

char dashboard(user mhs);
// Fungsi untuk meminta pengguna memilih file dari daftar
string chooseFile(const string& folder_path);

#endif
