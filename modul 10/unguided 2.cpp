#include <iostream>
using namespace std;

// Definisi struktur pohon
struct pohon {
    pohon* kanan;
    char data;
    pohon* kiri;
};

// Deklarasi variabel global
pohon* simpul;
pohon* root;
pohon* saatIni;
pohon* helperA;
pohon* helperB;
pohon* alamat[256];

// Fungsi untuk inisialisasi root
void inisialisasi() {
    root = NULL;
}

// Fungsi untuk membuat simpul baru
void simpulBaru(char dataMasukkan) {
    simpul = new pohon;
    simpul->data = dataMasukkan;
    simpul->kanan = NULL;
    simpul->kiri = NULL;
}
// Fungsi untuk membuat simpul akar
void simpulAkar() {
    if (root == NULL) {
        char dataAnda;
        cout << "Silahkan masukkan data: ";
        cin >> dataAnda;
        simpulBaru(dataAnda);
        root = simpul;
        cout << "Root terbentuk..." << endl;
    } else {
        cout << "Root sudah ada..." << endl;
    }
}
// Fungsi untuk menambah simpul
void tambahSimpul() {
    if (root != NULL) {
        int i = 1, j = 1, penanda = 0;
        char dataUser;
        alamat[i] = root;
        // Memasukkan child
        while (penanda == 0 && j < 256) {
            cout << "Masukkan data kiri (0 untuk berhenti): ";
            cin >> dataUser;
            if (dataUser != '0') {
                simpulBaru(dataUser);
                saatIni = alamat[i];
                saatIni->kiri = simpul;
                j++;
                alamat[j] = simpul;
            } else {
                penanda = 1;
                j++;
                alamat[j] = NULL;
            }
            if (penanda == 0) {
                cout << "Masukkan data kanan (0 untuk berhenti): ";
                cin >> dataUser;
                if (dataUser != '0') {
                    simpulBaru(dataUser);
                    saatIni = alamat[i];
                    saatIni->kanan = simpul;
                    j++;
                    alamat[j] = simpul;
                } else {
                    penanda = 1;
                    j++;
                    alamat[j] = NULL;
                }
            }
            i++;
        }
    }
}
// Fungsi untuk pre-order
void preOrder(pohon* node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrder(node->kiri);
        preOrder(node->kanan);
    }
}
// Fungsi untuk in-order
void inOrder(pohon* node) {
    if (node != NULL) {
        inOrder(node->kiri);
        cout << node->data << " ";
        inOrder(node->kanan);
    }
}
// Fungsi untuk post-order
void postOrder(pohon* node) {
    if (node != NULL) {
        postOrder(node->kiri);
        postOrder(node->kanan);
        cout << node->data << " ";
    }
}
// Menampilkan menu
void tampilkanMenu() {
    cout << "Menu:" << endl;
    cout << "1. Tambah Root" << endl;
    cout << "2. Tambah Simpul" << endl;
    cout << "3. Tampilkan Pre-order" << endl;
    cout << "4. Tampilkan In-order" << endl;
    cout << "5. Tampilkan Post-order" << endl;
    cout << "6. Keluar" << endl;
    cout << "Pilih opsi: ";
}

// Fungsi utama
int main() {
    inisialisasi();
    int choice;
    do {
        tampilkanMenu();
        cin >> choice;
        switch (choice) {
            case 1: // Menginput simpul akar
                simpulAkar(); // 
                break;
            case 2: // Menambah simpul
                tambahSimpul();
                break;
            case 3: // Menampilkan traversal secara pre-order
                cout << "Pre-order: "; 
                preOrder(root);
                cout << endl;
                break;
            case 4: // Menampilan traversal secara in-order
                cout << "In-order: "; 
                inOrder(root);
                cout << endl;
                break;
            case 5: // Menampilan traversal secara post-order
                cout << "Post-order: ";
                postOrder(root);
                cout << endl;
                break;
            case 6: // Mengakhiri menu
                cout << "Keluar dari program." << endl;
                break;
            default: // Error message jika inputan tidak valid
                cout << "Opsi tidak valid. Silakan coba lagi." << endl;
                break;
        }
    } while (choice != 6);

    // Mencetak nama pembuat program
    cout << endl;
    cout << "Azka Widya Rahmawati - 2311110054" << endl;
    cout << endl; 
    return 0;
}