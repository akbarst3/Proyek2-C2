#include <iostream>
#include <fstream>
#include <string>
#include "string.h"
#include <vector>
#include "../user.h"

user login(const string &id, const string &password, const string &user);
user loginMhs();
user loginDosen();
void bacafile(string path, jawaban *&headkunjaw);
void nilai(jawaban *headKunjaw, jawaban *headJawab, int jumlahSoal);
string getTopik(string path);
