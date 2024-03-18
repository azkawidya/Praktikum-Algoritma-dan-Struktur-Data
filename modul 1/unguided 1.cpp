#include <iostream>
using namespace std;

// Fungsi untuk menghitung luas segitiga
float hitungLuasSegitiga(float alas, float tinggi) {
    return 0.5 * alas * tinggi;
}

int main() {
    float alas, tinggi;
    
    // Meminta input dari pengguna
    std::cout << "Masukkan panjang alas segitiga: ";
    std::cin >> alas;
    std::cout << "Masukkan tinggi segitiga: ";
    std::cin >> tinggi;

    // Memanggil fungsi hitungLuasSegitiga dan menampilkan hasil
    float luas = hitungLuasSegitiga(alas, tinggi);
    std::cout << "Luas segitiga adalah: " << luas << " satuan persegi." << std::endl;

    return 0;
}
