#include <iostream>

using namespace std;

// Node struct untuk merepresentasikan node dalam linked list
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk membuat node baru
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk menambahkan node di awal linked list
void data_baru(Node*& head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

//  Memperbaiki bagian yang salah pada program
/*
Node createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return *newNode;
}

*/

// Fungsi untuk mencetak linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;

    // Menambahkan node ke linked list
    data_baru(head, 3);
    data_baru(head, 7);
    data_baru(head, 9);

    // Mencetak linked list
    cout << "Linked List: ";
    printList(head);

    return 0;
}
