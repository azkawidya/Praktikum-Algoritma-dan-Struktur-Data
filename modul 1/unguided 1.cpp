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
