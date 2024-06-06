# <h1 align="center">Laporan Praktikum Modul Graph dan Tree</h1>
<p align="center">Azka Widya Rahmawati</p>

## Dasar Teori
### Graph 
Graf atau Graph adalah struktur data yang terdiri atas himpunan simpul (vertex) dan himpunan sisi (edge) yang menghubungkan pasangan simpul [1]. Saat membuat representasi graf dalam bentuk daftar terkait, pahami perbedaan antara simpul vertex dan simpul edge. Simpul vertex menunjukkan titik atau simpul dalam graf, sementara simpul edge menunjukkan hubungan antara titik-titik tersebut. Tergantung pada kebutuhan, struktur keduanya dapat sama atau berbeda, namun biasanya sama. Perbedaan antara simpul vertex dan simpul edge adalah bagaimana keduanya digunakan dan diperlakukan dalam representasi graf.

Jenis-jenis graph:
- Undirected Graph (Graf Tidak Berarah): Sisi tidak memiliki arah, artinya jika ada sisi antara simpul A dan B, maka bisa dilalui dari A ke B atau dari B ke A.

- Directed Graph (Graf Berarah atau Digraph): Sisi memiliki arah, artinya jika ada sisi dari simpul A ke B, maka hanya bisa dilalui dari A ke B, tidak sebaliknya.

- Weighted Graph (Graf Berbobot): Setiap sisi memiliki bobot atau nilai tertentu yang seringkali menggambarkan jarak, biaya, atau kapasitas.

- Unweighted Graph (Graf Tanpa Bobot): Sisi tidak memiliki bobot atau nilai.

Representasi:
- Adjacency Matrix (Matriks Ketetanggaan): Matriks dua dimensi dimana elemen [i][j] menunjukkan ada atau tidaknya sisi antara simpul i dan j, serta bobotnya jika graph berbobot.
- Adjacency List (Daftar Ketetanggaan): Array dari daftar, dimana setiap simpul memiliki daftar simpul lain yang terhubung dengannya.

Contoh: Jaringan sosial (misalnya, hubungan pertemanan di Facebook), Jaringan komputer (misalnya, perangkat yang terhubung dalam jaringan).

### Tree
Tree adalah struktur data hierarkis yang terdiri dari simpul-simpul yang dihubungkan oleh sisi-sisi, dimana tidak ada siklus dan setiap simpul (kecuali akar) memiliki satu induk (parent) [2]. Struktur data tree ini digunakan untuk menyimpan data-data hirarki seperti pohon keluarga, struktur organisasi, skema pertandingan, dan lain sebagainya.

Komponen:

- Root (Akar): Simpul paling atas dari pohon.
- Node (Simpul): Titik dalam pohon.
- Edge (Sisi): Garis yang menghubungkan dua simpul (induk dan anak).
- Parent (Induk): Simpul yang memiliki cabang ke bawah (anak).
- Child (Anak): Simpul yang terhubung ke atas (induk).
- Leaf (Daun): Simpul yang tidak memiliki anak.
- Subtree (Subpohon): Pohon yang merupakan bagian dari pohon yang lebih besar.

Jenis Tree:

- Binary Tree (Pohon Biner): Setiap simpul memiliki paling banyak dua anak.
- Binary Search Tree (Pohon Pencarian Biner): Pohon biner yang terurut, dimana anak kiri memiliki nilai lebih kecil dari induknya dan anak kanan memiliki nilai lebih besar.
- Balanced Tree (Pohon Seimbang): Pohon dimana selisih kedalaman antara subpohon kiri dan kanan tidak lebih dari satu.
- AVL Tree, Red-Black Tree: Jenis pohon pencarian biner yang selalu seimbang secara otomatis.
- N-ary Tree: Pohon dimana setiap simpul memiliki paling banyak N anak.

Traversals (Penelusuran): 
- Preorder: Kunjungi root, lalu subpohon kiri, kemudian subpohon kanan.
- Inorder: Kunjungi subpohon kiri, root, kemudian subpohon kanan.
- Postorder: Kunjungi subpohon kiri, subpohon kanan, kemudian root.

Contoh: Struktur folder dalam sistem file, pohon keputusan dalam algoritma machine learning.

