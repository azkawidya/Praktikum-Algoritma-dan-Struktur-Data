#include <iostream>
#include <vector>
#include <string>
#include <iomanip> 
using namespace std;

// Main program
int main() {
    int numCities; // Deklarasi variabel untuk menyimpan jumlah kota
   
    // Menginput jumlah kota 
    cout << "Silakan masukkan jumlah simpul: ";
    cin >> numCities;
    cin.ignore();  

    vector<string> cities(numCities); // Menyimpan nama-nama kota
    vector<vector<int>> distanceMatrix(numCities, vector<int>(numCities, 0)); // Menyimpan jarak antar kota

    // Memasukkan dan menyimpan nama kota
    for (int i = 0; i < numCities; ++i) {
        cout << "Simpul " << i + 1 << ": "; // Setiap iterasi nama kota ke-i akan dimasukkan
        getline(cin, cities[i]);
    }
    // Memasukkan dan menyimpan jarak antar simpul0
    
    cout << "\nSilahkan masukkan bobot antar simpul : ";
    
    for (int i = 0; i < numCities; ++i) {
        for (int j = 0; j < numCities; ++j) {
            cout << cities[i] << "-->" << cities[j] << " = ";
            cin >> distanceMatrix[i][j];
        }
    }

    // Menampilkan jarak matriks
    cout << "\n     ";
    for (const auto& city : cities) {
        cout << setw(7) << city << "  "; // setw untuk mengatur jarak atau lebar tampilan
    }
    cout << endl;
    // Menampilkan setiap baris matriks jarak dengan nama kota 
    for (int i = 0; i < numCities; ++i) {
        cout << setw(7) << cities[i] << "  ";
        for (int j = 0; j < numCities; ++j) {
            cout << setw(4) << distanceMatrix[i][j] << "  ";
        }
        cout << endl;
    }
    // Mencetak nama pembuat program
    cout << endl;
    cout << "Azka Widya Rahmawati - 2311110054" << endl;
    cout << endl; 
    return 0;

    return 0;
} 