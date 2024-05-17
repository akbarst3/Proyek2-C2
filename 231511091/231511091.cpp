#include "231511091.h"

void addNode(jawaban *head, string &data)
{
    jawaban *newNode = new jawaban;
    newNode->opsiJwb = data;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        jawaban *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void CaesarCipherEnkrip(jawaban *head, int shift)
{
    shift = (pow(shift, 5) / 2);
    jawaban *current = head;
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
        shift--;
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
        while (current != NULL)
        {
            file << current->opsiJwb << endl;
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
    while (current != NULL)
    {
        string opsiJwb = current->opsiJwb;
        string newOpsiJwb = "";

        for (int i = 0; i < opsiJwb.length(); i++)
        {
            bool found = false;
            for (int j = 0; j < newOpsiJwb.length(); j++)
            {
                if (opsiJwb[i] == newOpsiJwb[j])
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                newOpsiJwb += opsiJwb[i];
            }
        }

        current->opsiJwb = newOpsiJwb;
        current = current->next;
    }
}

void buatkey(string key, Node* &headkey)
{
    Node* last = nullptr;

    for (char c : key)
    {
        Node* nodeKey = new Node(c); 
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