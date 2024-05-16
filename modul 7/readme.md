# <h1 align="center">Laporan Praktikum Modul Stack & Queue</h1>
<p align="center">Azka Widya Rahmawati</p>

## Dasar Teori
### Stack
Stack atau tumpukan adalah suatu kumpulan data yang seolah-olah ada data yang diletakkan di atas data yang lainya. Perlu diingat bahwa stack merupakan suatu list yang semua operasi penambahan (insertion) data dan penghapusan (deletion) data, elemennya dilaksanakan pada satu ujung atas tumpukan (top of stack) [1]. Elemen pertama yang akan dihapus adalah elemen terakhir yang disisipkan, sehingga disebut “Last In First Out” (LIFO) yang memiliki prinsip data yang masuk terakhir akan di ambil pertama kali dan TOP menunjuk elemen terakhir [2]. Petunjuk awal stack = DASAR. Jika TOP = 0, berarti stack kosong dan TOP berimpit dengan DASAR.

Beberapa fungsi dasar untuk pengelolaan data pada operasi dalam stack:
1. Push: Menambahkan elemen ke puncak stack. Jika stack penuh, operasi ini tidak dapat dilakukan.
2. Pop: Menghapus elemen dari puncak stack. Jika stack kosong, operasi ini tidak dapat dilakukan.
3. Peek atau Top: Melihat elemen yang berada di puncak stack tanpa menghapusnya.
4. isEmpty: Memeriksa apakah stack kosong.
5. isFull: Memeriksa apakah stack penuh.
6. Size: Mendapatkan jumlah elemen yang ada di dalam stack.
7. Clear: Mengosongkan semua elemen yang ada di dalam stack.

### Queue
Queue adalah suatu kumpulan data yang mana penambahan elemen hanya dapat dilakukan pada suatu ujung (disebut dengan sisi belakang atau rear), dan penghapusan (pengambilan elemen) dilakukan lewat   ujung lain (disebut dengan sisi depan atau front). Struktur data queue atau antrian sedikit berbeda dari stack, yang mana dalam queue item pertama yang dimasukkan adalah yang pertama jadi dihapus (First-In-First-Out, FIFO), sementara dalam stack, item terakhir dimasukkan adalah yang pertama akan dihapus (LIFO). Queue berfungsi seperti baris di film: orang pertama yang bergabung di belakang garis adalah orang pertama yang mencapai garis depan antrian dan beli tiket dan orang terakhir yang mengantre adalah orang terakhir yang membeli tiket [3].

Beberapa operasi umum pada struktur data queue:
1. Enqueue (Push): Menambahkan elemen ke belakang (akhir) antrian. 
2. Dequeue (Pop): Menghapus elemen dari depan (awal) antrian.
3. Front (Peek): Melihat elemen yang berada di depan antrian tanpa menghapusnya.
4. isEmpty: Memeriksa apakah antrian kosong.
5. isFull: Memeriksa apakah antrian penuh.
6. Size: Mendapatkan jumlah elemen yang ada dalam antrian.
7. Clear: Mengosongkan semua elemen dalam antrian.

## Guided 
### 1. Stack
```C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArraybuku() {
    for (int i = top; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";
    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;
    peekArrayBuku(2);
    popArrayBuku();
    cout << "Banyaknya data = " << countStack() << endl;
    changeArrayBuku(2, "Bahasa Jerman");
    cout << endl;
    cetakArrayBuku();
    cout << "\n";
    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    cetakArrayBuku();

    return 0;
}
```
Kode di atas digunakan untuk mengimplemnentasikan stack dalam mengelola data buku dan memungkinkan operasi dasar seperti menambah, menghapus, dan melihat data. Pada isFull(), fungsi ini memeriksa apakah stack sudah penuh. Jika variabel top sama dengan maksimal, yang berarti tidak ada ruang lagi untuk menambah data, fungsi akan mengembalikan nilai true. Pada isEmpty() digunakan untuk memeriksa apakah stack kosong. Jika top adalah 0, tidak ada elemen dalam stack, dan fungsi akan mengembalikan nilai true. Untuk menambahkan beberapa buku ke dalam stack dapat menggunakan pushArrayBuku(). Untuk mencetak semua buku yang ada dalam stack dapat menggunakan cetakArrayBuku(). memeriksa apakah stack penuh dengan isFull() dan apakah stack kosong dengan isEmpty(). Untuk melihat buku pada posisi tertentu dapat menggunakan peekArrayBuku(). popArrayBuku() digunakan untuk  menghapus buku teratas. changeArrayBuku() digunakan untuk mengubah judul buku pada posisi tertentu. Kemudian, untuk menghapus semua buku dalam stack dan mencetak stack untuk memastikan bahwa semua buku telah dihapus dapat menggunakan destroyArraybuku().