## Guided 
### 1. Program Graph
```C++
#include <iostream>
#include <iomanip>
using namespace std;

string simpul[7] = {"Ciamis",
                    "Bandung",
                    "Bekasi",
                    "Tasikmalaya", 
                    "Cianjur", 
                    "Purwokerto", 
                    "Yogyakarta"};

int busur [7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 9, 15, 0},
    {0, 5, 0, 9, 5, 0, 0},
    {0, 0, 0, 2, 4, 0, 8},
    {3, 0, 0, 1, 0, 0, 0},
    {0, 0, 7, 0, 0, 9, 4},
    {0, 0, 0, 8, 8, 0, 0}
};

void tampilGraph() {
    for (int baris = 0; baris < 7; baris++) {
        cout << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++) {
            if (busur[baris][kolom] !=0)
            cout << " -> " << simpul[kolom] << "(" << busur[baris][kolom] << ")";
        }
        cout << endl;
    }
 }

 int main() {
    tampilGraph();
    return 0;
 }
```
Kode di atas merupaka implementasi representasi dari graf menggunakan matriks ketetanggaan. Pada node graf (verteks), array simpul berisi nama dari 7 node (atau verteks) dalam graf: “Ciamis,” “Bandung,” “Bekasi,” “Tasikmalaya,” “Cianjur,” “Purwokerto,” dan “Yogyakarta.” Pada matriks ketetanggaan: array busur adalah matriks 2D yang mewakili sambungan (edge) antara node-node ini. Setiap sel busur[i][j] berisi bobot dari sambungan dari node i ke node j. Jika tidak ada sambungan langsung, nilainya adalah 0. Fungsi tampilGraph() mencetak graf dalam format daftar ketetanggaan. Untuk setiap node, fungsi ini mencantumkan node-node yang berdekatan beserta bobot sambungannya (jika tidak nol).

### 2. Program Tree
```C++
#include <iostream>
using namespace std;

// definisi struktur pohon
struct pohon {
    pohon * kanan;
    char data;
    pohon * kiri;
};

// deklarasi variabel global
pohon * simpul;
pohon * root;
pohon * saatIni;
pohon * helperA;
pohon * helperB;
pohon * alamat[256];

// fungsi untuk inisialisai root
void inisialisasi() {
    root = NULL;
}

// fungsi untuk membuat simpul baru
void simpulBaru (char dataMasukkan) {
    simpul = new pohon;
    simpul->data = dataMasukkan;
    simpul->kanan = NULL;
    simpul->kiri = NULL;
}

// fungsi untuk membuat simpul akar
void simpulAkar() {
    if (root == NULL) {
        char dataAnda;
        cout << "Silakan masukkan data: ";
        cin >> dataAnda;
        simpulBaru(dataAnda);
        root = simpul;
        cout << "Root terbentuk..." << endl;
    } else {
        cout << "Root sudah ada..." << endl;
    }
}

// fungsi untuk menambah simpul
void tambahSimpul() {
    if (root != NULL) {
        int i = 1, j = 1, penanda = 0;
        char dataUser;
        alamat[i] = root;

        while (penanda == 0 && j < 256) {
            cout << "Masukkan data kiri: ";
            cin >> dataUser;
            if (dataUser != '0') {
                simpulBaru(dataUser);
                saatIni = alamat[i];
                saatIni -> kiri = simpul;
                j++;
                alamat[j] = simpul;
            } else {
                penanda = 1;
                j++;
                alamat[j] = NULL;
            }
            if (penanda == 0) {
                cout << "Masukkan data kanan: ";
                cin >> dataUser;
                if(dataUser != '0') {
                    simpulBaru (dataUser);
                    saatIni = alamat [i];
                    saatIni -> kanan = simpul;
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

// fungsi untuk membaca pohon
void bacaPohon() {
    if (root != NULL) {
        int i = 1, n = 1, pencacah = 0;
        cout << endl;
        while (alamat [i] != NULL) {
            saatIni = alamat[i];
            cout << saatIni -> data << " ";
            pencacah++;
            if (pencacah == n) {
                cout << endl;
                pencacah = 0;
                n = n * 2;
            }
            i++;
        }
    }
}

// fungsi utama
int main() {
    inisialisasi();
    simpulAkar();
    tambahSimpul();
    bacaPohon();
    return 0;
}
```
Kode di atas merupakan implementasi pohon biner menggunakan struktur data dan operasi dasar. Dalam kode ini menggunakan struktur data pohon untuk merepresentasikan simpul-simpul dalam pohon biner.
Setiap simpul memiliki tiga bagian, yaitu kanan, data (berisi karakter), dan kiri. Fungsi inisialisasi() menginisialisasi root (akar) dengan nilai NULL. Jika root belum ada, fungsi simpulAkar() meminta pengguna memasukkan data dan membuat simpul akar. Fungsi tambahSimpul() memungkinkan pengguna menambah simpul ke pohon. Pengguna diminta memasukkan data kiri dan kanan untuk setiap simpul. Data ‘0’ menandakan simpul kosong. Fungsi bacaPohon() mencetak isi pohon secara level-order (baris per baris).

## Unguided 
### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.
```C++
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
```
#### Output:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/105ae44c-a7d3-4fd1-b8c8-d170cd80efd3)

