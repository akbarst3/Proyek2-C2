#ifndef USER_H
#define USER_H
#include <string>

using namespace std;

struct user{
    string id;
    string password;
    string nama;
};

struct jawaban {
    char data;
    jawaban* next;
    jawaban(char d): data(d), next(nullptr) {}
};

#endif