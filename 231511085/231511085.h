#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct user {
    string id;
    string password;
    string nama;
};

user login(const string &id, const string &password, const string &user);
user loginMhs();
user loginDosen();