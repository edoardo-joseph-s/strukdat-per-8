#include <iostream> 

using namespace std; 

struct Node{ // Mendefinisikan struktur Node untuk linked list
    int data; // Menyimpan data dalam node
    Node* next; // Pointer ke node berikutnya dalam linked list
};

Node* createNode(int data){ // Fungsi untuk membuat node baru
    Node* newNode = new Node(); // Membuat node baru dengan alokasi memori
    newNode->data = data; // Mengatur data node
    newNode->next = nullptr; // Mengatur pointer next node menjadi nullptr
    return newNode; // Mengembalikan node yang baru dibuat
}

void tambah_data(Node*& head, int data){ // Fungsi untuk menambahkan data ke linked list
    Node* newNode = createNode(data); // Membuat node baru dengan data yang diberikan
    if (head == nullptr){ // Jika linked list masih kosong
        head = newNode; // Menjadikan node baru sebagai head
    }else{ // Jika linked list tidak kosong
        Node* temp = head; // Membuat pointer sementara ke head
        while (temp->next != nullptr){ // Melakukan iterasi sampai akhir linked list
            temp = temp->next; // Bergerak ke node berikutnya
        }
        temp->next = newNode; // Menyambungkan node baru di akhir linked list
    }
}

void printlist(Node* head){ // Fungsi untuk mencetak linked list
    Node* temp = head; // Membuat pointer sementara ke head
    cout << "Linked List: "; // Mencetak label
    while (temp != nullptr){ // Melakukan iterasi selama masih ada node
        cout << temp->data << "->"; // Mencetak data node
        temp = temp->next; // Bergerak ke node berikutnya
    }
    cout <<"NULL"<<endl; // Mencetak NULL di akhir linked list
}

int main(){ // Fungsi utama
    Node* head = nullptr; // Inisialisasi head linked list sebagai nullptr

    tambah_data(head, 10); // Menambahkan data 10 ke linked list
    tambah_data(head, 15); // Menambahkan data 15 ke linked list
    tambah_data(head, 30); // Menambahkan data 30 ke linked list
    tambah_data(head, 5); // Menambahkan data 5 ke linked list

    printlist(head); // Mencetak linked list

    return 0;
}