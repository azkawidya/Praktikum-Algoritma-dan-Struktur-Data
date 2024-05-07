#include <iostream>
#include <string>

using namespace std;

struct Node {
    string nama;
    int usia;
    Node* next;
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insertDepan(string nama, int usia) {
        Node* newNode = new Node();
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = head;
        head = newNode;
        if (tail == NULL) {
            tail = head;
        }
    }

    void insertBelakang(string nama, int usia) {
        Node* newNode = new Node();
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = NULL;
        if (tail != NULL) {
            tail->next = newNode;
        }
        tail = newNode;
        if (head == NULL) {
            head = tail;
        }
    }

    void insertTengah(string nama, int usia, string namaSetelah) {
        Node* current = head;
        while (current != NULL && current->nama != namaSetelah) {
            current = current->next;
        }
        if (current != NULL) {
            Node* newNode = new Node();
            newNode->nama = nama;
            newNode->usia = usia;
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void hapusData(string nama) {
        Node* current = head;
        Node* previous = NULL;
        while (current != NULL && current->nama != nama) {
            previous = current;
            current = current->next;
        }
        if (current != NULL) {
            if (previous != NULL) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            delete current;
        }
    }

    void ubahData(string namaLama, string namaBaru, int usiaBaru) {
        Node* current = head;
        while (current != NULL && current->nama != namaLama) {
            current = current->next;
        }
        if (current != NULL) {
            current->nama = namaBaru;
            current->usia = usiaBaru;
        }
    }

    void tampilkanData() {
        Node* current = head;
        while (current != NULL) {
            cout << current->nama << "\t" << current->usia << endl;
            current = current->next;
        }
    }
};

int main() {
    LinkedList list;

    // Masukkan data sesuai urutan berikut.
    list.insertBelakang("Azka", 18);
    list.insertBelakang("Jane", 20);
    list.insertBelakang("Michael", 18);
    list.insertBelakang("Yusuke", 19);
    list.insertBelakang("Akechi", 20);
    list.insertBelakang("Hoshino", 18);
    list.insertBelakang("Karin", 18);

    // Hapus data Akechi
    list.hapusData("Akechi");

    // Tambahkan data Futaba diantara Azka dan Jane
    list.insertTengah("Futaba", 18, "Azka");

    // Tambahkan data Igor diawal
    list.insertDepan("Igor", 20);

    // Ubah data Michael menjadi Reyn
    list.ubahData("Michael", "Reyn", 18);

    // Tampilkan seluruh data
    list.tampilkanData();

    return 0;
}