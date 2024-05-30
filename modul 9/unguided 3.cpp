#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Mahasiswa {
    string NIM;
    int nilai;
};

// Hash table menggunakan unordered_map
unordered_map<string, Mahasiswa> hashTable;

// Fungsi untuk menambahkan data mahasiswa baru
void tambahData(const string& NIM, int nilai) {
    hashTable[NIM] = {NIM, nilai};
}

// Fungsi untuk menghapus data mahasiswa berdasarkan NIM
void hapusData(const string& NIM) {
    if (hashTable.find(NIM) != hashTable.end()) {
        hashTable.erase(NIM);
        cout << "Data berhasil dihapus." << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }
}

// Fungsi untuk mencari data mahasiswa berdasarkan NIM
void cariDataNIM(const string& NIM) {
    auto it = hashTable.find(NIM);
    if (it != hashTable.end()) {
        cout << "NIM: " << it->second.NIM << ", Nilai: " << it->second.nilai << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }
}

// Fungsi untuk mencari data mahasiswa berdasarkan rentang nilai
void cariDataNilai(int minNilai, int maxNilai) {
    bool found = false;
    for (auto& pair : hashTable) {
        if (pair.second.nilai >= minNilai && pair.second.nilai <= maxNilai) {
            cout << "NIM: " << pair.second.NIM << ", Nilai: " << pair.second.nilai << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Tidak ada data dalam rentang nilai yang dicari." << endl;
    }
}

int main() {
    // Tampilan menu pilihan
    int pilihan, nilai;
    string NIM;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Hapus Data Mahasiswa\n";
        cout << "3. Cari Data Mahasiswa Berdasarkan NIM\n";
        cout << "4. Cari Data Mahasiswa Berdasarkan Nilai (80 - 90)\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan NIM: ";
                cin >> NIM;
                cout << "Masukkan nilai: ";
                cin >> nilai;
                tambahData(NIM, nilai);
                break;
            case 2:
                cout << "Masukkan NIM yang akan dihapus: ";
                cin >> NIM;
                hapusData(NIM);
                break;
            case 3:
                cout << "Masukkan NIM yang dicari: ";
                cin >> NIM;
                cariDataNIM(NIM);
                break;
            case 4:
                cariDataNilai(80, 90);
                break;
            case 5:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 5);

    return 0;
}
