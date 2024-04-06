# <h1 align="center">Laporan Praktikum Modul Sorting</h1>
<p align="center">Azka Widya Rahmawati</p>

## Dasar Teori
Sorting (pengurutan data) secara umum dapat didefinisikan sebagai suatu proses untuk menyusun kembali himpunan obyek dengan menggunakan aturan tertentu. Pengurutan data menjadi salah satu bagian penting dalam ilmu komputer karena waktu yang diperlukan untuk melakukan suatu proses pengurutan perlu dipertimbangkan. Algoritma sorting terbagi menjadi dua jenis, yaitu pengurutan secara urut naik (ascending), data yang nilainya paling kecil sampai data yang nilainya paling besar; dan pengurutan data secara urut turun (descending), data yang mempunyai nilai paling besar sampai paling kecil [1]. Tujuan dari sorting adalah untuk lebih memudahkan dalam pencarian data dikemudian hari.

### Insertion Sort
Insertion sort merupakan algoritma sederhana untuk pengurutan dengan menyisipkan sekumpulan data dengan membandingkan semua data mulai dari data ke 2 dengan data ke 1, lalu mulai dari datanya terus bertambah sampai beberapa jumlah sekumpulan data yang kemudian data tersebut dibandingkan sampai data ke i (sampai elemen array terakhir) diurutkan secara ascending ataupun descending [2].

### Bubble Sort
Bubble Sort merupakan algoritma sorting sederhana dengan cara bergerak berulang dari awal hingga akhir data untuk membandingkan semua elemen yang saling bersebelahan [3]. Jika ditemukannya urutan elemen data yang tidak sesuai berdasarkan kondisi tertentu selama melakukan perbandingan, maka tukar ke dua posisi elemen dari data tersebut.

### Selection Sort
Selection Sort termasuk algoritma sorting sederhana dengan cara membandingkan semua elemen data untuk mencari nilai terkecil atau nilai terbesar disetiap perulangan, kemudian menempatkan nilai terkecil atau nilai terbesar diposisi yang tepat hingga semua elemen terurut [3]. Sebagai contoh pada pengurutan array {5, 6, 4, 8, 12} Selection Sort dimulai dengan menentukan elemen pertama yaitu 5 sebagai nilai min (minimum) kemudian bandingkan 5 dengan 6, karena 6 > 5 maka nilai min tetap 5, selanjutnya bandingkan 5 dengan 4, karena 4 < 5 maka set 4 sebagai nilai min yang baru, kemudian bandingkan 4 dengan 8, karena 8 > 4 maka nilai min tetap 4, selanjutnya bandingkan 4 dengan 12, karena 12 > 4, maka nilai min tetap 4. Setelah perulangan pertama selesai nilai min adalah 4, maka tukarkan 4 dengan 5 sebagai elemen pertama array sehingga urutan data menjadi {4, 6, 5, 8, 12}. Pada perulangan kedua 4 tidak lagi dibandingkan maka set 6 sebagai nilai min dan lanjutkan perbandingan data hingga semua elemen data terurut. 

## Guided 