### 2. Queue
```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0; // Penanda depan antrian
int back = 0; // Penanda belakang antrian
string queueTeller[5]; // Array untuk menyimpan antrian

bool isFull() { // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue) {
        return true; // =1
    } else {
        return false;
    }
}

bool isEmpty() { // Antrian kosong atau tidak
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) { // Menambahkan antrian
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) { // Jika antrian kosong
            queueTeller[0] = data;
            front++;
            back++;
        } else { // Jika antrian ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() { // Mengurangi antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() { // Menghitung jumlah antrian
    return back;
}

void clearQueue() { // Menghapus semua antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() { // Melihat isi antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```
Kode di atas digunakan untuk mengimplementasikan queue dalam mengelola antrian teller yang memungkinkan operasi dasar seperti menambah, menghapus, dan melihat elemen dalam antrian. Pada const int maksimalQueue = 5; digunankan untuk mendeklarasikan konstanta maksimalQueue yang menentukan ukuran maksimum queue. int front = 0; untuk mendeklarasikan variabel front yang menunjukkan indeks depan dari queue. int back = 0; untuk mendeklarasikan variabel back yang menunjukkan indeks belakang dari queue. string queueTeller[5]; untuk mendeklarasikan array queueTeller yang akan digunakan untuk menyimpan data antrian. Pada isFull() digunakan untuk mengembalikan true jika queue penuh, yaitu jika back sama dengan maksimalQueue dan isEmpty() digunakan untuk mengembalikan true jika queue kosong, yaitu jika back adalah 0. Untuk menambahkan data ke queue dapat menggunakan enqueueAntrian(string data). Jika queue penuh, akan mencetak “Antrian penuh”. Jika queue kosong, data akan ditambahkan pada indeks 0. Jika tidak, data akan ditambahkan pada indeks back. Untuk menghapus data dari depan queue dapat menggunakan dequeueAntrian(). Jika queue kosong, akan mencetak “Antrian kosong”. Jika tidak, semua elemen dalam queue akan digeser ke depan. Untuk mengembalikan jumlah elemen dalam queue dapat menggunakan countQueue(). Untuk menghapus semua elemen dalam queue dan mengatur back dan front kembali ke 0 dapat menggunakan clearQueue(). Kemudian untuk menampilkan semua elemen dalam queue dapat menggunakan viewQueue(). Jika elemen tidak kosong akan mencetak elemennya dan jika kosong akan mencetak “(kosong)”.

## Unguided 

### 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.

```C++
#include <iostream>

using namespace std;

bool isPalindrome(const string& str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        // Skip non-alphanumeric characters
        while (left < right && !isalnum(str[left])) left++;
        while (left < right && !isalnum(str[right])) right--;

        // Convert to lowercase and compare
        if (tolower(str[left]) != tolower(str[right])) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    string sentence;
    cout << "Masukan Kalimat: ";
    getline(cin, sentence);

    if (isPalindrome(sentence)) {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }

    return 0;
}
```
#### Output:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/06273d65-0f96-40df-bcec-f6f4c824f74b)

Kode di atas digunakan untuk mengecek apakah kalimat yang diinputkan dalam program stack adalah palindrom atau tidak. Program ini hanya memeriksa setengah dari string dan mengabaikan karakter non-alfanumerik serta perbedaan antara huruf besar dan kecil yang memastikan bahwa pengecekan palindrom dilakukan dengan benar sesuai definisi palindrom yang sebenarnya. Pada isPalindrome menerima sebuah string str dan mengembalikan true jika str adalah palindrom, dan false jika bukan. Variabel left dan right digunakan untuk menelusuri string dari kedua ujungnya. Untuk Loop while pertama digunakan untuk melewati karakter non-alfanumerik dan Loop while kedua untuk membandingkan karakter setelah diubah ke huruf kecil. Jika karakter tidak cocok, maka fungsi mengembalikan false, dan jika semua karakter cocok, maka fungsi mengembalikan true. Pada fungsi getline digunakan untuk membaca seluruh baris input, termasuk spasi. Fungsi isPalindrome dipanggil dengan sentence sebagai argumen. Berdasarkan nilai kembalian dari isPalindrome, program akan mencetak apakah kalimat tersebut adalah palindrom atau bukan.

#### Full code Screenshot:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/446c73b2-51c3-494a-aefd-7143b3686728)