Kode di atas digunakan untuk mensimulasikan program untuk menghitung jarak antar kota dan menampilkannya dalam bentuk matriks. Deklarasi variabel `numCities` untuk menyimpan jumlah simpul atau kota. Vector `cities` untuk menyimpan nama-nama kota. `distanceMatrix` untuk menyimpan jarak antar kota dalam bentuk matriks. `setw` dari pustaka iomanip untuk mengatur lebar tampilan agar rapi.

#### Full code Screenshot:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/da9abab3-6d29-4d75-bf6f-dd01bd199191)

### 2. Modifikasi guided tree di atas dengan program menu menggunakan input data tree dari user dan tampilkan pada pre-order, inorder, dan post order!
```C++
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
```
#### Output:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/778fdbde-2fbc-4f97-a5a0-55538e98a9ce)

Kode di atas mendefinisikan struktur data pohon biner dan beberapa fungsi untuk memanipulasinya. Struktur `pohon` mendefinisikan node dalam pohon biner. Setiap node memiliki tiga anggota, `kanan` adalah pointer ke node anak kanan, `data` adalah nilai yang disimpan di node (dalam hal ini, karakter) dan `kiri` adalah pointer ke node anak kiri.

Variabel global ini digunakan untuk menyimpan informasi tentang pohon dan membantu fungsi-fungsi yang berbeda.

`simpul`: Pointer ke node yang sedang diproses.
`root`: Pointer ke node akar pohon.
`saatIni`: Pointer ke node saat ini yang sedang diakses.
`helperA` dan `helperB`: Pointer yang digunakan untuk membantu operasi traversal.
`alamat`: Array pointer yang digunakan untuk menyimpan alamat node.

Fungsi-fungsi:

`inisialisasi()`: Menginisialisasi root menjadi NULL, menunjukkan bahwa pohon masih kosong.
`simpulBaru(char dataMasukkan)`: Mengalokasikan node baru, mengisi data dengan dataMasukkan, dan mengatur kanan dan kiri ke NULL.
`simpulAkar()`: Meminta input data dari pengguna dan membuat node akar baru dengan data tersebut.
`tambahSimpul()`: Menambahkan node baru ke pohon sebagai anak dari node yang sudah ada. Pengguna memilih apakah ingin menambahkan anak kiri atau kanan, dan input data baru diminta.
`preOrder(pohon* node)`: Mencetak data dari node saat ini dan kemudian secara rekursif memanggil preOrder pada anak kiri dan kanan.
`inOrder(pohon* node)`: Mencetak data dari anak kiri, kemudian data dari node saat ini, dan kemudian data dari anak kanan secara rekursif.
`postOrder(pohon* node)`: Mencetak data dari anak kiri dan kanan secara rekursif, dan kemudian data dari node saat ini.
`tampilkanMenu()`: Menampilkan menu pilihan kepada pengguna.
`main()`: Fungsi utama yang mengontrol program. Menginisialisasi pohon, menampilkan menu, dan menangani pilihan pengguna.

Program ini dimulai dengan menginisialisasi variabel global dan memanggil fungsi `inisialisasi()` untuk membuat pohon kosong. Loop utama menampilkan menu kepada pengguna dan menunggu pilihan mereka. Berdasarkan pilihan pengguna, program memanggil fungsi yang sesuai:
`simpulAkar()` membuat node akar baru jika pohon masih kosong.
`tambahSimpul()` menambahkan node baru sebagai anak dari node yang sudah ada. `preOrder()`, `inOrder()`, dan `postOrder()` melakukan traversal pohon dan mencetak data node dalam urutan yang berbeda. Loop utama berlanjut sampai pengguna memilih opsi 6 untuk keluar dari program. Terakhir, program mencetak nama pembuat program dan selesai.

#### Full code Screenshot:
![image](https://github.com/azkawidya/Praktikum-Algoritma-dan-Struktur-Data/assets/161341169/87b24273-2cb9-410e-8794-cadb550e3bbf)

## Kesimpulan
Graph digunakan untuk merepresentasikan hubungan antar elemen, seperti jaringan sosial atau jaringan komputer, sedangkan tree digunakan untuk struktur data hierarkis, seperti pohon keluarga atau struktur organisasi. Implementasi kedua struktur data ini dengan C++ membantu memperkuat pemahaman konsep dan penerapannya dalam pemrograman.

## Referensi
[1] 	A. Zein and E. S. Eriana, ALGORTIMA DAN STRUKTUR DATA, Tangerang Selatan: Unpam Press, 2022. 

[2] 	A. Sindar, STRUKTUR DATA DAN ALGORITMA DENGAN C++, Medan: CV. AA. RIZKY, 2019. 
