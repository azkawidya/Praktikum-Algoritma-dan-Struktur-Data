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
