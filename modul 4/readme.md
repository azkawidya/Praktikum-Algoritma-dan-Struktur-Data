# <h1 align="center">Laporan Praktikum Modul Algoritma Searching</h1>
<p align="center">Azka Widya Rahmawati</p>

## Dasar Teori
Algoritma searching adalah proses identifikasi lokasi spesifik atau mencari nilai tertentu dari suatu item dalam struktur data. Misalnya, bisa dalam array, tree, atau graph. Algoritma ini akan mencari item yang sesuai berdasarkan kunci pencarian yang diberikan, kemudian akan menampilkan hasilnya jika ditemukan atau memberikan pesan bahwa item tersebut tidak ada dalam struktur data jika tidak ditemukan [1]. Hasil pencarian adalah salah satu dari tiga keadaan ini: data ditemukan, data ditemukan lebih dari satu, atau data tidak ditemukan. 

### Sequential Search
Jenis algoritma ini merupakan algoritma pencarian yang paling sederhana. Sequential search, atau yang dikenal juga sebagai linear search, bekerja dengan cara memeriksa setiap elemen dalam data set secara berturut-turut hingga menemukan elemen yang dicari atau hingga mencapai akhir set data.

Cara kerja sequential search:

• Membandingkan setiap elemen pada array satu per satu secara 
berurutan.

• Proses pencarian dimulai dari indeks pertama hingga indeks terakhir.

• Proses pencarian akan berhenti apabila data ditemukan. Jika hingga 
akhir array data masih juga tidak ditemukan, maka proses pencarian 
tetap akan dihentikan.

• Proses perulangan pada pencarian akan terjadi sebanyak jumlah N 
elemen pada array.

### Binary Search
Algoritma binary search merupakan salah satu algoritma pencarian data yang biasa digunakan untuk array yang berpola terurut. Algortima ini juga termasuk ke dalam interval search. Teknik pencarian yang digunakan pada algoritma ini yaitu dengan cara berulang kali membagi jumlah data menjadi dua bagian sehingga memperkecil lokasi pencarian suatu data hingga dapat ditemukan. Biasanya, algoritma ini hanya digunakan untuk mencari suatu key pada array dengan jumlah elemen yang banyak dan kompleksitas dari algoritma ini adalah O(log n) [2]. Dalam penerapan algoritma ini sering digabungkan dengan algoritma sorting karena data yang akan digunakan harus sudah terurut terlebih dahulu.


## Guided 

### 1. Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data
```C++
#include <iostream>
using namespace std;

int main() {
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;

    //algoritma sequential search
    for (i = 0; i < n; i++) {
        if (data[i] == cari) {
            ketemu = true;
            break;
        }
    }
    cout << "\t Program Sequential Search Sederhana\n" << endl;
    cout << "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;

    if (ketemu) {
        cout << "\nangka " << cari << " ditemukan pada indeks ke-" << i << endl;
    }
    else {
        cout << cari << "tidak dapat ditemukan pada data." << endl;
    }

    return 0;
}
```

### 2. Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search
```C++
#include <iostream>
#include <iomanip>
using namespace std;

int bil_data[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

void selection_sort() {
    int temp, min, i, j;
    for(i = 0; i < 7; i++) {
        min = i;
        for(j = i + 1; j < 7; j++) {
            if(bil_data[j] < bil_data[min]) {
                min = j;
            }
        }
        temp = bil_data[i];
        bil_data[i] = bil_data[min];
        bil_data[min] = temp;
    }
}

void binary_search() {
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = 6;
    while (b_flag == 0 && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if(bil_data[tengah] == cari) {
            b_flag = 1;
            break;
        } else if(bil_data[tengah] < cari) {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }
    if(b_flag == 1) {
        cout << "\n Data ditemukan pada index ke-" << tengah << endl;
    } else {
        cout << "\n Data tidak ditemukan\n";
    }
}

int main() {
    cout << "\t BINARY SEARCH\n";
    cout << "\n Data : ";
    // tampilkan data awal
    for(int x = 0; x < 7; x++) {
        cout << setw(3) << bil_data[x];
    }
    cout << endl;
    cout << "\n Masukkan data yang ingin Anda cari : ";
    cin >> cari;
    cout << "\n Data diurutkan : ";
    // urutkan data dengan selection sort
    selection_sort();
    // tampilkan data setelah diurutkan
    for(int x = 0; x < 7; x++) {
        cout << setw(3) << bil_data[x];
    }
    cout << endl;
    binary_search();
    return 0;
}
```

## Unguided 

### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!
```C++
#include <iostream>
#include <algorithm>
using namespace std;

// Fungsi untuk melakukan binary search pada string
int binarySearch(const string& arr, char x, int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid; // Huruf ditemukan
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // Huruf tidak ditemukan
}
int main()
{
    string kalimat;
    char huruf;
    
    // Menginputkan kalimat dan huruf yang dicari
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);
    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> huruf;
    
    // Sort kalimat terlebih dahulu sebelum binary search
    sort(kalimat.begin(), kalimat.end());
    
    // Binary search
    int result = binarySearch(kalimat, huruf, 0, kalimat.length() - 1);
    if (result != -1)
        cout << "Huruf '" << huruf << "' ditemukan pada indeks ke-" << result << endl;
    else
        cout << "Huruf '" << huruf << "' tidak ditemukan dalam kalimat." << endl;
    
    return 0;
}
```
#### Output:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/48a11fb7-4fd8-415e-a05a-636726ca3526)

