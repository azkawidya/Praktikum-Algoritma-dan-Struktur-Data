# <h1 align="center">Laporan Praktikum Modul Priority Queue dan Heaps</h1>
<p align="center">Azka Widya Rahmawati</p>

## Dasar Teori
Priority Queue adalah struktur data abstrak yang mirip dengan antrian biasa, tapi setiap elemennya memiliki “prioritas” yang terkait dengannya [1]. Dalam priority queue, elemen dengan prioritas tertinggi akan dihapus terlebih dahulu, bukan elemen yang pertama kali dimasukkan (seperti dalam antrian FIFO). Priority queue sangat berguna dalam algoritma seperti scheduling process dalam sistem operasi dan dalam implementasi algoritma graf seperti Dijkstra dan Prim.

Heaps adalah struktur data berbasis pohon yang digunakan untuk mengimplementasikan priority queues. Heap ini dapat dibagi menjadi dua jenis yaitu: max-heap dan min-heap. Dalam max-heap, nilai pada setiap node lebih besar atau sama dengan nilai anak-anaknya, sedangkan dalam min-heap, nilai pada setiap node lebih kecil atau sama dengan nilai anak-anaknya. Hal ini memungkinkan penambahan dan penghapusan elemen dengan efisien sambil mempertahankan urutan prioritas [2].

## Guided 
```C++
#include <iostream>
#include <algorithm>

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }

    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);

    std::cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";
    
    std::cout << "Node with maximum priority : " << extractMax() << "\n";
    std::cout << "Priority queue after extracting maximum : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";
    
    changePriority(2, 49);
    std::cout << "Priority queue after priority change : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";
    
    
    remove(3);
    std::cout << "Priority queue after removing the element : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    return 0;
}
```
Kode di atas adalah bentuk implementasi dari struktur data heap, khususnya max heap. Pada int H[50]; mendeklarasikan array H yang akan digunakan untuk menyimpan elemen heap dan pada int heapSize = -1; mendeklarasikan variabel heapSize yang melacak jumlah elemen dalam heap. Fungsi-fungsi berikut digunakan untuk menghitung indeks relasi dalam heap: parent(int i) untuk mengembalikan indeks dari orang tua node i. leftChild(int i) mengembalikan indeks dari anak kiri node i. rightChild(int i) untuk mengembalikan indeks dari anak kanan node i. Fungsi shiftUp(int i) dan shiftDown(int i) digunakan untuk mempertahankan properti heap saat elemen ditambahkan atau dihapus dimana shiftUp(int i) memindahkan elemen pada indeks i ke atas dalam heap sampai properti heap dipenuhi dan shiftDown(int i) melakukan hal yang sebaliknya, memindahkan elemen ke bawah dalam heap. Fungsi insert(int p) digunakan untuk menambahkan elemen baru ke heap, extractMax() menghapus dan mengembalikan elemen dengan prioritas tertinggi, changePriority(int i, int p) mengubah prioritas elemen yang ada, dan getMax() mengembalikan elemen dengan prioritas tertinggi tanpa menghapusnya. Pada fungsi remove(int i) untuk menghapus elemen pada indeks i dari heap.

Dalam fungsi main(), beberapa elemen dimasukkan ke dalam heap, dan beberapa operasi dilakukan seperti menampilkan elemen dengan prioritas tertinggi, mengubah prioritas elemen, dan menghapus elemen. Output dari program ini akan menunjukkan isi dari heap setelah setiap operasi, memperlihatkan bagaimana elemen-elemen di dalam heap berubah posisi untuk mempertahankan properti max heap. 

## Unguided 

### 1. Modifikasi guided diatas yang mana heap dikonstruksi secara manual berdasarkan user