### 2. Ubah guided queue diatas agar menjadi program inputan user dan program menu.
```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; 
int front = 0; 
int back = 0; 
string queueTeller[maksimalQueue]; 

bool isFull() { // Mengecek antrian penuh atau tidak
    return back == maksimalQueue;
}

bool isEmpty() { 
    return back == 0;
}

void enqueueAntrian(string data) { // Menambah antrian
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        queueTeller[back++] = data;
    }
}

void dequeueAntrian() { // Mengurangi antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back - 1; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        queueTeller[--back] = ""; 
    }
}

int countQueue() { // Menghitung jumlah antrian
    return back;
}

void clearQueue() { // Menghapus semua antrian
    for (int i = 0; i < back; i++) {
        queueTeller[i] = "";
    }
    back = 0;
}

void viewQueue() { // Melihat isi antrian
    cout << "Data antrian:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

void displayMenu() { 
    cout << "\n---- MENU ----" << endl;
    cout << "1. Tambah antrian" << endl;
    cout << "2. Hapus antrian" << endl;
    cout << "3. Lihat antrian" << endl;
    cout << "4. Hapus semua antrian" << endl;
    cout << "5. Jumlah antrian" << endl;
    cout << "6. Keluar" << endl;
    cout << "Pilih menu: ";
}

int main() { //program utama
    int pilihan;
    string nama;

    do { //looping untuk menu
        displayMenu();
        cin >> pilihan;
        cin.ignore(); 
        switch (pilihan) {
            case 1:
                cout << "Masukkan nama: ";
                getline(cin, nama);
                enqueueAntrian(nama);
                break;
            case 2:
                dequeueAntrian();
                break;
            case 3:
                viewQueue();
                break;
            case 4:
                clearQueue();
                break;
            case 5:
                cout << "Jumlah antrian = " << countQueue() << endl;
                break;
            case 6:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (pilihan != 6);

    return 0;
}
```
#### Output:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/1a7901ce-5719-4bc1-8c66-cc4d72b16330)
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/de655afa-e028-43fb-bc2a-afca04412de2)

Kode di atas menggunakan konsep FIFO (First In First Out) untuk pengelolaan antrian yang umum digunakan dalam sistem antrian seperti di bank atau loket pembayaran. Pada const int maksimalQueue = 5; mendefinisikan ukuran maksimal antrian yang dapat ditampung. Pada int front = 0; dan int back = 0; adalah variabel yang menunjukkan indeks depan dan belakang dari antrian, dan string queueTeller[maksimalQueue]; adalah array yang digunakan untuk menyimpan data antrian. Fungsi isFull() digunakan untuk mengecek apakah antrian sudah penuh atau belum dengan membandingkan back dengan maksimalQueue. Fungsi isEmpty() digunakan untuk mengecek apakah antrian kosong atau tidak dengan memeriksa nilai back. Fungsi enqueueAntrian(string data) digunakan untuk menambahkan data ke dalam antrian, jika antrian penuh, maka akan ditampilkan pesan “Antrian penuh”. Fungsi dequeueAntrian() digunakan untuk mengurangi antrian, jika antrian kosong, akan ditampilkan pesan “Antrian kosong”, dan jika tidak, elemen pertama akan dihapus dan elemen lainnya digeser ke depan. Fungsi countQueue() digunakan untuk mengembalikan jumlah elemen dalam antrian. Fungsi clearQueue() digunakan untuk menghapus semua elemen dalam antrian. Fungsi viewQueue() digunakan untuk menampilkan semua elemen dalam antrian. Fungsi displayMenu() digunakan untuk menampilkan menu interaktif untuk pengguna. Fungsi main() adalah fungsi utama yang mengendalikan alur program dengan menu interaktif yang memungkinkan pengguna untuk menambah, menghapus, melihat, atau menghapus semua antrian.

#### Full code Screenshot:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/dc57f0a8-01d5-4766-a30a-9345d5636d61)

## Kesimpulan
Dalam Stack, item terakhir yang dimasukkan adalah yang pertama akan dihapus (LIFO) dan dalam Queue yang mana item pertama yang dimasukkan adalah yang pertama jadi dihapus (FIFO). Kedua struktur data ini memiliki operasi dasar yang berbeda dan digunakan untuk berbagai aplikasi. Contoh program stack untuk palindrom menunjukkan bagaimana stack dapat digunakan untuk menyelesaikan masalah tertentu. Pemahaman yang baik tentang stack dan queue dapat membantu memahami cara kerja sistem komputasi dan ingin mengembangkan kemampuan berpikir logis dan sistematis.

## Referensi
[1] W. Tarigan, ALGORITMA PEMROGRAMAN DAN STRUKTUR DATA, Purbalingga: EUREKA MEDIA AKSARA, 2022. 

[2] H. Soetanto, Struktur Data Dasar-dasar Pemrograman, Jakarta: Penerbit Universitas Budi Luhur, 2022. 

[3] A. Zein and E. S. Eriana, Algoritma dan Struktur Data, Tangerang Selatan: Unpam Press, 2022. 