Kode di atas digunakan untuk mengurutkan karakter dalam kalimat yang diinput, kemudian melakukan pencarian binary search untuk huruf yang ingin dicari. Jika huruf tersebut ada di dalam kalimat, maka program akan menampilkan indeks di mana huruf itu ditemukan. Jika tidak, program akan memberitahu bahwa huruf tersebut tidak ada dalam kalimat. Kalimat harus diurutkan terlebih dahulu karena binary search membutuhkan data yang terurut.

#### Full code Screenshot:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/ebb0f1b4-8a0b-4cec-86ee-19ac6c17f5b7)


### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!
```C++
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string kalimat;
    int jumlah_vokal = 0;
    
    // Menginput kalimat
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);
    
    // Menghitung jumlah huruf vokal
    for (int i = 0; i < kalimat.length(); ++i)
    {
        char huruf = tolower(kalimat[i]); // Mengubah huruf menjadi lowercase untuk memudahkan dalam pengecekan
        if (huruf == 'a' || huruf == 'e' || huruf == 'i' || huruf == 'o' || huruf == 'u')
        {
            ++jumlah_vokal;
        }
    }
    
    // Menampilkan hasil
    cout << "Jumlah huruf vokal dalam kalimat adalah " << jumlah_vokal << endl;
    
    return 0;
}
```
#### Output:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/d89e9429-dfa4-46e0-be92-2b8c300dc0df)

Kode di atas digunakan untuk menghitung banyaknya huruf vokal dalam sebuah kalimat. Program ini akan meminta pengguna untuk memasukkan sebuah kalimat yang kemudian program akan mengiterasi setiap karakter dalam kalimat tersebut dan mengecek apakah karakter itu adalah huruf vokal (a, e, i, o, u). Jika ya, maka program akan menambahkan jumlah huruf vokal. Setelah selesai mengiterasi, program akan menampilkan jumlah total huruf vokal yang ada dalam kalimat tersebut.

#### Full code Screenshot:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/c2113471-0ddd-4dfe-a367-98fe9958dfdc)

### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!
```C++
#include <iostream>
using namespace std;

// Fungsi untuk melakukan Sequential Search
int sequentialSearch(int arr[], int size, int key)
{
    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == key)
        {
            ++count;
        }
    }
    return count;
}

int main()
{
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int dataSize = sizeof(data) / sizeof(data[0]);
    int target = 4;

    int result = sequentialSearch(data, dataSize, target);

    cout << "Jumlah angka 4 dalam data adalah " << result << endl;

    return 0;
}
```
#### Output:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/b2874ad1-09f0-4067-9914-1a7ac2ce828d)

Kode di atas digunakan untuk menghitung berapa banyak angka 4 dengan menggunakan algoritma Sequential Search. Dari kode program di atas terdapat data berupa angka-angka: 9, 4, 1, 4, 7, 10, 5, 4, 12, dan 4. Program akan menghitung berapa kali angka 4 muncul dalam data tersebut dengan mengiterasi setiap elemen dan membandingkannya dengan angka target, yaitu 4. Hasilnya akan menampilkan jumlah angka 4 dalam data.

#### Full code Screenshot:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/63a0a40e-33c6-4f61-b29c-6ed011532581)

## Kesimpulan
Algoritma searching adalah proses untuk menemukan atau mencari nilai tertentu dalam suatu struktur data. Ada dua jenis algoritma pencarian yang umum digunakan:
1. Sequential Search

    Sequential search adalah algoritma pencarian yang paling sederhana. Algoritma ini bekerja dengan cara memeriksa setiap elemen dalam struktur data secara berurutan hingga menemukan elemen yang dicari atau hingga mencapai akhir struktur data. Algoritma ini sederhana dan mudah dipahami, selain itu tidak memerlukan struktur data yang terurut. Namun, algoritma ini lambat untuk struktur data yang besar dan tidak efisien untuk pencarian data yang sering dilakukan.

2. Binary Search

    Binary search adalah algoritma pencarian yang lebih efisien daripada sequential search. Algoritma ini hanya dapat digunakan pada struktur data yang terurut dan bekerja dengan cara membagi struktur data menjadi dua bagian secara berulang hingga menemukan elemen yang dicari. Algoritma ini cepat untuk struktur data yang besar dan efisien untuk pencarian data yang sering dilakukan. Namun, algoritma ini memerlukan struktur data yang terurut dan lebih kompleks daripada sequential search.

## Referensi
[1] "Apa itu algoritma searching," Algoritme.id, 25 August 2023. [Online]. Available: https://algoritme.id/apa-itu-algoritma-searching/. [Accessed 20 April 2024].

[2] A. Zein and E. S. Eriana, Algoritma dan Struktur Data, Tagerang Selatan: Unpam Press, 2022.

