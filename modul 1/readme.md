# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Azka Widya Rahmawati</p>

## Dasar Teori
Tipe data merupakan jenis nilai atau berupa nilai apa yang akan ditampung oleh sebuah variabel. Tipe data ini wajib ada saat akan membuat sebuah variabel, tujuannya agar variabel tersebut mempresentasikan nilai yang spesifik dan jelas saat digunakan nantinya [1]. Pemilihan tipe data yang tidak tepat dapat menyebabkan munculnya masalah seperti kesalahan dalam perhitungan, penggunaan memori yang tidak efisien, maupun kerentanan dalam keamanan program.

### Tipe Data Primitif
Tipe data primitif adalah tipe data dasar yang tidak diturunkan oleh tipe data lainnya. Contoh tipe data primitif yaitu:

Integer     : Digunakan untuk menyimpan bilangan bulat.

Float       : Digunakan untuk menyimpan bilangan desimal.

Character   : Digunakan untuk menyimpan karakter atau huruf.

Boolean     : Digunakan untuk menyimpan nilai boolean yang hanya memiliki dua nilai, true dan false.

### Tipe Data Abstrak 
Tipe data abstrak (ADT) adalah model matematika dari sebuah objek data yang meningkatkan tipe data dengan mengaitkan tipe data dengan fungsi yang beroperasi pada data terkait [2]. Tipe data ini tidak perlu mengetahui bagaimana tipe data tersebut 
diimplementasikan. ADT berfokus pada apa yang dapat dilakukan dengan data, bukan bagaimana data tersebut disimpan. Terdapat tiga ADT yaitu List ADT, Stack ADT, dan Queue ADT.

### Tipe Data Koleksi 
Tipe data koleksi adalah tipe data yang digunakan untuk menyimpan kumpulan data yang terhubung secara bersamaan. Contoh tipe data koleksi yang sering atau umum digunakan dalam pemrograman yaitu:

Array   : Menyimpan kumpulan data dengan tipe data yang sama di dalam urutan tertentu.

Vector  : Menyimpan kumpulan data dengan tipe data yang sama dalam urutan yang dapat diubah.

List    : Menyimpan kumpulan data dengan tipe data yang sama dalam urutan yang dapat diubah.

Set     : Menyimpan kumpulan data unik tanpa duplikat.

Map     : Menyimpan kumpulan data pasangan key-value.

## Guided 

### 1. Tipe Data Primitif

```C++
#include <iostream>
using namespace std;
// main program
int main()
{
    char op;
    float num1, num2;
    // it allows user to enter operator i.e. +, -, *, /
    cout << "masukkan operator: ";
    cin >> op;
    // it allows user to enter the operands
    cout << "\nMasukkan bilangan ke-1 dan ke-2: ";
    cin >> num1 >> num2;
    // switch statement begins
    switch (op)
    {
    // if user enter +
    case '+':
        cout << num1 + num2;
        break;
    // if user enter -
    case '-':
        cout << num1 - num2;
        break;
    // if user enter *
    case '*':
        cout << num1 * num2;
        break;
    //if user enter /
    case '/':
        cout << num1 / num2;
        break;
    // if the operator is other than +, -, *, or /,
    // error message will display
    default:
         cout << "Error! operator is not correct";
    } // switch statement ends
    return 0;
}
```
Kode di atas adalah program kalkulator sederhana yang memungkinkan pengguna memasukkan operator dan dua bilangan untuk melakukan operasi matematika. Jika memasukkan operator selain +, -, *, atau /, maka program akan menampilkan pesan kesalahan “Error! operator is not correct”.

### 2. Tipe Data Abstrak

