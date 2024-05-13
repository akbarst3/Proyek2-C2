#include "231511091.h"
#include "../user.h"

void addNode(jawaban* head, string& data) 
{
    jawaban* newNode = new jawaban;
    newNode->opsiJwb = data;
    newNode->next = nullptr;

    if (head == nullptr) 
    {
        head = newNode;
    } 
    else 
    {
        jawaban* current = head;
        while (current->next != nullptr) 
        {
            current = current->next;
        }
        current->next = newNode;
    }
}


void CaesarCipherEncrypt(jawaban* head, int shift) 
{
    jawaban* current = head;
    while (current != nullptr) 
    {
        std::string cipher = "";
        std::string add = "x";
        for (char c : current->opsiJwb) 
        {
            if (isalpha(c)) 
            {
                char base = isupper(c) ? 'A' : 'a';
                c = ((c - base) + shift) % 26 + base;
            }
            cipher += c + add;
        }
        current->opsiJwb = cipher;
        current = current->next;
    }
}

void displayList(jawaban* head) 
{
    jawaban* current = head;
    while (current != nullptr) 
    {
        std::cout << current->opsiJwb << std::endl;
        current = current->next;
    }
}

void freeList(jawaban* head) 
{
    jawaban* current = head;
    while (current != nullptr) 
    {
        jawaban* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

void createFile(string hasilEnkrip, string namaFile, string user) {
    string path;
    if(user == "dosen"){
        path = "assets/folder-kunci-jawaban/";
        namaFile = "kunjaw" + namaFile;
    } else {
        path  = "assets/folder-jawab-mhsw/";
    }
    ofstream file( path + namaFile + ".txt");
    if (file.is_open()) {
        file << hasilEnkrip;
        file.close();
        cout << "File berhasil dibuat!\n";
    } else {
        cerr << "File gagal dibuat!\n";
    }
}

void removeSpaces(string &str) {
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
}

void toLowerCase(string &str) {
    for (char &ch : str) {
        if (isupper(ch)) {
            ch = tolower(ch);
        }  
    }
}

void deleteSameChar(string &key)
{
    string temp;
    for (char c : key)
    {
        bool found = false;
        for (char d : temp)
        {
            if (d == c)
            {
                found = true;
            }
        }
        if (!found)
        {
            temp += c;
        }
    }
    key = temp;
}

