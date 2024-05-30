# <h1 align="center">Laporan Praktikum Modul Rekursif dan Hash Table</h1>
<p align="center">Azka Widya Rahmawati</p>

## Dasar Teori
### Rekursif
Rekursi adalah teknik pemrograman di mana sebuah fungsi memanggil dirinya sendiri untuk menyelesaikan suatu masalah. Fungsi yang memanggil dirinya sendiri disebut fungsi rekursif [1]. Rekursi dapat digunakan untuk menyelesaikan berbagai masalah, seperti traversal struktur data (pohon, daftar, dan lainnya), menghitung faktorial, deret Fibonacci, algoritma pencarian (binary search, quicksort, dan lainnya). Fungsi rekursif biasanya memiliki dua kasus, yaitu:

- Kasus dasar: kondisi yang mudah dipecahkan tanpa perlu rekursi.

- Kasus rekursif: masalah yang dipecahkan dengan memanggil fungsi itu sendiri dengan parameter yang berbeda.

#### Kelebihan Rekursi:
- Solusi rekursif lebih mudah dibaca dibandingkan solusi iteratif.
- Rekursi dapat digunakan untuk memecahkan masalah yang bersifat rekursif secara alami.
- Rekursi dapat membantu dalam mendefinisikan dan memahami struktur data kompleks.

#### Kekurangan Rekursi:
- Efisiensi ruang menjadi masalah utama dalam rekursi karena setiap panggilan rekursif menambah overhead pada call stack.
- Kesulitan dalam pemahaman konsep rekursi oleh beberapa programmer dapat memunculkan potensi bug dan kompleksitas pemecahan masalah.
- Beberapa implementasi rekursif mungkin kurang efisien secara waktu, terutama ketika terdapat overhead pemanggilan fungsi.

###  Hash Table
Hash Table adalah struktur data yang digunakan untuk menyimpan dan mencari data dengan cepat [2]. Hash Table memetakan kunci ke nilai menggunakan fungsi hash. Fungsi hash mengambil kunci dan menghasilkan indeks dalam tabel hash. Nilai kemudian disimpan di indeks yang sesuai.

#### Cara Kerja Hash Table:
- Fungsi Hash: Kunci dipetakan ke indeks dalam tabel hash menggunakan fungsi hash.
- Penyimpanan Nilai: Nilai disimpan di indeks yang dihasilkan oleh fungsi hash.
- Pencarian: Untuk mencari nilai, fungsi hash digunakan untuk menghasilkan indeks dari kunci. Nilai di indeks yang sesuai kemudian dikembalikan.

#### Kelebihan Hash Table:
- Hash Table memungkinkan pencarian data yang sangat cepat, terutama untuk data dalam jumlah besar.
- Hash Table dapat menggunakan memori secara efisien, terutama jika fungsi hash dirancang dengan baik.
- Hash Table dapat digunakan untuk menyimpan berbagai jenis data, seperti string, angka, dan objek.

#### Kekurangan Hash Table:
- Tabrakan terjadi ketika dua kunci berbeda dipetakan ke indeks yang sama. Tabrakan perlu ditangani dengan teknik tertentu, seperti chaining atau open addressing.
- Performa Hash Table sangat bergantung pada fungsi hash yang digunakan. Fungsi hash yang buruk dapat menyebabkan banyak tabrakan dan memperlambat operasi.

## Guided 
### 1.  Rekursif Langsung (Direct Recursion)

```C++
#include <iostream>
using namespace std;
//Code ini berfungsi untuk melakukan hitung mundur
//dari angka yang diinputkan

void countdown(int n) {
    if (n == 0) {
        return;
    }
    cout << n << " ";
    countdown(n - 1);
}

int main() {
    cout << "Rekursif Langsung: ";
    countdown(5); //5 merupakan input nya
    cout << endl;
    return 0;
}   
```
Kode di atas mendemonstrasikan penggunaan fungsi rekursif untuk melakukan hitung mundur dari angka yang diinputkan dimana fungsi countdown() memanggil dirinya sendiri secara berulang hingga nilai input mencapai 0. Pada void countdown(int n), fungsi countdown() yang menerima satu parameter integer n. Fungsi ini memiliki tipe kembalian void atau tidak mengembalikan nilai. Pada if (n == 0) { return; } untuk mengecek apakah nilai n sama dengan 0. Jika ya, fungsi akan langsung dihentikan dengan menggunakan perintah return; yang menandakan bahwa hitung mundur telah selesai. Pada countdown(n - 1); memanggil fungsi countdown() secara rekursif dengan parameter n - 1, yang mana fungsi akan memanggil dirinya sendiri dengan nilai n yang dikurangi 1 pada setiap pemanggilan. Hal ini akan terus berulang hingga nilai n mencapai 0 dan fungsi dihentikan. Pada cout << "Rekursif Langsung: "; mencetak teks "Rekursif Langsung: " ke konsol. Pada countdown(5); memanggil fungsi countdown() dengan nilai input 5. Hal ini akan memulai hitung mundur dari 5 hingga 0 dan pada cout << endl; menambahkan baris baru ke konsol.

