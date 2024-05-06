#include "231511086.h"
#include <dirent.h>
#include <limits>
#include <iostream>
#include <string>

using namespace std;

vector<Question> readQuestionsFromFile(const string &filename)
{
  ifstream file(filename);

  if (!file.is_open())
  {
    cout << "Gagal membuka file." << endl;
    exit(1);
  }

  vector<Question> questions;
  string line;
  Question currentQuestion;

  while (getline(file, line))
  {
    if (line.empty())
    {
      questions.push_back(currentQuestion);
      currentQuestion = Question();
    }
    else
    {
      if (currentQuestion.question.empty())
      {
        currentQuestion.question = line;
      }
      else
      {
        currentQuestion.options.push_back(line);
      }
    }
  }

  if (!currentQuestion.question.empty())
  {
    questions.push_back(currentQuestion);
  }

  file.close();

  return questions;
}

// Fungsi untuk menyimpan jawaban ke dalam linked list
void saveAnswersToLinkedList(const vector<Question> &questions, Node *&head)
{
  cout << "------------------------------\n";
  cout << "|                            |\n";
  cout << "|       DASHBOARD UJIAN      |\n";
  cout << "|                            |\n";
  cout << "------------------------------\n";
  cout << "ISI SOAL DENGAN HURUF KAPITAL (A/B/C/D)" << endl;

  // Menginisialisasi pointer head ke NULL
  head = NULL;

  for (size_t i = 0; i < questions.size(); ++i)
  {
    cout << questions[i].question << endl;
    for (size_t j = 0; j < questions[i].options.size(); ++j)
    {
      cout << questions[i].options[j] << endl;
    }
    cout << "Jawaban Anda (A/B/C/D): ";
    char answer;
    cin >> answer;

    // Memastikan jawaban yang dimasukkan adalah huruf kapital
    if (answer >= 'a' && answer <= 'z')
    {
      answer -= ('a' - 'A'); // Konversi huruf ke huruf kapital
    }

    if (answer != 'A' && answer != 'B' && answer != 'C' && answer != 'D')
    {
      cout << "Jawaban tidak valid." << endl;
      answer = 'I'; // Ganti 'I' dengan karakter lain untuk menandakan jawaban tidak valid
    }

    // Membuat node baru untuk menyimpan jawaban
    Node *newNode = new Node;
    newNode->answer = answer;
    newNode->next = NULL;

    // Menambahkan node baru ke awal linked list
    newNode->next = head;
    head = newNode;
  }
}

// Fungsi untuk mencetak isi linked list
void printLinkedList(Node *head)
{
  cout << "Daftar Jawaban:" << endl;
  while (head != NULL)
  {
    cout << head->answer << " ";
    head = head->next;
  }
  cout << endl;
}

char dashboard(user mhs)
{
  system("cls");
  char answer;
  // Tampilkan dashboard
  cout << "------------------------------\n";
  cout << "|                            |\n";
  cout << "|       DASHBOARD MAHASISWA      |\n";
  cout << "|                            |\n";
  cout << "------------------------------\n";
  cout << "Selamat datang di dasbor Mahasiswa" << endl;
  cout << mhs.nama << endl;
  cout << mhs.id << endl;
  cout << "------------------------------" << endl;
  cout << "(1) Kerjakan Soal" << endl;
  cout << "(2) Keluar" << endl;
  cin >> answer;
  return answer;
}
// Implementasi fungsi chooseFile di luar kelas
string chooseFile(const string &folder_path)
{
  // Menampilkan daftar file kepada pengguna
  cout << "Pilih file yang ingin Anda buka:\n";
  int file_count = 0;
  for (const auto &entry : fs::directory_iterator(folder_path))
  {
    if (fs::is_regular_file(entry.path()))
    {
      ++file_count;
      cout << file_count << ". " << entry.path().filename() << endl;
    }
  }

  if (file_count == 0)
  {
    cout << "Tidak ada file dalam folder." << endl;
  }

  // Meminta pengguna untuk memilih file
  int choice;
  cout << "Pilihan Anda: ";
  cin >> choice;

  // Mengonfirmasi pilihan pengguna dan membuka file yang dipilih
  if (choice > 0 && choice <= file_count)
  {
    int current_file = 0;
    for (const auto &entry : fs::directory_iterator(folder_path))
    {
      if (fs::is_regular_file(entry.path()))
      {
        ++current_file;
        if (current_file == choice)
        {
          string selected_file_path = folder_path + "/" + entry.path().filename().string();
          cout << "Anda telah memilih untuk membuka file: " << selected_file_path << endl;
          // Di sini Anda bisa menulis kode untuk membuka file
          return selected_file_path;
        }
      }
    }
  }
  else
  {
    cout << "Pilihan tidak valid." << endl;
  }
}
