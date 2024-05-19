#include "231511091.h"

void CaesarCipherEnkrip(jawaban *head, int shift)
{
    if (head == nullptr) return;
    shift = pow(shift,5); 
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
        shift--;
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

void deleteSameChar(jawaban *headkey)
{
    jawaban *current = headkey;
    jawaban *prev = nullptr;
    string seenChars = "";  

    while (current != nullptr)
    {
        char currentChar = current->data;
        if (seenChars.find(currentChar) != string::npos) 
        {
            
            if (prev != nullptr)
            {
                prev->next = current->next;
                delete current; 
                current = prev->next; 
            }
            else
            {
                
                headkey = current->next;
                delete current;
                current = headkey;
            }
        }
        else
        {
            seenChars += currentChar; 
            prev = current;
            current = current->next;
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