### 2. Rekursif Tidak Langsung (Indirect Recursion)
```C++
#include <iostream>
using namespace std;

void functionB(int n);

void functionA(int n) {
    if (n > 0) {
        cout << n << " ";
        functionB(n - 1); // Panggilan rekursif tidak langsung
    }
}

void functionB(int n) {
    if (n > 0) {
        cout << n << " ";
        functionA(n / 2); // Panggilan rekursif tidak langsung
    }
}

int main() {
    int num = 5;
    cout << "Rekursif Tidak Langsung: ";
    functionA(num);
    return 0;
}
```
Kode di atas mendemonstrasikan penggunaan rekursif tidak langsung untuk mencetak deret angka dengan pola tertentu, yang mana fungsi functionA() dan functionB() saling memanggil satu sama lain secara berulang, namun dengan cara yang berbeda. Hal ini menghasilkan deret angka yang unik, yaitu dimulai dari nilai input, kemudian dibagi 2, dicetak, dan dibagi 2 lagi, dan seterusnya, hingga mencapai 0.

### 3. Hash Table
```C++
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int TABLE_SIZE = 11;
string name;
string phone_number;
class HashNode {
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];
public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
    return hash_val % TABLE_SIZE; // 4 bisa aja 204,12004, 6 bisa aja 266, 300
    }
    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);
        
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }
    
    void remove(string name) {
        int hash_val = hashFunc(name);

        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->name == name) {
                table[hash_val].erase(it);
                return;
            }
        }
    }
    string searchByName(string name) {
    int hash_val = hashFunc(name);
    for (auto node : table[hash_val]) {
        if (node->name == name) {
            return node->phone_number;
        }
    }
    return "";
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
                for (auto pair : table[i]) {
                if(pair != nullptr){
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main() {
HashMap employee_map;

employee_map.insert("Mistah", "1234");
employee_map.insert("Pastah", "5678");
employee_map.insert("Ghana", "91011");

cout << "Nomer Hp Mistah : " <<employee_map.searchByName("Mistah") << endl;
cout << "Phone Hp Pastah : " <<employee_map.searchByName("Pastah") << endl;
cout << "Phone Hp Ghana : " <<employee_map.searchByName("Ghana") << endl;

employee_map.remove("Mistah");

cout << "Nomer Hp Mistah setelah dihapus : " <<employee_map.searchByName("Mistah") << endl << endl;

cout << "Hash Table : " << endl;

employee_map.print();

return 0;
}
```
Kode di atas digunakan untuk menyimpan dan mengelola informasi pegawai menggunakan Hash Table. Hash Table menjadi pilihan yang tepat untuk aplikasi yang membutuhkan pencarian dan penyisipan data yang cepat, terutama untuk data dalam jumlah besar. Kode di atas menggunakan fungsi hash untuk menyimpan entri pada bucket yang sesuai, dan fungsi lainnya untuk menambah, menghapus, dan mencari entri berdasarkan nama.

## Unguided 

### 1. Buatlah sebuah program Rekursif Langsung (Direct Recursion) yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif!
```C++
#include <iostream>
using namespace std;

// Fungsi rekursif untuk menghitung faktorial
int faktorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * faktorial(n - 1);
    }
}

int main() {
    int bilangan;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> bilangan;

    // Memastikan bahwa input adalah bilangan bulat positif
    if (bilangan < 0) {
        cout << "Harap masukkan bilangan bulat positif." << endl;
    } else {
        cout << "Faktorial dari " << bilangan << " adalah: " << faktorial(bilangan) << endl;
    }

    return 0;
}
```
#### Output:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/946efa93-5cac-461b-add3-8fb847ea1c2f)

