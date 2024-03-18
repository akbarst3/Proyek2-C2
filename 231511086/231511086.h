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

namespace fs = std::filesystem;
using namespace std;

struct Question {
  string question;
  vector<string> options;
};

vector<Question> readQuestionsFromFile(const string& filename);

void saveAnswersToFile(const vector<Question>& questions, char answers[]);

char dashboard(user mhs);
// Fungsi untuk mendapatkan daftar file dalam suatu folder
vector<string> dapatkanFileDiFolder(const string& pathFolder);
// Fungsi untuk meminta pengguna memilih file dari daftar
string pilihFile(const vector<string>& files);

void chooseFile(const string& folder_path);

#endif
