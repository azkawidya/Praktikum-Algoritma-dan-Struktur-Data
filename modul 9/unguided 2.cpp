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