Kode di atas mendefinisikan fungsi rekursif untuk menghitung faktorial dari bilangan bulat positif yang dimasukkan oleh pengguna. Fungsi faktorial(n) memanggil dirinya sendiri secara berulang hingga mencapai kasus dasar (n <= 1) dimana pada if (n <= 1), jika n lebih kecil dari atau sama dengan 1, maka nilai faktorial adalah 1. Namun, jika n lebih besar dari 1, maka faktorial dihitung dengan mengalikan n dengan faktorial dari n - 1. Kemudian, fungsi faktorial(n - 1) akan menghitung faktorial dari n - 1, dan hasil tersebut dikalikan dengan n untuk mendapatkan faktorial dari n. Pada fungsi main() untuk mengatur input pengguna, memvalidasinya, dan memanggil fungsi faktorial() untuk menghitung dan menampilkan hasil faktorial.

#### Full code Screenshot:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/767ffc4d-da21-4028-a601-f0b812205fcc)

### 2. Buatlah versi program Rekursif Tidak Langsung (Indirect Recursion) dari soal nomor 1 di atas!
```C++
#include <iostream>
using namespace std;

// Deklarasi fungsi rekursif tidak langsung
int faktorialGenap(int n);
int faktorialGanjil(int n);

// Fungsi untuk menghitung faktorial bilangan genap
int faktorialGenap(int n) {
    if (n <= 0) {
        return 1;
    } else {
        return n * faktorialGanjil(n - 1);
    }
}

// Fungsi untuk menghitung faktorial bilangan ganjil
int faktorialGanjil(int n) {
    if (n <= 0) {
        return 1;
    } else {
        return n * faktorialGenap(n - 1);
    }
}

int main() {
    int bilangan;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> bilangan;

    // Memastikan bahwa input adalah bilangan bulat positif
    if (bilangan < 0) {
        cout << "Harap masukkan bilangan bulat positif." << endl;
    } else {
        // Memilih fungsi rekursif berdasarkan genap atau ganjil
        if (bilangan % 2 == 0) {
            cout << "Faktorial dari " << bilangan << " adalah: " << faktorialGenap(bilangan) << endl;
        } else {
            cout << "Faktorial dari " << bilangan << " adalah: " << faktorialGanjil(bilangan) << endl;
        }
    }

    return 0;
}
```
#### Output:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/c84b668a-df7b-49dd-b633-a9b2686b0fac)

Kode di atas digunakan untuk mendefinisikan dua fungsi rekursif tidak langsung untuk menghitung faktorial bilangan bulat positif, yaitu faktorialGenap() untuk bilangan genap dan faktorialGanjil() untuk bilangan ganjil. Pada faktorialGenap(int n) digunakan untuk menghitung faktorial bilangan genap n dimana if (n <= 0), jika n lebih kecil dari atau sama dengan 0, maka nilai faktorialnya adalah 1 dan jika n lebih besar dari 0, maka faktorial dihitung dengan mengalikan n dengan faktorial ganjil dari n - 1. Kemudian, fungsi faktorialGanjil(n - 1) akan menghitung faktorial ganjil dari n - 1, dan hasil tersebut dikalikan dengan n untuk mendapatkan faktorial genap dari n.

Pada faktorialGanjil(int n) menghitung faktorial bilangan ganjil n. Struktur dan logika fungsi ini mirip dengan faktorialGenap(), yaitu if (n <= 0), jika n lebih kecil dari atau sama dengan 0, maka nilai faktorialnya adalah 1 dan jika n lebih besar dari 0, maka faktorial dihitung dengan mengalikan n dengan faktorial genap dari n - 1. Kemudian, Fungsi faktorialGenap(n - 1) akan menghitung faktorial genap dari n - 1, dan hasil tersebut dikalikan dengan n untuk mendapatkan faktorial ganjil dari n.

#### Full code Screenshot:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/d6fd30f7-a251-4563-a7f1-9f889dc3470f)

### 3. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan:
a. Setiap mahasiswa memiliki NIM dan nilai.

b. Program memiliki tampilan pilihan menu berisi poin C.

c. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).
```C++
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Mahasiswa {
    string NIM;
    int nilai;
};

// Hash table menggunakan unordered_map
unordered_map<string, Mahasiswa> hashTable;

// Fungsi untuk menambahkan data mahasiswa baru
void tambahData(const string& NIM, int nilai) {
    hashTable[NIM] = {NIM, nilai};
}

// Fungsi untuk menghapus data mahasiswa berdasarkan NIM
void hapusData(const string& NIM) {
    if (hashTable.find(NIM) != hashTable.end()) {
        hashTable.erase(NIM);
        cout << "Data berhasil dihapus." << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }
}

// Fungsi untuk mencari data mahasiswa berdasarkan NIM
void cariDataNIM(const string& NIM) {
    auto it = hashTable.find(NIM);
    if (it != hashTable.end()) {
        cout << "NIM: " << it->second.NIM << ", Nilai: " << it->second.nilai << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }
}

// Fungsi untuk mencari data mahasiswa berdasarkan rentang nilai
void cariDataNilai(int minNilai, int maxNilai) {
    bool found = false;
    for (auto& pair : hashTable) {
        if (pair.second.nilai >= minNilai && pair.second.nilai <= maxNilai) {
            cout << "NIM: " << pair.second.NIM << ", Nilai: " << pair.second.nilai << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Tidak ada data dalam rentang nilai yang dicari." << endl;
    }
}

int main() {
    // Tampilan menu pilihan
    int pilihan, nilai;
    string NIM;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Data\n";
        cout << "2. Hapus Data\n";
        cout << "3. Cari Data Berdasarkan NIM\n";
        cout << "4. Cari Data Berdasarkan Nilai (80 - 90)\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan NIM: ";
                cin >> NIM;
                cout << "Masukkan nilai: ";
                cin >> nilai;
                tambahData(NIM, nilai);
                break;
            case 2:
                cout << "Masukkan NIM yang akan dihapus: ";
                cin >> NIM;
                hapusData(NIM);
                break;
            case 3:
                cout << "Masukkan NIM yang dicari: ";
                cin >> NIM;
                cariDataNIM(NIM);
                break;
            case 4:
                cariDataNilai(80, 90);
                break;
            case 5:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 5);

    return 0;
}
```
#### Output:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/0750733b-3994-41ff-9cc3-45f5ab621d88)

Kode di atas digunakan untuk ntuk mengelola data mahasiswa menggunakan Hash Table. Fungsi-fungsi yang digunakan pada kode di atas dapat melakukan penambahan, penghapusan, dan pencarian data mahasiswa.

Deklarasi Hash Table: unordered_map<string, Mahasiswa> hashTable; adalah deklarasi Hash Table hashTable yang menggunakan string sebagai kunci (NIM) dan struktur Mahasiswa sebagai nilai.

Fungsi tambahData(): Menambahkan data mahasiswa baru ke Hash Table dan memasukkan NIM dan nilai ke dalam Hash Table menggunakan kunci (NIM) dan nilai (struktur Mahasiswa).

Fungsi hapusData(): Menghapus data mahasiswa berdasarkan NIM dan mmencari entri dengan kunci (NIM) dalam Hash Table. Jika entri ditemukan, entri dihapus dari Hash Table. Pesan "Data berhasil dihapus." dicetak jika berhasil, atau "Data tidak ditemukan." jika gagal.

Fungsi cariDataNIM(): Mencari data mahasiswa berdasarkan NIM dan mencari entri dengan kunci (NIM) dalam Hash Table. Jika entri ditemukan, informasi NIM dan nilai dicetak. Jika tidak ditemukan, pesan "Data tidak ditemukan." dicetak.

Fungsi cariDataNilai(): Mencari data mahasiswa berdasarkan rentang nilai (80 - 90 dalam contoh ini) dan mengiterasi semua entri dalam Hash Table. Jika nilai mahasiswa dalam rentang yang ditentukan, informasi NIM dan nilai dicetak. Jika tidak ada data dalam rentang, pesan "Tidak ada data dalam rentang nilai yang dicari." dicetak.

Fungsi main(): Menyajikan menu interaktif dengan 5 pilihan: Tambah Data Mahasiswa, Hapus Data Mahasiswa,Cari Data Mahasiswa Berdasarkan NIM, Cari Data Mahasiswa Berdasarkan Nilai (80 - 90), dan Keluar. Selain itu, membaca input pengguna untuk memilih operasi yang diinginkan, melakukan operasi yang dipilih dengan memanggil fungsi yang sesuai, dan mengulangi loop menu hingga pengguna memilih untuk keluar.

#### Full code Screenshot:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/2e76d60f-4e03-410b-9867-2b85f0942764)

## Kesimpulan
Rekursi dan Hash Table dapat digunakan untuk menyelesaikan berbagai masalah secara efisien. Rekursi memungkinkan solusi yang mudah dibaca atau dimengerti untuk masalah rekursif, sedangkan Hash Table memungkinkan pencarian data yang cepat dan efisien. Penggunaan keduanya dapat memperluas kemampuan dan keefektifan algoritma dan struktur data.

## Referensi
[1] A. Zein and E. S. Eriana, ALGORTIMA DAN STRUKTUR DATA, Tangerang Selatan: Unpam Press, 2022. 

[2] H. Soetanto, Struktur Data Dasar-Dasar Pemrograman, Jakarta: Penerbit Universitas Budi Luhur, 2022. 



 