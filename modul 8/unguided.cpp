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