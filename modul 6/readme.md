# <h1 align="center">Laporan Praktikum Modul Single and Double Linked List</h1>
<p align="center">Azka Widya Rahmawati</p>

## Dasar Teori
### Single Linked List
Single linked list merupakan susunan berupa untaian yang setiap node memiliki pointer yang menunjuk ke simpul berikutnya sehingga terbentuk satu untaian, dengan demikian hanya diperlukan sebuah variabel pointer. NULL memiliki nilai khusus yang artinya tidak menunjuk ke mana-mana. Biasanya, linked list pada titik akhirnya akan menunjuk ke NULL. Pembuatan single linked list dapat dilakukan menggunakan dua jenis metode, yaitu LIFO (last in first out) dengan aplikasinya stack (tumpukan) dan FIFO (first in first out) dengan aplikasinya queue (antrean) [1]. 

### Linked List Circular 
Linked List Circular adalah struktur data yang terdiri dari sejumlah simpul (atau node) yang saling terhubung, sedangkan linked list non-circular terletak pada penunjuk simpul terakhir (tail). Pada linked list circular, simpul terakhir (tail) tidak menunjuk ke NULL seperti pada linked list non-circular, melainkan menunjuk kembali ke simpul pertama (head), sehingga membentuk lingkaran tertutup.

### Double Linked List
Salah satu kelemahan single linked list adalah pointer atau penunjuk yang hanya dapat bergerak satu arah, yaitu maju/mundur atau kanan/kiri sehingga pencarian data pada single linked list hanya dapat bergerak dalam satu arah. Untuk mengatasi kelemahan ini, bisa menggunakan metode double linked 
list. Linked list ini dikenal dengan nama linked list berpointer ganda atau double linked list [2].

## Guided 

### 1. Latihan Single Linked List
```C++
#include <iostream>
using namespace std;

///PROGRAM SINGLE LINKED LIST NON-CIRCULAR
//Deklarasi Struct Node
struct Node {
    //komponen/member
    int data;
    Node *next;
};
    Node *head;
    Node *tail;
//Inisialisasi Node
void init(){
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty(){
    if (head == NULL)
    return true;
    else
    return false;
}
//Tambah Depan
void insertDepan(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
}
    else{
        baru->next = head;
        head = baru;
    }
}
//Tambah Belakang
void insertBelakang(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
    tail->next = baru;
    tail = baru;
    }
}
//Hitung Jumlah List
int hitungList(){
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while( hitung != NULL ){
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
//Tambah Tengah
void insertTengah(int data, int posisi){
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
            bantu = head;
            int nomor = 1;
        while( nomor < posisi - 1 ){
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
//Hapus Depan
void hapusDepan() {
    Node *hapus;
    if (isEmpty() == false){
        if (head->next != NULL){
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Belakang
void hapusBelakang() {
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false){
        if (head != tail){
            hapus = tail;
            bantu = head;
            while (bantu->next != tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Tengah
void hapusTengah(int posisi){
    Node *hapus, *bantu, *bantu2;
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        int nomor = 1;
        bantu = head;
        while( nomor <= posisi ){
            if( nomor == posisi-1 ){
                bantu2 = bantu;
            }
            if( nomor == posisi ){
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
    delete hapus;
    }
}
//Ubah Depan
void ubahDepan(int data){
    if (isEmpty() == false){
        head->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Tengah
void ubahTengah(int data, int posisi){
    Node *bantu;
    if (isEmpty() == false){
        if( posisi < 1 || posisi > hitungList() ){
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if( posisi == 1){
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else{
            bantu = head;
            int nomor = 1;
            while (nomor < posisi){
                bantu = bantu->next;nomor++;
            }
            bantu->data = data;
        }
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Belakang
void ubahBelakang(int data){
    if (isEmpty() == false){
        tail->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Hapus List
void clearList(){
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
//Tampilkan List
void tampil(){
    Node *bantu;
    bantu = head;
    if (isEmpty() == false){
        while (bantu != NULL){
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
int main(){
    init();
    insertDepan(3);tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7,2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    return 0;
}
```
Kode di atas digunakan untuk melakukan operasi dasar pada Single Linked List, seperti menambahkan, menghapus, dan mengubah Node, serta menampilkan isi list. Kode ini juga menunjukkan penggunaan variabel global dan fungsi untuk mengelola list. Penggunaan cout digunakan untuk memberikan umpan balik kepada pengguna tentang operasi yang dilakukan atau kesalahan yang mungkin terjadi, seperti posisi yang di luar jangkauan atau list yang masih kosong. 

