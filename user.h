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
    string opsiJwb;
    jawaban *next;
};

#endif