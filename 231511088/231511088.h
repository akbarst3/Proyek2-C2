#ifndef HEAD088_H
#define HEAD088_H
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "../user.h"

struct ujian
{
    string pertanyaan;
    string jawaban[4];
};

char dashboard(user dosen);
void toUpperCase(string *str);
void buatSoal(string mataUjian, int jumlahSoal, ujian *soalBaru);
void simpanKeFile(ujian *soalBaru, string namaFile, int jumlahSoal);

#endif