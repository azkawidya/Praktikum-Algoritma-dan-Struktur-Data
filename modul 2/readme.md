# <h1 align="center">Laporan Praktikum Modul Array</h1>
<p align="center">Azka Widya Rahmawati</p>

## Dasar Teori
Array adalah variabel yang menyimpan kumpulan data-data dengan tipe yang sama di dalam urutan tertentu dan menggunakan sebuah nama yang juga sama [1]. Setiap elemen yang ada di dalam array dapat diakses secara langsung menggunakan indeksnya. Indeks array secara default selalu dimulai dari 0.

### Array Satu Dimensi
Array satu dimensi adalah array yang terdiri dari n buah kolom dan setiap elemen dari array dapat diakses melalui indeks yang ada pada array tersebut [2].

Contoh:
```C++
#include <iostream>
using namespace std;
int main() {
int arr[5] = {9, 3, 5, 2, 1}; //deklarasi array
cout<< arr[1] << endl;
cout<< arr[3];
}
``` 

### Array Dua Dimensi
Array dua dimensi adalah array yang terdiri dari n buah baris dan m buah kolom, atau array yang mempunyai dua subskrip, yaitu baris dan kolom. Bentuknya dapat berupa tabel atau matriks.
Contoh:
```C++
#include <iostream>
using namespace std;
int main() {
int arr[2][2] = {{3, 2}, {2, 5}};
for (int i=0; i<2; i++) { //baris
for(int j=0; j<2; j++) { //kolom
cout<< arr[i][j] << ends;
};
cout << endl;
};
}
```

### Array Multidimensi
Array multidimensi adalah array yang memiliki lebih dari dua ukuran. Array ini digunakan untuk menyimpan sebuah data yang kompleks, seperti data spasial 3D, data gambar, maupun data lainnya yang membutuhkan organisasi berlapis.
Contoh:
```C++
#include <iostream>
using namespace std;
int main() {
  int data_3d[2][3][4] = {
    {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12}
    },
    {
      {13, 14, 15, 16},
      {17, 18, 19, 20},
      {21, 22, 23, 24}
    }
  };

  // Mengakses dan mencetak elemen array
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 4; k++) {
        cout << "Data 3D [" << i << "][" << j << "][" << k << "]: " << data_3d[i][j][k] << endl;
      }
    }
  }

  return 0;
}
```

### Array Empat Dimensi
Array empat dimensi merupakan struktur data yang lebih kompleks dibandingkan array satu, dua, dan tiga dimensi. Array ini digunakan untuk menyimpan sebuah data yang sangat kompleks maupun terstruktur dalam banyak dimensi. Contoh: 
int arr [5][4][6][6];

### Array Lima Dimensi
Array lima dimensi ini jarang digunakan dibandingkan array empat dimensi, umumnya digunakan untuk menyimpan sebuah data yang sangat kompleks dan berukuran besar.
Contoh: int arr [2][4][4][3][3];


## Guided 

### 1. Program Input Array Tiga Dimensi

```C++
#include <iostream>
using namespace std;
// program input array 3 dimensi
int main()
{
    // deklarasi array
    int arr[2][3][3];
    // input elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x << "]["<< y << "][" << z << "] = ";
                cin >> arr [x][y][z];
            }
        }
        cout << endl;
    }
    // output array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Data Array[" << x << "]["<< y << "]["<< z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;
    // tampilan array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}
```
Kode di atas digunakan untuk mengimplementasikan input dan output array tiga dimensi dengan mendeklarasikan array menggunakan nama arr. Array ini memiliki ukuran 2 x 3 x 3 (dua lapis, masing-masing lapis berisi matriks 3 x 3). Selanjutnya, menggunakan tiga perulangan bersarang (nested loops) untuk mengisi setiap elemen-elemen array. Loop pertama (x) berjalan dari 0 hingga 1 karena memiliki dua lapis, loop kedua (y) berjalan dari 0 hingga 2, dan loop ketiga (z) berjalan dari 0 hingga 2. Pada setiap iterasi, pengguna meminta untuk memasukkan nilai untuk elemen arr [x][y][z]. Setelah mengisi elemen-elemen array, digunakan tiga perulangan bersarang lagi untuk menampilkan nilai-nilai yang sebelumnya sudah dimasukkan. Kemudian mencetak pesan “Data Array [x][y][z] = nilai” untuk setiap elemennya. 

