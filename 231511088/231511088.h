#ifndef HEAD088_H
#define HEAD088_H
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

struct ujian
{
    string pertanyaan;
    string jawaban[4];
};

char dashboard(user dosen);
void buatSoal(string mataUjian, int jumlahSoal, ujian *soalBaru);
string toUpperCase(string str);
void simpanKeFile(const ujian *soalBaru, string namaFile, int jumlahSoal)





#endif