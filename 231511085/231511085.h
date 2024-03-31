#include <iostream>
#include <fstream>
#include <string>
#include <string>
#include <vector>
#include "../user.h"

user login(const string &id, const string &password, const string &user);
user loginMhs();
user loginDosen();
class Grader {
public:
    Grader(const std::string& kunci_file, const std::string& jawaban_file);
    void runGrader();
private:
    std::vector<std::string> kunci_jawaban;
    std::vector<std::string> jawaban_pengguna;
    int poin;

    void bacaKunciJawaban(const std::string& kunci_file);
    void bacaJawabanPengguna(const std::string& jawaban_file);
    void periksaJawaban();
    void tampilkanPoin();
};