### 2. Program Mencari Nilai Maksimal pada Array
```C++
#include <iostream>
using namespace std;
int main()
{
    int maks, a, i = 1, lokasi;
    cout << "Masukkan panjang array: ";
    cin >> a;
    int array[a];
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }
    maks = array[0];
    for (i = 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
}
```
Kode di atas digunakan untuk menghitung atau mencari nilai maksimum dan minimun dari elemen-elemen dalam sebuah array. Pada variabel "maks" digunakan untuk menyimpan nilai maksimum dari array, "a" digunakan untuk menyimpan panjang array, "i" digunakan untuk iterasi loop dan "lokasi" digunakan untuk menyimpan lokasi elemen array dengan nilai maksimum. Pada loop for digunakan untuk mencari nilai maksimum dalam array yang membandingkan setiap elemen array dengan variabel maks. Jika elemen array lebih besar dari maks, maka nilai elemen array tersebut akan disimpan ke variabel maks dan lokasi elemen tersebut akan disimpan ke variabel lokasi.

## Unguided 

### 1. Buatlah program untuk menampilkan Output dengan data yang diinputkan oleh user!

```C++
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  // deklarasi variabel
  int n;
  vector<int> data;

  // input jumlah data
  cout << "Masukkan jumlah data: ";
  cin >> n;

  // input data dari user
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    data.push_back(x); // menambahkan elemen x ke akhir vector data
  }

  // tampilkan data array
  cout << "Data Array: ";
  for (int i = 0; i < n; i++)
  {
    cout << data[i] << " ";
  }
  cout << endl;

  // tampilkan nomor genap
  cout << "Nomor Genap: ";
  for (int i = 0; i < n; i++)
  {
    if (data[i] % 2 == 0) // memeriksa apakah elemen ke-i dari vector data adalah bilangan genap
    {
      cout << data[i] << " ";
    }
  }
  cout << endl;

  // tampilkan nomor ganjil
  cout << "Nomor Ganjil: ";
  for (int i = 0; i < n; i++) 
  {
    if (data[i] % 2 == 1) // memeriksa apakah elemen ke-i dari vector data adalah bilangan ganjil
    {
      cout << data[i] << " ";
    }
  }
  cout << endl;

  return 0;
}
```
#### Output:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/32afe1ba-a8d2-44d3-920a-7796c117c62d)

Kode di atas digunakan untuk memasukkan data, menampilkan data, dan memisahkan nomor genap dan ganjil dari sekumpulan data. Pada variabel n digunakan untuk menyimpan jumlah data dan variabel data digunakan untuk menyimpan kumpulan data dalam bentuk vector. Program ini menggunakan perulangan untuk meminta pengguna memasukkan n angka. Jika elemen adalah bilangan genap (memiliki sisa bagi 0), maka dicetak sebagai “Nomor Genap”. Jika elemen adalah bilangan ganjil (memiliki sisa bagi 1), maka dicetak sebagai “Nomor Ganjil”.

#### Full code Screenshot:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/725798fc-56d8-4d62-9a6f-c39a3026cadb)

### 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

```C++
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  // mendeklarasi variabel
  int n, m, o;
  vector<vector<vector<int>>> data;

  // menginput jumlah elemen di setiap dimensi
  cout << "Masukkan jumlah elemen di dimensi pertama: ";
  cin >> n;
  cout << "Masukkan jumlah elemen di dimensi kedua: ";
  cin >> m;
  cout << "Masukkan jumlah elemen di dimensi ketiga: ";
  cin >> o;

  // mendeklarasi array tiga dimensi
  data.resize(n); // mengubah ukuran data untuk memiliki n elemen
  for (int i = 0; i < n; i++)
  {
    data[i].resize(m); // mengubah ukuran elemen ke-i dari data untuk memiliki m elemen
    for (int j = 0; j < m; j++)
    {
      data[i][j].resize(o); // mengubah ukuran elemen ke-j dari data[i] untuk memiliki o elemen
    }
  }

  // menginput data dari user
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      for (int k = 0; k < o; k++)
      {
        cin >> data[i][j][k];
      }
    }
  }

  // menampilkan data array
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      for (int k = 0; k < o; k++)
      {
        cout << data[i][j][k] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}
```
#### Output:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/3d5037ad-357e-4f8f-8a78-8457882cf57d)

Kode di atas digunakan untuk mengimplementasikan array tiga dimensi. n, m, dan o merupakan variabel yang menyimpan jumlah elemen dalam masing-masing dimensi array. Pengguna akan diminta memasukkan jumlah elemen di dimensi pertama, kedua, dan ketiga. Kemudian data diubah ukurannya untuk memiliki n elemen pada dimensi pertama. Setiap elemen ke-i dari data diubah ukurannya untuk memiliki m elemen pada dimensi kedua dan setiap elemen ke-j dari data [i] diubah ukurannya untuk memiliki o elemen pada dimensi ketiga. Program akan meminta pengguna memasukkan nilai-nilai untuk setiap elemen array dan data dimasukkan ke dalam data [i][j][k].