### 2. Latihan Double Linked List

```C++
#include <iostream>
using namespace std;

class Node {
    public:int data;
    Node* prev;
    Node* next;
};
class DoublyLinkedList {
        public:
        Node* head;
        Node* tail;
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
    }
    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } 
        else {
            tail = newNode;
        }
        head = newNode;
    }
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } 
        else {
            tail = nullptr;
        }
        delete temp;
    }
    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};


int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```
Kode di atas adalah contoh sederhana dari Double Linked List dapat digunakan dalam aplikasi nyata dengan interaksi pengguna. Dalam program ini menggunakan loop tak terbatas (while (true)) untuk terus menampilkan menu dan memproses pilihan pengguna sampai pengguna memilih untuk keluar (case 6). Kode ini memungkinkan pengguna untuk melakukan operasi dasar pada Doubly Linked List melalui terminal atau command line interface. class Node dapat mendefinisikan struktur Node dengan tiga anggota yaitu data (int), prev (pointer ke Node sebelumnya), dan next (pointer ke Node berikutnya). class DoublyLinkedList mendefinisikan kelas untuk Double Linked List dengan dua pointer, head dan tail. DoublyLinkedList() adalah konstruktor yang menginisialisasi head dan tail dengan nullptr, menandakan list kosong. void push(int data) digunakan untuk menambahkan Node baru dengan data yang diberikan ke awal list. void pop() digunakan untuk menghapus Node pertama dari list. bool update(int oldData, int newData) digunakan untuk mencari Node dengan oldData dan mengganti datanya dengan newData. Mengembalikan true jika berhasil, false jika tidak. void deleteAll() digunakann untuk menghapus semua Node dalam list dan mengatur head dan tail menjadi nullptr. void display()digunakan untuk menampilkan data dari setiap Node dalam list.
int main() adalah fungsi utama yang menyediakan menu interaktif untuk menambahkan, menghapus, memperbarui, dan menampilkan data, serta menghapus seluruh data atau keluar dari program.

## Unguided 

### 1. Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut:

a.  Masukkan data sesuai urutan berikut. (Gunakan insert depan, belakang atau tengah). Data pertama yang dimasukkan adalah nama dan usia anda.

![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/f0a790b4-a876-4c2e-a48d-619df7ab914b)

b.  Hapus data Akechi

c.	Tambahkan data berikut diantara Azka dan Jane : Futaba	18

d.	Tambahkan data berikut diawal : Igor	20

e.	Ubah data Michael menjadi : Reyn	18

f.	Tampilkan seluruh data

```C++
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
```
#### Output:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/08067222-f69a-4d86-a613-0995869c6f6c)

Kode di atas digunakan untuk mengimplementasikan kelas LinkedList untuk mengelola daftar tunggal elemen Node yang menyimpan data siswa, termasuk nama dan usia mereka. Fungsi anggota kelas memungkinkan penyisipan, penghapusan, pembaruan, dan penampilan data siswa. Kode ini menunjukkan penggunaan daftar terkait untuk menyimpan dan memanipulasi data dengan cara yang terstruktur dan efektif. #include <iostream> dan #include <string> adalah perintah untuk menyertakan header files yang memberikan fungsionalitas untuk input/output dan tipe data string. Struct Node untuk mendefinisikan struktur Node yang menyimpan nama, usia, dan pointer ke Node berikutnya. Class LinkedList untuk Mendefinisikan kelas LinkedList dengan pointer head dan tail. LinkedList() untuk konstruktor yang menginisialisasi head dan tail ke NULL. insertDepan untuk menambahkan Node baru di awal list. insertBelakang untuk menambahkan Node baru di akhir list. insertTengah untuk menambahkan Node baru setelah Node dengan nama tertentu. hapusData untuk menghapus Node dengan nama tertentu dari list. ubahData utnuk mengubah nama dan usia pada Node tertentu. tampilkanData untuk menampilkan semua data dalam list. int main() adalah fungsi utama yang menunjukkan cara menggunakan LinkedList untuk menambahkan, menghapus, dan menampilkan data.

