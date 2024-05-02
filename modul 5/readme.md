# <h1 align="center">Laporan Praktikum Modul Struct dan Implementasi</h1>
<p align="center">Azka Widya Rahmawati</p>

## Dasar Teori
Struct adalah tipe data bentukan yang berisi kumpulan variabel yang ada dalam satu nama yang sama dan terdapat kaitannya satu sama lain. Berbeda dengan array yang hanya berupa kumpulan variabel bertipe data sama, struct bisa memiliki variabel-variabel yang bertipe data sama atau berbeda, struct juga bisa menyimpan variabel yang bertipe data array atau struct itu sendiri [1]. Variabel-variabel yang menjadi anggota struct ini dapat disebut dengan elemen struct. Penggunaan struct dapat memudahkan pemetaan entitas dari sebuah kehidupan yang nyata maupun suatu model dengan penyimpanan dan handling dalam C++ [2].

## Guided 

### 1. Buatlah sebuah struktur dengan nama buku yang berisi judul_buku, pengarang, penerbit, tebal_halaman, harga_buku. Isi dengan nilai kemudian tampilkan.
```C++
#include <iostream>
using namespace std;

struct Buku {
    string judul_buku;
    string pengarang;
    string penerbit;
    int tebal_halaman;
    double harga_buku;
}; Buku buku1, buku2;

int main() {
    // Membuat dan mengisi struktur buku
    Buku buku1;
    buku1.judul_buku = "Anne of Green Gables";
    buku1.pengarang = "Lucy Maud Montgomery";
    buku1.penerbit = "Gramedia Pustaka Utama";
    buku1.tebal_halaman = 412;
    buku1.harga_buku = 65000;

    Buku buku2;
    buku2.judul_buku = "Tuesdays with Morrie";
    buku2.pengarang = "Mitch Albom";
    buku2.penerbit = "Knopf Doubleday Publishing Group";
    buku2.tebal_halaman = 192;
    buku2.harga_buku = 126000;

    // Menampilkan informasi buku
    cout << "Judul Buku     : " << buku1.judul_buku << endl;
    cout << "Pengarang      : " << buku1.pengarang << endl;
    cout << "Penerbit       : " << buku1.penerbit << endl;
    cout << "Tebal Halaman  : " << buku1.tebal_halaman << " halaman" << endl;
    cout << "Harga Buku     : Rp" << buku1.harga_buku << endl;

    cout << "Judul Buku     : " << buku2.judul_buku << endl;
    cout << "Pengarang      : " << buku2.pengarang << endl;
    cout << "Penerbit       : " << buku2.penerbit << endl;
    cout << "Tebal Halaman  : " << buku2.tebal_halaman << " halaman" << endl;
    cout << "Harga Buku     : Rp" << buku2.harga_buku << endl;

    return 0;
}
```
Kode di atas digunakan untuk mendemonstrasikan bagaimana struct dapat digunakan untuk menyimpan dan mengisi data dari dua buah buku, kemudian menampilkan informasi buku tersebut berupa judul buku, pengarang, penerbit, tebal halaman, dan harga buku. 

### 2. Buatlah sebuah struktur dengan skema seperti dibawah, isi dengan nilai kemudian jalankan.
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/93d451af-9dc9-4376-a85e-e63faf7d1bf2)

