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

struct Node {
  char answer; // Jawaban pengguna (A/B/C/D)
  Node* next; // Pointer ke node berikutnya
};

struct Question {
  string question;
  vector<string> options;
};

vector<Question> readQuestionsFromFile(const string& filename);

void saveAnswersToLinkedList(const vector<Question>& questions, Node*& head);

char dashboard(user mhs);
// Fungsi untuk meminta pengguna memilih file dari daftar
string chooseFile(const string& folder_path);

#endif
