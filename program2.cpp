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

// Fungsi untuk menambahkan node di awal linked list
void tambah_data(Node*& head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
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

// Fungsi untuk menghapus node dari linked list berdasarkan nilai yang diberikan
void deleteNode(Node*& head, int key) {
    Node* temp = head;
    Node* prev = nullptr;

    if (temp != nullptr && temp->data == key) {
        head = temp->next;
        delete temp;
        return;
    }

    while (temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Data " << key << " tidak ditemukan dalam linked list." << endl;
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Data " << key << " berhasil dihapus dari linked list." << endl;
}

int main() {
    Node* head = nullptr;
    int choice, data;

    do {
        cout << "\nMenu:\n1. Tambah Data\n2. Hapus Data\n3. Tampilkan Linked List\n4. Keluar\nPilih: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Masukkan data yang ingin ditambahkan: ";
                cin >> data;
                tambah_data(head, data);
                break;
            case 2:
                cout << "Masukkan data yang ingin dihapus: ";
                cin >> data;
                deleteNode(head, data);
                break;
            case 3:
                printList(head);
                break;
            case 4:
                cout << "Keluar dari program.";
                break;
            default:
                cout << "\nPilihan tidak valid. Silakan coba lagi.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}