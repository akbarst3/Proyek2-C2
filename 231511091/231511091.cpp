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
        current = current->next;
    }
}

void createFile(string hasilEnkrip, string namaFile, string user)
{
    string path;
    if (user == "dosen")
    {
        path = "assets/folder-kunci-jawaban/";
        namaFile = "kunjaw" + namaFile;
    }
    else
    {
        path = "assets/folder-jawab-mhsw/";
    }
    ofstream file(path + namaFile + ".txt");
    if (file.is_open())
    {
        file << hasilEnkrip;
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

void buatkey(string key, jawaban *headkey)
{

    for (char c : key)
    {
        jawaban *nodeKey = (jawaban *)malloc(sizeof(jawaban));
        if (nodeKey == NULL)
        {
            cout << "Memori Full\n";
            return;
        }
        nodeKey->opsiJwb = c;
        nodeKey->next = NULL;
        if (headkey == NULL)
        {
            headkey = nodeKey;
        }
        else
        {
            jawaban *temp = headkey;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = nodeKey;
        }
    }
}