#include <iostream>
#include <string>

using namespace std;

struct Node {
    string nama_produk;
    int harga;
    Node *prev, *next;

    Node(string nama, int hrg) : nama_produk(nama), harga(hrg), prev(NULL), next(NULL) {}
};

class DoubleLinkedList {
private:
    Node *head, *tail;

public:
    DoubleLinkedList() : head(NULL), tail(NULL) {}

    void addProduct(string nama, int harga) {
        Node *newNode = new Node(nama, harga);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertAfter(string after, string nama, int harga) {
        Node *current = head;
        while (current && current->nama_produk != after) {
            current = current->next;
        }
        if (current && current->next) {
            Node *newNode = new Node(nama, harga);
            newNode->next = current->next;
            current->next->prev = newNode;
            current->next = newNode;
            newNode->prev = current;
        } else {
            cout << "Produk setelah '" << after << "' tidak ditemukan." << endl;
        }
    }

    void removeProduct(string nama) {
        Node *current = head;
        while (current && current->nama_produk != nama) {
            current = current->next;
        }
        if (current) {
            if (current->prev) {
                current->prev->next = current->next;
            }
            if (current->next) {
                current->next->prev = current->prev;
            }
            if (current == head) {
                head = current->next;
            }
            if (current == tail) {
                tail = current->prev;
            }
            delete current;
        } else {
            cout << "Produk '" << nama << "' tidak ditemukan." << endl;
        }
    }

    void updateProduct(string oldNama, string newNama, int newHarga) {
        Node *current = head;
        while (current && current->nama_produk != oldNama) {
            current = current->next;
        }
        if (current) {
            current->nama_produk = newNama;
            current->harga = newHarga;
        } else {
            cout << "Produk '" << oldNama << "' tidak ditemukan." << endl;
        }
    }

    void displayProducts() {
        Node *current = head;
        cout << "Nama Produk\tHarga\n";
        while (current) {
            cout << current->nama_produk << "\t" << current->harga << endl;
            current = current->next;
        }
    }

    ~DoubleLinkedList() {
        while (head) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

void displayMenu() {
    cout << "Toko Skincare Purwokerto\n";
    cout << "1. Tambah Data\n";
    cout << "2. Hapus Data\n";
    cout << "3. Update Data\n";
    cout << "4. Tambah Data Urutan Tertentu\n";
    cout << "5. Hapus Data Urutan Tertentu\n";
    cout << "6. Hapus Seluruh Data\n";
    cout << "7. Tampilkan Data\n";
    cout << "8. Exit\n";
}

int main() {
    DoubleLinkedList dll;
    dll.addProduct("Originote", 60000);
    dll.addProduct("Somethinc", 150000);
    dll.addProduct("Skintific", 100000);
    dll.addProduct("Wardah", 50000);
    dll.addProduct("Hanasui", 30000);

    int pilihan;
    string nama, after;
    int harga;

    do {
        displayMenu();
        cout << "Pilih menu: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama Produk: ";
                cin >> nama;
                cout << "Masukkan Harga: ";
                cin >> harga;
                dll.addProduct(nama, harga);
                break;
            case 2:
                cout << "Masukkan Nama Produk yang akan dihapus: ";
                cin >> nama;
                dll.removeProduct(nama);
                break;
            case 3:
                cout << "Masukkan Nama Produk yang akan diupdate: ";
                cin >> nama;
                cout << "Masukkan Nama Produk baru: ";
                cin >> after;
                cout << "Masukkan Harga baru: ";
                cin >> harga;
                dll.updateProduct(nama, after, harga);
                break;
            case 4:
                cout << "Masukkan Nama Produk setelah produk mana akan ditambahkan: ";
                cin >> after;
                cout << "Masukkan Nama Produk baru: ";
                cin >> nama;
                cout << "Masukkan Harga baru: ";
                cin >> harga;
                dll.insertAfter(after, nama, harga);
                break;
            case 7:
                dll.displayProducts();
                break;
            case 8:
                cout << "Terima kasih telah menggunakan program ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 8);

    return 0;
}