### 1. Mengurutkan secara ascending untuk data numerik bertipe double menggunakan Algoritma Bubble Sort
```C++
#include <iostream>
using namespace std;

void bubble_sort(double arr[], int length)
{
    bool not_sorted = true;
    int j=0;
    double tmp;
    
    while (not_sorted)
    {
        not_sorted = false;
        j++;
        for (int i = 0; i < length - j; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                not_sorted = true;
            }//end of if
        }//end of for loop
    }//end of while loop
}//end of bubble_sort

void print_array(double a[], int length)
{
    for(int i=0; i<length; i++)
    {
    cout << a[i] << "\t";
    }
    cout << endl;
}

int main()
{
    int length = 5;
    double a[] = {22.1, 15.3, 8.2, 33.21, 99,99};
    
    cout << "Urutan bilangan sebelum sorting: " << endl;
    print_array(a, length);
    
    bubble_sort(a, length);
    
    cout << "\nUrutan bilangan setelah sorting: " << endl;
    print_array(a, length);
}
```
Kode di atas digunakan untuk mengurutkan bilangan dalam array a secara menaik atau ascending (dari yang terkecil ke yang terbesar). #include <iostream> merupakan preprocessor directive yang memasukkan header file <iostream> ke dalam program yang berisi fungsi-fungsi standar untuk input dan output, seperti cout dan cin. using namespace std; memungkinkan untuk menggunakan fungsi-fungsi dari namespace std tanpa harus menuliskan std:: sebelumnya. Pada void bubble_sort(double arr[], int length) digunakan untuk mendeklarasi fungsi bubble_sort yang menerima dua parameter: arr (array bilangan desimal yang akan diurutkan) dan length (panjang array). Pada while (not_sorted) merupakan loop while yang akan terus berjalan selama not_sorted bernilai true. Pada for (int i = 0; i < length - j; i++) merupakan loop for yang akan mengiterasi melalui setiap elemen array hingga length - j dan nilai j akan bertambah setiap kali loop while dijalankan. Pada if (arr[i] > arr[i + 1]), kondisi ini untuk membandingkan elemen saat ini dengan elemen selanjutnya, jika elemen saat ini lebih besar daripada elemen berikutnya, maka mereka akan ditukar. Pada void print_array(double a[], int length) digunakan untuk mendeklarasikan fungsi print_array yang akan mencetak semua elemen array a. Pada double a[] = {22.1, 15.3, 8.2, 33.21, 99.99}; digunakan untuk mendeklarasikan dan menginisialisasikan array a dengan bilangan desimal yang diberikan. Pada bubble_sort(a, length); digunakan untuk memanggil fungsi bubble_sort yang akan mengurutkan array a. Kemudian cout << "\nUrutan bilangan setelah sorting: " << endl; untuk mencetak pesan setelah array diurutkan.

### 2. Mengurutkan karakter secara descending (dari terbesar hingga terkecil) menggunakan Algoritma Insertion Sort
```C++
#include <iostream>
using namespace std;

void insertion_sort(char arr[], int length)
{
    int i, j;
    char tmp;
    
    for (i = 1; i < length; i++)
    {
        j = i;
        while (j > 0 && arr[j - 1] < arr[j])
        {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }//end of while loop
    }//end of for loop
}

void print_array(char a[], int length)
{
    for(int i=0; i<length; i++)
    {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() 
{
    int length = 6;
    char a[length] = {'c', 'f', 'a', 'z', 'd', 'p'};
    
    cout << "Urutan karakter sebelum sorting: " << endl;
    print_array(a, length);
    
    insertion_sort(a, length);
 
    cout << "\nUrutan karakter setelah sorting: " << endl;
    print_array(a, length);
}
```
Kode di atas digunakan untuk mengurutkan karakter-karakter dalam array a secara menurun atau descending (dari yang terbesar ke yang terkecil). Pada #include <iostream> merupakan preprocessor directive yang memasukkan header file <iostream> ke dalam program yang berisi fungsi-fungsi standar untuk input dan output, seperti cout dan cin. Using namespace std; memungkinkan untuk menggunakan fungsi-fungsi dari namespace std tanpa harus menuliskan std:: sebelumnya. Pada void insertion_sort(char arr[], int length) untuk mendeklarasi fungsi insertion_sort yang akan menerima dua parameter: arr (array karakter yang akan diurutkan) dan length (panjang array). for (i = 1; i < length; i++) untuk loop for yang akan mengiterasi melalui setiap elemen array, mulai dari indeks 1 karena elemen pertama dianggap sudah terurut. Pada while (j > 0 && arr[j - 1] < arr[j])digunakan untuk loop while yang akan membandingkan elemen saat ini dengan elemen sebelumnya. Jika elemen saat ini lebih kecil dari elemen sebelumnya, maka akan ditukar. Pada void print_array(char a[], int length) digunakan untuk mendeklarasi fungsi print_array yang akan mencetak semua elemen array a. Pada char a[length] = {'c', 'f', 'a', 'z', 'd', 'p'}; digunakan untuk mendeklarasi dan menginisialisasi array a dengan karakter-karakter yang diberikan. Pada cout << "Urutan karakter sebelum sorting: " << endl; digunakan untuk mencetak pesan sebelum array diurutkan Pada insertion_sort(a, length); digunakan untuk memanggil fungsi insertion_sort untuk mengurutkan array a. Pada cout << "\nUrutan karakter setelah sorting: " << endl; digunakan untuk mencetak pesan setelah array diurutkan. Kemudian, untuk print_array(a, length); digunakan agar dapat memanggil fungsi print_array untuk mencetak array yang sebelumnya sudah diurutkan.

