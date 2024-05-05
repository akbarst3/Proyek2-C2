#include "231511078.h"

Node* newNode(char data) {
  Node* newNode = new Node;
  newNode->data = data;
  newNode->next = nullptr;
  return newNode;
}

void insertAtEnd(Node** head_ref, char data) {
  Node* new_node = newNode(data);
  if (*head_ref == nullptr) {
    *head_ref = new_node;
    return;
  }
  Node* last = *head_ref;
  while (last->next != nullptr) {
    last = last->next;
  }
  last->next = new_node;
}

void generateKeyTable(const string& key, Node** head_ref) {
  *head_ref = nullptr; 
  for (char ch : key) {
    insertAtEnd(head_ref, ch);
  }
  for (char ch : list1) {
    if (key.find(ch) == string::npos) {
      insertAtEnd(head_ref, ch);
    }
  }
}

Node* searchNode(Node* head, char ch) {
  while (head != nullptr) {
    if (head->data == ch) {
      return head;
    }
    head = head->next;
  }
  return nullptr;
}

void encryptByPlayfairCipher(Node* table, const string& plainText, string& cipherText) {
  cipherText = "";
  for (size_t i = 0; i < plainText.length(); i += 2) {
    char ch1 = plainText[i];
    char ch2 = plainText[i + 1];

    Node* node1 = searchNode(table, ch1);
    Node* node2 = searchNode(table, ch2);

    if (node1 == nullptr || node2 == nullptr) {
      continue; 
    }

    int row1 = (node1->next) ? (node1->next)->data - 'a' : node1->data - 'a';
    int col1 = node1->data - 'a';
    int row2 = (node2->next) ? (node2->next)->data - 'a' : node2->data - 'a';
    int col2 = node2->data - 'a';

    if (row1 == row2) {
      cipherText += table->next->data + ((col1 + 1) % 5);
      cipherText += table->next->data + ((col2 + 1) % 5);
    } else if (col1 == col2) {
      cipherText += table->next->data + (((row1 + 1) % 5) * 5 + col1);
      cipherText += table->next->data + (((row2 + 1) % 5) * 5 + col2);
    } else {
      cipherText += table->next->data + (row1 * 5 + col2);
      cipherText += table->next->data + (row2 * 5 + col1);
    }

    table = table->next; 
  }
}

string PlayfairCipher(string& plainText, string& key) {
  Node* table = nullptr;
  generateKeyTable(key, &table);

  string CipherText;
  encryptByPlayfairCipher(table, plainText, CipherText);
  return CipherText;
}