```C   
#include <iostream>
#include <stdio.h>
using namespace std;

// struck
struct Mahasiswa
{
    const char *name;
    const char *address;
    int age;
};

int main()
{
    //menggunakan struct
    struct Mahasiswa mhs1, mhs2;
    // mengisi nilai ke struct
    mhs1.name = "Dian";
    mhs1.address = "Mataram";
    mhs1.age = 22;
    mhs2.name = "Bambang";
    mhs2.address = "Surabaya";
    mhs2.age = 23;

    // mencetak isi struct
    cout << "Mahasiswa 1\n";
    cout << "Nama: " << mhs1.name <<endl;
    cout << "Alamat: " << mhs1.address <<endl;
    cout << "Umur: " << mhs1.age <<endl;
    
    cout << "Mahasiswa 2\n";
    cout << "Nama: " << mhs2.name <<endl;
    cout << "Alamat: " << mhs2.address <<endl;
    cout << "Umur: " << mhs2.age <<endl;
    return 0;
}
```
Kode di atas menunjukkan cara menggunakan dan mendefinisikan struct untuk menyimpan data mahasiswa yang kemudian dicetak. Contoh ini merupakan cara sederhana untuk menyimpan data yang terkait dalam satu struktur dan memudahkan untuk pengelolaannya.

### 3. Tipe Data Koleksi 

```C++
#include <iostream>
#include <array>
using namespace std;

int main() {
    // Deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;
    // Mencetak array dengan tab
    cout << "Isi array pertama : " << nilai[0] << endl;
    cout << "Isi array kedua : " << nilai[1] << endl;
    cout << "Isi array ketiga : " << nilai[2] << endl;
    cout << "Isi array keempat : " << nilai[3] << endl;
    cout << "Isi array kelima : " << nilai[4] << endl;
    return 0;
}
```
Kode di atas menunjukkan cara sederhana untuk menyimpan data dalam array yang kemudian dicetaknya. Kode tersebut hanya menggunakan 5 elemen dari array nilai dan dapat mengubah ukuran array untuk menyimpan lebih banyak atau lebih sedikit data. Selain itu, bisa menggunakan loop for untuk mencetak isi array dengan efisien dan lebih mudah, juga bisa menambahkan operasi lain pada array, seperti mencari data, mengurutkan data, dan lain sebagainya.

## Unguided 

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

```C++
#include <iostream>
using namespace std;

// Fungsi untuk menghitung luas segitiga
float hitungLuasSegitiga(float alas, float tinggi) {
    return 0.5 * alas * tinggi;
}

int main() {
    float alas, tinggi;
    
    // Meminta input dari pengguna
    cout << "Masukkan panjang alas segitiga: ";
    cin >> alas;
    cout << "Masukkan tinggi segitiga: ";
    cin >> tinggi;

    // Memanggil fungsi hitungLuasSegitiga dan menampilkan hasil
    float luas = hitungLuasSegitiga(alas, tinggi);
    cout << "Luas segitiga adalah: " << luas << " satuan persegi." << endl;

    return 0;
}
```

### Output
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/8c5ac939-e791-4018-8a7e-450f24b13f03)

### Full code screenshot
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/f042ffbd-ded5-4a75-ad5f-31bf37ff1703)

Kode di atas menunjukkan bahwa tipe data primitif seperti float digunakan untuk menyimpan nilai sederhana seperti panjang dan tinggi. Selain itu, penggunaan fungsi dapat mempermudah pengelolaan kode dan memisahkan logika perhitungan dari bagian utama program.

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya.

```C++
#include <iostream>
#include <string>
using namespace std;

// Definisikan class Film
class Film {
private:
    string title;
    int releaseYear;

public:
    // Constructor
    Film(string t, int year) : title(t), releaseYear(year) {}

    // Getter untuk judul film
    string getTitle() {
        return title;
    }

    // Getter untuk tahun rilis
    int getReleaseYear() {
        return releaseYear;
    }
};

// Definisikan struct Film
struct FilmStruct {
    string title;
    int releaseYear;
};

int main() {
    // Membuat objek Film menggunakan class
    Film myFilm("Anne with an A", 2019);

    // Membuat variabel FilmStruct menggunakan struct
    FilmStruct myFilmStruct;
    myFilmStruct.title = "Lttle Women";
    myFilmStruct.releaseYear = 1994;

    // Menampilkan data anggota dari class
    cout << "\nFilm (Class):" << endl;
    cout << "Judul film: " << myFilm.getTitle() << endl;
    cout << "Tahun rilis: " << myFilm.getReleaseYear() << endl;

    // Menampilkan data anggota dari struct
    cout << "\nFilm (Struct):" << endl;
    cout << "Judul film: " << myFilmStruct.title << endl;
    cout << "Tahun rilis: " << myFilmStruct.releaseYear << endl;

    return 0;
}
```
### Output
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/41a9f4ac-8d21-4e1f-b3f0-fff2a1dbae2a)

