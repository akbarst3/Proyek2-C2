#ifndef HEAD088_H
#define HEAD088_H
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "../user.h"

struct opsiJawaban
{
    string data;
    opsiJawaban *next;
};

struct soalBaru
{
    string pertanyaan;
    opsiJawaban *opsi;
    soalBaru *next;
};


char dashboardDosen(user dosen);
void buatSoal(string mataUjian, int jumlahSoal);
void toUpperCase(string *str);
void tulisSoal(soalBaru **head, int jumlahSoal);
void simpanKeFile(soalBaru *head, string namaFile, int jumlahSoal);
void buatKunjaw(jawaban **headKunjaw, string mataUjian, int jumlahSoal);

#endif