## Unguided 

### 1. Kelas S1 IF 2016 G memiliki 5 mahasiswa. Pada akhir semester mereka menerima lembar Indeks Prestasi Semester (IPS), masing-masing mahasiswa tersebut memiliki IPS sebagai berikut: {3.8, 2.9, 3.3, 4.0, 2.4}. Buatlah program untuk mengurutkan IPS mahasiswa tersebut dari yang terbesar hingga terkecil dengan menggunakan algoritma Selection Sort!
```C++
#include <iostream>
using namespace std;

// untuk menukar posisi dua elemen
void swap(double *xp, double *yp)
{
    double temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// untuk mencetak array
void printArray(double arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Algoritma Selection Sort
void selectionSort(double arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        // menemukan indeks elemen terkecil dalam sub array yang belum diurutkan
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[min_idx])
            {
                min_idx = j;
            }
        }
        // menukar elemen terkecil dengan elemen pertama dalam sub array
        swap(&arr[min_idx], &arr[i]);
    }
}

int main()
{
    int length = 5;
    double ips[] = {3.8, 2.9, 3.3, 4.0, 2.4};

    cout << "Indeks Prestasi Semester sebelum sorting: " << endl;
    printArray(ips, length);

    selectionSort(ips, length);

    cout << "\nIndeks Prestasi Semester setelah sorting: " << endl;
    printArray(ips, length);

    return 0;
}
```
#### Output:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/ee7d9ffe-6cb8-4f68-998e-7c7f758ddf5d)

Kode di atas digunakan untuk mengurutkan nilai Indeks Prestasi Semester (IPS) menggunakan algoritma Selection Sort. Perulangan for pertama di selectionSort berjalan dari elemen pertama hingga elemen terakhir (n-1). Di dalam perulangan, variabel min_idx diinisialisasikan dengan indeks elemen pertama. Perulangan for kedua berjalan dari elemen setelah elemen pertama (i+1) hingga elemen terakhir. Di dalam perulangan kedua, nilai elemen dibandingkan dengan elemen pada indeks min_idx. Jika elemen lebih kecil, maka min_idx diperbarui dengan indeks elemen tersebut. Setelah perulangan kedua selesai, elemen pada indeks min_idx ditukar dengan elemen pertama.

#### Full code Screenshot:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/5a69eb4d-182e-4168-9966-95a5ed99bbba)

### 2. Pak RT memiliki 10 warga dengan nama: siti, situ, sana, ana, ani, caca, cici, dida, dodo, dan dadi. Supaya mudah dalam melakukan pencarian, Pak RT akan mengurutkan nama-nama tersebut sesuai dengan alfabet. Buatlah program untuk membantu Pak RT dengan menggunakan algoritma Bubble Sort! 
```C++
#include <iostream>
#include <string>
using namespace std;

// untuk menukar posisi dua elemen
void swap(string &a, string &b)
{
    string temp = a;
    a = b;
    b = temp;
}

// Algoritma Bubble Sort
void bubbleSort(string arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    int length = 10;
    string names[] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};

    cout << "Nama-nama sebelum sorting: " << endl;
    for (int i = 0; i < length; i++)
    {
        cout << names[i] << " ";
    }
    cout << endl;

    bubbleSort(names, length);

    cout << "\nNama-nama setelah sorting: " << endl;
    for (int i = 0; i < length; i++)
    {
        cout << names[i] << " ";
    }
    cout << endl;

    return 0;
}
```
#### Output:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/f086af49-5018-48c8-9996-00e5d13a29d2)