```C++
#include <iostream>
using namespace std;

struct Hewan {
    string nama_hewan;
    string jenis_kelamin;
    string kembangbiak;
    string pernapasan;
    string tempat_hidup;
    bool karnivora;
}; 

struct Hewan_drt {
    Hewan info_hewan;
    int jumlah_kaki;
    bool apakah_menyusui;
    string suara;
};
Hewan_drt hewan1;

struct Hewan_lt {
    Hewan info_hewan;
    string bentuk_sirip;
    string pertahanan_diri;
};
Hewan_lt hewan2;

int main() {
    // Hewan 1 (daratan)
    hewan1.info_hewan.nama_hewan = "Kucing";
    hewan1.info_hewan.jenis_kelamin = "J";
    hewan1.info_hewan.kembangbiak = "Melahirkan";
    hewan1.info_hewan.pernapasan = "Paru-paru";
    hewan1.info_hewan.tempat_hidup = "Daratan";
    hewan1.info_hewan.karnivora = true;
    hewan1.jumlah_kaki = 4;
    hewan1.apakah_menyusui = true;
    hewan1.suara = "Meow";

    // Hewan 2 (lautan)
    hewan2.info_hewan.nama_hewan = "Penyu";
    hewan2.info_hewan.jenis_kelamin = "B";
    hewan2.info_hewan.kembangbiak = "Bertelur";
    hewan2.info_hewan.pernapasan = "Paru-paru dan insang";
    hewan2.info_hewan.tempat_hidup = "Lautan";
    hewan2.info_hewan.karnivora = false;
    hewan2.bentuk_sirip = "Sirip dan Ekor";
    hewan2.pertahanan_diri = "Cangkang yang kuat";

    cout << "\tHewan Darat " << endl;
    cout << "Nama Hewan         : " << hewan1.info_hewan.nama_hewan << endl;
    cout << "Jenis Kelamin      : " << hewan1.info_hewan.jenis_kelamin << endl;
    cout << "Kembangbiak        : " << hewan1.info_hewan.kembangbiak << endl;
    cout << "Alat Pernapasan    : " << hewan1.info_hewan.pernapasan << endl;
    cout << "Tempat Hidup       : " << hewan1.info_hewan.tempat_hidup << endl;
    cout << "Karnivora          : " << hewan1.info_hewan.karnivora << endl;
    cout << "Jumlah Kaki        : " << hewan1.jumlah_kaki << endl;
    cout << "Apakah Menyusui?   : " << hewan1.apakah_menyusui << endl;
    cout << "Suara              : " << hewan1.suara << endl;

    cout << "\tHewan Laut " << endl;
    cout << "Nama Hewan         : " << hewan2.info_hewan.nama_hewan << endl;
    cout << "Jenis Kelamin      : " << hewan2.info_hewan.jenis_kelamin << endl;
    cout << "Kembangbiak        : " << hewan2.info_hewan.kembangbiak << endl;
    cout << "Alat Pernapasan    : " << hewan2.info_hewan.pernapasan << endl;
    cout << "Tempat Hidup       : " << hewan2.info_hewan.tempat_hidup << endl;
    cout << "Apakah Karnivora?  : " << hewan2.info_hewan.karnivora << endl;
    cout << "Bentuk Sirip       : " << hewan2.bentuk_sirip << endl;
    cout << "Pertahanan Diri    : " << hewan2.pertahanan_diri << endl;
}
```
Kode di atas digunakan untuk mengorganisir data-data yang terkait ke dalam satu unit. Dalam kode program di atas mendefinisikan struktur data untuk hewan darat dan hewan laut, kemudian mengisi data dua jenis hewan tersebut dan menampilkan informasinya. 

## Unguided 

### 1. Modifikasi tugas guided pertama, sehingga setiap item yang terdapat pada struct buku berupa array yang berukuran 5, isi dengan data kemudian tampilkan.
```C++
#include <iostream>
#include <string>

using namespace std;

// Mendefinisikan struktur buku dengan array
struct buku {
    string judul_buku[5];
    string pengarang[5];
    string penerbit[5];
    int tebal_halaman[5];
    int harga_buku[5];
};

int main() {
    // Mendeklarasikan variabel BukuFavorit dengan tipe buku
    buku BukuFavorit;

    // Mengisi data ke dalam array di variabel BukuFavorit
    BukuFavorit.judul_buku[0] = "Tuesdays with Morrie";
    BukuFavorit.judul_buku[1] = "Life of Pi";
    BukuFavorit.judul_buku[2] = "The Sorcery Little Magacal Piya";
    BukuFavorit.judul_buku[3] = "Jakarta Sebelum Pagi";
    BukuFavorit.judul_buku[4] = "Northanger Abbey";

    BukuFavorit.pengarang[0] = "Mitch Albom";
    BukuFavorit.pengarang[1] = "Yann Martel";
    BukuFavorit.pengarang[2] = "Cindyana H.";
    BukuFavorit.pengarang[3] = "Ziggy Zezsyazeoviennazabrizkie";
    BukuFavorit.pengarang[4] = "Jane Austen";

    BukuFavorit.penerbit[0] = "Sinar Star Book";
    BukuFavorit.penerbit[1] = "Gramedia Pustaka Utama";
    BukuFavorit.penerbit[2] = "Fantasious";
    BukuFavorit.penerbit[3] = "Grasindo";
    BukuFavorit.penerbit[4] = "Gramedia Pustaka Utama";

    BukuFavorit.tebal_halaman[0] = 192;
    BukuFavorit.tebal_halaman[1] = 448;
    BukuFavorit.tebal_halaman[2] = 476;
    BukuFavorit.tebal_halaman[3] = 280;
    BukuFavorit.tebal_halaman[4] = 328;

    BukuFavorit.harga_buku[0] = 125000;
    BukuFavorit.harga_buku[1] = 88000;
    BukuFavorit.harga_buku[2] = 99500;
    BukuFavorit.harga_buku[3] = 92000;
    BukuFavorit.harga_buku[4] = 59000;

    // Menampilkan informasi BukuFavorit
    cout << "\tBuku Favorit Saya" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "\tBuku ke-" << i + 1 << endl;
        cout << "\tJudul Buku    : " << BukuFavorit.judul_buku[i] << endl;
        cout << "\tPengarang     : " << BukuFavorit.pengarang[i] << endl;
        cout << "\tPenerbit      : " << BukuFavorit.penerbit[i] << endl;
        cout << "\tTebal Halaman : " << BukuFavorit.tebal_halaman[i] << " halaman" << endl;
        cout << "\tHarga Buku    : Rp " << BukuFavorit.harga_buku[i] << endl << endl;
    }

    return 0;
}
```
#### Output:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/52d6a2d1-136f-4514-83fa-dd69237bed11)

