#ifndef USER_H
#define USER_H
#include <string>

using namespace std;

struct user{
    string id;
    string password;
    string nama;
};

struct jawaban
{
    char jwb;
    jawaban *next;
};

struct opsi
{
    string opsiJwb;
    opsi *next;
};

#endif