#### Full code Screenshot:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/3078dc7c-30cc-4687-9280-d27347da976f)

### 3. Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!

```C++
#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // mendeklarasi variabel
  int n;
  vector<int> data;

  // menginput jumlah data
  cout << "Masukkan jumlah data: ";
  cin >> n; // menerima input jumlah data dari pengguna dan disimpan di variabel n

  // menginput data dari user
  for (int i = 0; i < n; i++) // menerima input data sebanyak n kali
  {
    int x;
    cin >> x;
    data.push_back(x); // menambahkan data ke vector
  }

  // mencari nilai maksimum
  int maksimum = data[0]; 
  for (int i = 1; i < n; i++)
  {
    if (data[i] > maksimum)
    {
      maksimum = data[i];
    }
  }

  // mencari nilai minimum
  int minimum = data[0]; 
  for (int i = 1; i < n; i++)
  {
    if (data[i] < minimum)
    {
      minimum = data[i];
    }
  }

  // menghitung nilai rata-rata
  int total = 0;
  for (int i = 0; i < n; i++)
  {
    total += data[i]; // menghitung jumlah total dari semua elemen di dalam vector data
  }
  float rata_rata = (float)total / n; // menghitung nilai rata-rata dari elemen-elemen di dalam vector data

  // menampilkan menu
  int pilihan;
  do // loop do-while untuk menampilkan menu dan memproses pilihan pengguna
  {
    cout << "Menu:" << endl;
    cout << "1. Tampilkan nilai maksimum" << endl;
    cout << "2. Tampilkan nilai minimum" << endl;
    cout << "3. Tampilkan nilai rata-rata" << endl;
    cout << "4. Keluar" << endl;
    cout << "Masukkan pilihan: ";
    cin >> pilihan;

    switch (pilihan) // mengeksekusi blok kode berdasarkan pilihan menu yang diinputkan oleh pengguna
    {
      case 1:
        cout << "Nilai maksimum: " << maksimum << endl;
        break;
      case 2:
        cout << "Nilai minimum: " << minimum << endl;
        break;
      case 3:
        cout << "Nilai rata-rata: " << rata_rata << endl;
        break;
      case 4:
        cout << "Terima kasih!" << endl;
        break;
      default:
        cout << "Pilihan tidak valid!" << endl;
    }
  } while (pilihan != 4);

  return 0;
}
```
#### Output:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/211598a3-09cc-4c84-835d-a3aa38a654f0)


Kode di atas digunakan untuk melakukan beberapa operasi pada data yang dimasukkan oleh pengguna. Variabel maksimum dan minimum diinisialisasikan dengan nilai dari elemen pertama pada vector data. Program melakukan perulangan untuk membandingkan setiap elemen vector dengan nilai maksimum dan minimum. Jika nilai elemen lebih besar dari maksimum, maka nilai maksimum diperbarui. Jika nilai elemen lebih kecil dari minimum, maka nilai minimum diperbarui. Program juga menghitung total dari semua elemen dalam vector data dengan nilai rata-rata dihitung dengan membagi total dengan n.
Kemudian program akan menampilkan menu pilihan kepada pengguna dan diminta untuk memilih salah satu opsi (tampilkan nilai maksimum, minimum, rata-rata, atau keluar). Program akan mengeksekusi blok kode sesuai dengan pilihan pengguna.


#### Full code Screenshot:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/bb1fe504-5740-4ce8-a447-805304f85aaf)

## Kesimpulan
Array merupakan struktur data yang penting dalam sebuah pemrograman untuk menyimpan sekumpulan data dengan tipe yang sama. Array dapat memiliki satu dimensi, dua dimensi,  atau lebih (array multidimensi).
Array memungkinkan untuk dapat mengakses data secara langsung dengan menggunakan indeks. Berbagai operasi juga dapat dilakukan pada array, seperti mencari nilai maksimum, minimum, rata-rata, dan lain sebagainya.

## Referensi

[1] 	M. F. Rohmah and R. E. Cahyono, Teori dan Aplikasi Algoritma Pemrograman dengan Bahasa C dan C++, Penerbit NEM, 2022. 

[2] 	A. Huda, N. Ardi and A. Muabi, Pengantar Coding Berbasis C/C++, UNP PRESS, 2021. 