#### Full code Screenshot:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/e19cca87-2d78-4300-a72e-f959a058f899)

### 2. Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/7c5760f4-00d3-411d-bd9d-43bf8a520dbe)
Case:
1. Tambahkan produk Azarine dengan harga 65000 diantara Somethinc dan Skintific
2. Hapus produk wardah
3. Update produk Hanasui menjadi Cleora dengan harga 55.000
4. Tampilkan menu seperti dibawah ini:

    Toko Skincare Purwokerto
    1.  Tambah Data
    2.	Hapus Data
    3.	Update Data
    4.	Tambah Data Urutan Tertentu
    5.	Hapus Data Urutan Tertentu
    6.	Hapus Seluruh Data
    7.	Tampilkan Data
    8.	Exit
    
Pada menu 7, tampilan akhirnya akan menjadi seperti dibawah ini:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/eb9e57db-24de-49a5-9b7a-c6d9c924e5f8)

```C++
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
```
#### Output:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/8dfce61e-458a-4e81-a72d-ac8791283545)

Kode di atas digunakan untuk mengelola daftar produk dengan menggunakan struktur data Double Linked List dimana pengguna dapat menambahkan produk baru, menghapus produk, memperbarui informasi produk, dan menampilkan semua produk yang tersedia. #include <iostream> dan #include <string> adalah perintah untuk menyertakan header files yang memberikan fungsionalitas untuk input/output dan tipe data string. using namespace std; memungkinkan untuk menggunakan elemen-elemen dalam namespace std tanpa perlu menuliskan std:: sebelum setiap elemen tersebut. struct Node mendefinisikan tipe data Node yang memiliki atribut nama_produk, harga, prev (pointer ke Node sebelumnya), dan next (pointer ke Node berikutnya). class DoubleLinkedList mendefinisikan tipe data DoubleLinkedList dengan dua pointer, head dan tail, yang menunjuk ke Node pertama dan terakhir dalam list. DoubleLinkedList() adalah konstruktor yang menginisialisasi head dan tail dengan NULL, menandakan list kosong.addProduct menambahkan produk baru ke akhir list. insertAfter menambahkan produk baru setelah produk dengan nama tertentu. removeProduct menghapus produk dengan nama tertentu dari list. updateProduct mengubah nama dan harga produk yang sudah ada dalam list. displayProducts menampilkan nama dan harga dari setiap produk dalam list. ~DoubleLinkedList() adalah destruktor yang membersihkan semua Node dalam list saat objek DoubleLinkedList dihancurkan. Pada fungsi displayMenu menampilkan menu interaktif untuk pengguna dan pada fungsi main adalah fungsi utama yang membuat objek DoubleLinkedList, menambahkan beberapa produk, dan memproses input pengguna sesuai dengan pilihan menu yang dipilih.

#### Full code Screenshot:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/94afc668-d563-4052-8dda-c6161a79f2ba)


## Kesimpulan
Single Linked List adalah struktur data linier yang terdiri dari simpul-simpul yang saling terhubung secara sekuensial. Setiap simpul memiliki pointer yang menunjuk ke simpul berikutnya. Linked list ini mendukung operasi LIFO (Last In First Out) dan FIFO (First In First Out). Pada Linked List Circular, varian dari linked list di mana simpul terakhir (tail) menunjuk kembali ke simpul pertama (head), membentuk lingkaran tertutup yang memungkinkan iterasi tanpa batas akhir. Sedangkan Double Linked List mengatasi keterbatasan single linked list dengan memiliki dua pointer di setiap simpul, yang memungkinkan navigasi dua arah. Double linked list memudahkan pencarian dan manipulasi data.

## Referensi
[1] A. Zein and E. S. Eriana, Algoritma dan Struktur Data, Tangerang Selatan: Unpam Press, 2022. 

[2] A. Mulyana, Cara Mudah Mempelajari Algoritma dan Struktur Data, Yogyakarta: DIVA Press, 2021. 