Kode di atas digunakan untuk mendefinisikan sebuah struktur bernama buku yang berisi array untuk menyimpan informasi tentang lima buku favorit. Masing-masing lima elemen menampung data dari lima buku yang berbeda-beda. Dalam fungsi main, variabel BukuFavorit dari tipe buku diisi dan dideklarasikan dengan data untuk lima buku favorit. Data yang diisi meliputi judul buku, nama pengarang, nama penerbit, tebal halaman, dan harga buku. Setelah mengisi data, kode tersebut menggunakan loop for untuk menampilkan informasi tentang kelima buku tersebut. Pada outputnya akan menampilkan judul buku, pengarang, penerbit, tebal halaman, dan harga buku dalam format yang terorganisir.

#### Full code Screenshot:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/d6e04188-3ab7-4ab2-bf98-8c5d7e500c2b)

### 2. Apa yang terjadi jika deklarasi variabel struct yang dibuat pada tugas guided I, berjenis Array. Bagaimana cara mengisi data dan menampilkannya?

Jika deklarasi variabel struct yang dibuat berjenis array, berarti akan memiliki kumpulan buku, bukan hanya satu. Setiap elemen dalam array akan mewakili satu buku dengan atribut yang ditentukan. Setiap struct buku diisi dengan informasi yang relevan, kemudian semua informasi tersebut ditampilkan dengan menggunakan loop for. Untuk itu, dapat dilakukan dengan mendeklarasikan struct dengan nama buku yang memiliki beberapa field seperti judul_buku, pengarang, penerbit, tebal_halaman, dan harga_buku. Kemudian, membuat array dari struct buku, misalnya, buku perpustakaan[2]; akan membuat array perpustakaan yang bisa menyimpan informasi untuk 2 buku. Untuk mengisi data ke dalam setiap buku dengan mengakses setiap elemen array dan memberikan nilai ke field yang sesuai. Contohnya, untuk mengisi data buku pertama, menggunakan perpustakaan[0].judul_buku = "Judul Buku"; dan seterusnya untuk field lainnya. Untuk menampilkan data, menggunakan loop (seperti for atau while) untuk melewati setiap elemen array dan mencetak nilai dari setiap field.

## Kesimpulan
Struct merupakan tipe data bentukan yang memungkinkan kita untuk mengelompokkan variabel-variabel yang berkaitan satu sama lain menjadi satu kesatuan. Struct mempunyai beberapa manfaat, yaitu memudahkan dan membantu pengorganisasian data yang terkait, sehingga lebih mudah dikelola dan dipahami, meningkatkan efisiensi kode atau mengurangi redundansi kode dan membuat kode lebih ringkas, lalu meningkatkan keterbacaan kode atau membuat kode lebih mudah dibaca dan dimengerti karena data yang terkait dikelompokkan bersama.

## Referensi
[1] A. B. Kaswar, et al., Mudah Belajar Pemrograman Dasar C++, Aceh: Syiah Kuala University Press, 2021. 

[2] M. T. D. Putra, et al., Belajar Pemrograman Lanjut Dengan C++, Bandung: WIDINA MEDIA UTAMA, 2023. 