Kode di atas digunakan untuk menampilkan nama-nama warga dalam urutan terurut sesuai alfabet menggunakan algoritma bubble sort. Untuk mendeklarasikan fungsi swap yang menerima dua parameter berupa referensi ke dua string (a dan b) yang bertugas menukar nilai antara a dan b menggunakan void swap(string &a, string &b). Untuk mendeklarasikan fungsi bubbleSort yang menerima dua parameter: arr (array string yang akan diurutkan) dan n (panjang array) menggunakan void bubbleSort(string arr[], int n). Pada if (arr[j] > arr[j + 1]), kondisi ini untuk membandingkan elemen saat ini dengan elemen selanjutnya, jika elemen saat ini lebih besar dari elemen selanjutnya, maka elemen tersebut akan ditukar menggunakan fungsi swap. Pada string names[] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"}; digunakan untuk mendeklarasikan dan menginisialisasikan array names dengan nama-nama warga. Untuk mencetak pesan sebelum array diurutkan dapat menggunakan cout << "Nama-nama sebelum sorting: " << endl;. Untuk  memanggil fungsi bubbleSort agar array names diurutkan dapat menggunakan bubbleSort(names, length);. Sedangkan untuk mencetak pesan setelah array diurutkan menggunakan cout << "\nNama-nama setelah sorting: " << endl;.

#### Full code Screenshot:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/021e25ea-79f7-40de-b0e4-f995190e6084)

### 3. Buatlah program yang meminta user menginputkan suatu bilangan n dan meminta user untuk menginputkan sejumlah n karakter. Kemudian program akan melakukan sorting secara menaik (ascending) dan menurun (descending)!
```C++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cout << "Masukkan jumlah karakter (n): ";
    cin >> n;

    vector<char> characters(n);
    
    for(int i = 0; i < n; ++i)
    {
        cout << "Karakter ke-" << i+1 << ": ";
        cin >> characters[i];
    }

    cout << "Urutan karakter sebelum sorting: ";
    for(char c : characters) 
    {
        cout << c << ' ';
    }
    
    // mengurutkan karakter-karakter secara ascending
    sort(characters.begin(), characters.end());
    
    cout << "\nUrutan karakter setelah ascending sort: ";
    for(char c : characters)
    {
        cout << c << ' ';
    }

   // mengurutkan karakter-karakter secara descending
   sort(characters.rbegin(), characters.rend());

   cout << "\nUrutan karakter setelah descending sort: ";
   for(char c : characters)
   {
       cout << c << ' ';
   }

   return 0;
}
```
#### Output:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/e5020a85-c041-4e57-83d0-96d7e16ba263)

Kode di atas digunakan untuk menginputkan jumlah karakter n dan karakter-karakter sejumlah n. Kemudian, program membaca karakter-karakter tersebut dan mengurutkannya secara ascending dan descending. Fungsi sort digunakan untuk mengurutkan karakter dalam vektor characters. Untuk mengurutkan karakter secara ascending menggunakan sort(characters.begin(), characters.end()). Untuk mengurutkan karakter secara descending menggunakan sort(characters.rbegin(), characters.rend()).

#### Full code Screenshot:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/67adf9c7-949d-4261-86ae-99f9c40b6c67)

## Kesimpulan
Sorting adalah proses penyusunan kembali himpunan obyek dengan aturan tertentu. Tujuan sorting adalah untuk memudahkan pencarian data. Ada dua jenis algoritma sorting, yaitu ascending (urut naik) dan descending (urut turun). Insertion Sort yaitu menyisipkan data baru ke urutan yang tepat. Bubble Sort yaitu membandingkan elemen berdekatan dan menukar posisi jika tidak sesuai. Selection Sort yaitu menemukan elemen terkecil atau elemen terbesar dan menukarnya dengan elemen pertama.

## Referensi
[1] W. Tarigan, ALGORITMA PEMROGRAMAN DAN STRUKTUR DATA, Purbalingga: EUREKA MEDIA AKSARA, 2022. 
[2] F. Yanti and E. S. Eriana, ALGORITMA SORTING DAN SEARCHING, Purbalingga: EUREKA MEDIA AKSARA, 2024. 
[3] M. P. Putri, et al., ALGORITMA DAN STRUKTUR DATA, Bandung: WIDINA BHAKTI PERSADA BANDUNG, 2022. 

