#include "231511091.h"

void CaesarCipherEnkrip(jawaban *head, int shift)
{
    if (head == nullptr) return;
    jawaban *current = head;    
    while (current != nullptr)
    {
        char c = current->data;
        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            c = ((c - base + shift) % 26) + base; 
        }
        current->data = c; 
        current = current->next; 
    }
}

void createFile(jawaban* head, string user, string namaFile)
{
    string path;
    jawaban *current = head;
    if (user == "dosen")
    {
        path = "assets/folder-kunci-jawaban/";
        namaFile = "kunjaw" + namaFile;
    }
    else
    {
        path = "assets/folder-jawab-mhsw/";
    }
    ofstream file(path + namaFile);
    if (file.is_open())
    {
        while (current != nullptr)
        {
            file << current->data << endl;
            current = current->next;
        }
        file.close();
        cout << "File berhasil dibuat!\n";
    }
    else
    {
        cerr << "File gagal dibuat!\n";
    }
}

void removeSpaces(string &str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
}

void toLowerCase(string &str)
{
    for (char &ch : str)
    {
        if (isupper(ch))
        {
            ch = tolower(ch);
        }
    }
}

void buatkey(string key, jawaban* &headkey)
{
    jawaban* last = nullptr;

    for (char c : key)
    {
        jawaban* nodeKey = new jawaban(c); 
        if (nodeKey == nullptr)
        {
            cout << "Memori Full\n";
            return;
        }

        if (headkey == nullptr)
        {
            headkey = nodeKey; 
        }
        else
        {
            last->next = nodeKey; 
        }
        last = nodeKey; 
    }
}

