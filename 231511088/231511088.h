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
    opsi *opsi;
    ujian *next;
};

char dashboard(user dosen);
void buatSoal(string mataUjian, int jumlahSoal);
void toUpperCase(string *str);
void soalBaru(ujian *head, int jumlahSoal);
void simpanKeFile(ujian *head, string namaFile, int jumlahSoal);
void buatKunjaw(opsi *headKunjaw, string mataUjian, int jumlahSoal);

#endif