```C++
#include <iostream>
#include <algorithm>

using namespace std;

// mendeklarasai ukuran maksimal H dan deklarasi heapSize
int H[50];
int heapSize = -1;

// fungsi void untuk mendapatkan parent node
int parent(int i) {
    return (i - 1) / 2;
}

// fungsi void untuk mendapatkan leftChiled node dari indeks i
int leftChild(int i) {
    return ((2 * i) + 1);
}

// fungsi void untuk mendapatkan rightChild node dari indeks i
int rightChild(int i) {
    return ((2 * i) + 2);
}

// fungsi void untuk elemen digerakkan ke atas heap
void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

// fungsi void untuk elemen digerakkan ke bawah heap
void shiftDown(int i) {
    // deklarasi maxIndex
    int maxIndex = i;
    int l = leftChild(i);
    // jika leftChild (l) lebih kecil dari heapSize dan H[l] > H[maxindex]
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    // jika rightChild (r) lebih kecil dari heapSize dan H[r] > H[maxindex]
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    // jika indeks tidak sama dengan maxIndex
    if (i != maxIndex) {
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

// fungsi void untuk menambahkan elemen baru 
void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

// fungsi void untuk ekstrak elemen maksimal yang nilainya paling besar
int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

// fungsi void untuk mengubah priority elemen
void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

// mendapatkan elemen maksimum dari heap
int getMax() {
    return H[0];
}

// fungsi void untuk hapus elemen dari heap
void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

// fungsi void untuk mengatur ukuran elemen dan isi elemen di dalam heap oleh input user
void addHeap(int size) {
    for (int i = 0; i < size; i++) {
        int element;
        cout << "Enter element " << (i + 1) << ": ";
        cin >> element;
        insert(element);
    }
}

// main program 
int main() {
    // deklarasi a
    int a;
    // user input banyak elemen yang diinginkan
    cout << "Enter the size of elements: ";
    cin >> a;
    // memanggil fungsi addHeap
    addHeap(a);

    // menampilkan priority queue dari elemen yang telah diinput user
    cout << "Priority Queue: ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    // menampilkan node yang memiliki maximum priority dengan memanggil fungsi extractMax
    cout << "Node with maximum priority: " << extractMax() << "\n";

    // menampilkan priority queue setelah ekstrak elemen maximum
    cout << "Priority queue after extracting maximum: ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    // deklarasi index dan newPriority
    int indeks, newPriority;

    // user menginput index elemen yang ingin diubah
    cout << "Enter the Index of the priority you want to change: ";
    cin >> indeks;

    // user menginput new priority untuk menggantikan elemen pada index yang telah diinput
    cout << "Enter the new priority: ";
    cin >> newPriority;

    // memanggil fungsi changePriority untuk mengubah elemen
    changePriority(indeks, newPriority);

    // menampilkan Priority queue setelah elemen diperbarui
    cout << "Priority queue after priority change: ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    // deklarasi removeElement
    int removeElement;

    // user menginput indeks dari elemen yang ingin dihapus
    cout << "Enter the Indeks of the element you want to remove: ";
    cin >> removeElement;

    // panggil fungsi remove untuk hapus elemen
    remove(removeElement);

    // menampilkan Priority Queue setelah elemen dihapus
    cout << "Priority queue after removing the element: ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    return 0;
}
```
#### Output:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/01761de6-ae74-4012-a6f1-01afd69c79fb)

Kode di atas digunakan untuk memodifikasi program sehingga heap dapat dikonstruksi secara manual berdasarkan input pengguna, untuk mengambil input dari pengguna dan memasukkannya ke dalam heap perlu menambahkan beberapa baris kode. 

Pada int H[50]; mendeklarasikan array H dengan ukuran maksimal 50 untuk menyimpan elemen heap.
int heapSize = -1; menginisialisasi ukuran heap dengan -1 karena heap masih kosong. Fungsi Parent, Left Child, dan Right Child: parent(int i), leftChild(int i), dan rightChild(int i) digunakan menghitung indeks parent, left child, dan right child dari node dengan indeks i. Pada shiftUp(int i) untuk memindahkan elemen ke atas heap jika nilainya lebih besar dari parentnya dan shiftDown(int i) untuk memindahkan elemen ke bawah heap jika nilainya lebih kecil dari salah satu child-nya. Pada insert(int p) untuk menambahkan elemen baru ke heap dan memastikan properti heap terjaga dan extractMax() untuk menghapus elemen maksimal (root) dari heap dan mengembalikan nilainya. changePriority(int i, int p) untuk mengubah prioritas elemen pada indeks i menjadi nilai p. getMax()untuk mengembalikan nilai maksimal (root) dari heap tanpa menghapusnya. remove(int i) untuk menghapus elemen pada indeks i dari heap. Pada addHeap(int size) meminta input dari pengguna untuk menambahkan elemen ke dalam heap. Di dalam main(), pengguna diminta untuk memasukkan ukuran elemen yang ingin dimasukkan ke dalam heap. Kemudian, elemen-elemen tersebut dimasukkan ke dalam heap menggunakan addHeap(a).

#### Full code Screenshot:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/364fdbe8-8364-49a4-84ee-db7a61542d2c)

## Kesimpulan
Priority Queue adalah struktur data yang memungkinkan penyimpanan elemen dengan prioritas tertentu. Elemen dengan prioritas tertinggi akan dihapus terlebih dahulu, yang membedakannya dari antrian FIFO biasa. Struktur data ini sangat berguna dalam algoritma penjadwalan dan algoritma graf seperti Dijkstra dan Prim. Sedangkan Heaps adalah struktur data pohon yang mendukung operasi priority queue secara efisien. Terdapat dua jenis heap: max-heap, di mana nilai setiap node lebih besar atau sama dengan anak-anaknya, dan min-heap, di mana nilai setiap node lebih kecil atau sama dengan anak-anaknya. Ini memungkinkan penambahan dan penghapusan elemen secara efisien sambil mempertahankan urutan prioritas.

## Referensi

[1] S. M. Dr. Joseph Teguh Santoso, Struktur Data dan Algoritma (Bagian 1), Semarang: Yayasan Prima Agus Teknik, 2021. 

[2] F. L. Tobing, F. A. T. Tobing and J. Peranginangin, "Implementasi Algoritma Heapsort dalam Game Pembelajaran Algoritma Sorting," Jurnal Widya, vol. III, no. 2, pp. 331-343, 2022. 


 