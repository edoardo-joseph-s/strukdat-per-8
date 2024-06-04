#include <iostream>

using namespace std;

// Node struct untuk merepresentasikan node dalam linked list
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk membuat node baru
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Fungsi untuk menambahkan data di belakang linked list
void insertAtEnd(Node*& head, int data) {
    if (head == nullptr) {
        head = createNode(data);
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = createNode(data);
    }
}

// Fungsi untuk mencetak linked list
void printList(Node* head) {
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;
    int newData;
    char proceed = 'y';

    // Meminta pengguna untuk menambahkan data
    while (proceed == 'y') {
        cout << "Masukkan data baru: ";
        cin >> newData;
        insertAtEnd(head, newData);

        cout << "Data berhasil ditambahkan ke linked list." << endl;

        cout << "Apakah Anda ingin menambahkan data lagi? (y/n): ";
        cin >> proceed;
    }

    // Mencetak linked list setelah semua data ditambahkan
    cout << "Linked List setelah penambahan data:" << endl;
    printList(head);

    return 0;
}