### Full code screenshot
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/23d948eb-c8f7-47f4-bffe-18396d04d0ab)

Kode di atas mendemonstrasikan penggunaan class dan struct untuk mendefinisikan struktur data "Film" dengan dua anggota: judul dan tahun rilis. Class Film mendefinisikan class bernama Film dengan dua anggota data private: title (string) dan releaseYear (int). Class memiliki constructor yang menerima judul dan tahun rilis sebagai parameter dan menginisialisasi anggota data. Class memiliki dua getter public: getTitle() dan getReleaseYear() yang mana untuk mengakses anggota data private. Struct pada FilmStruct mendefinisikan struct bernama FilmStruct dengan dua anggota data: title (string) dan releaseYear (int).

Struct tidak memiliki constructor dan anggota data struct diakses secara langsung. Film myFilm("Anne with an A", 2019) membuat objek myFilm dari class Film dengan judul "Anne with an A" dan tahun rilis 2019. myFilmStruct.title = "Lttle Women"; dan myFilmStruct.releaseYear = 1994; mengisi anggota data myFilmStruct secara langsung.

Class dan struct merupakan dua konsep dalam bahasa pemrograman C++ yang dapat memungkinkan untuk mendefinisikan tipe data kustom. Class adalah konstruksi yang memungkinkan untuk membuat tipe data baru dengan data anggota (variabel) dan fungsi anggota (metode). Class digunakan untuk menggambarkan abstraksi data dan mendukung inheritance. Sedangkan dalam struct, data anggota secara default dideklarasikan sebagai public yang mana dapat diakses secara langsung dari luar struct dan biasanya digunakan untuk mengelompokkan beberapa data secara bersamaan tanpa menyertakan metode.


### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map.

```C++
#include <iostream>
#include <map>
using namespace std;

int main()
{
    // penggunaan map dengan key bertipe int dan value bertipe string
    map<int, string> book;
    book[1] = "Tuesdays with Morrie";
    book[2] = "The Magic Library";
    book[3] = "Animal Farm";

    // Menampilkan elemen-elemen dalam map
    for (const auto & pair: book) {
        cout << "Book Title: " << pair.second << endl;
    }

    return 0;
}
```
#### Output:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/9ea3647a-9b95-45b9-8f9c-dc68c095d03b)

#### Full code Screenshot:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/b620a74b-9d0d-4a41-a713-85ccc9a72327)

Kode di atas mendemonstrasikan cara menggunakan map untuk menyimpan data dengan menggunakan key dan value yang berbeda tipe data. "map<int, string> book" untuk mendefinisikan map bernama book yang memetakan integer (id buku) ke string (judul buku). "book[1] = "Tuesdays with Morrie"" utnuk menambahkan data baru ke map dengan key 1 dan value "Tuesdays with Morrie". Kemudian dua baris berikutnya untuk menambahkan data lain ke map dengan cara yang sama.

Map adalah struktur data yang sangat berguna untuk menyimpan data dengan key dan mengaksesnya secara efisien. Map menawarkan fleksibilitas yang lebih tinggi dalam hal tipe data. Sedangkan Array untuk menyimpan data yang berurutan dan mengaksesnya dengan indeks numerik. Array lebih efisien untuk operasi CRUD pada indeks tertentu.

## Kesimpulan
Terdapat 3 tipe data yaitu tipe data primitif, tipe data abstrak, dan tipe data koleksi. Tipe data primitif digunakan untuk menyimpan nilai sederhana seperti bilangan, karakter, dan nilai boolean. Contohnya program kalkulator sederhana. Class dan struct digunakan untuk mendefinisikan struktur data kustom dengan anggota data dan fungsi. Contohnya program data film. Map digunakan untuk menyimpan data dengan key dan mengaksesnya secara efisien. Contohnya program data buku.

## Referensi
[1] A. Zein and E. S. Eriana, Algoritma dan Struktur Data, Tangerang Selatan: Unpam Press, 2022.

[2] A. Sindar, Struktur Data dan Algoritma dengan C++, Serang: CV. AA. RIZKY, 2019. 
