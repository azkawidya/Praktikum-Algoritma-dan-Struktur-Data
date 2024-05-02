#include <iostream>
using namespace std;

struct Buku {
    string judul_buku;
    string pengarang;
    string penerbit;
    int tebal_halaman;
    double harga_buku;
}; Buku buku1, buku2;

int main() {
    // Membuat dan mengisi struktur buku
    Buku buku1;
    buku1.judul_buku = "Anne of Green Gables";
    buku1.pengarang = "Lucy Maud Montgomery";
    buku1.penerbit = "Gramedia Pustaka Utama";
    buku1.tebal_halaman = 412;
    buku1.harga_buku = 65000;

    Buku buku2;
    buku2.judul_buku = "Tuesdays with Morrie";
    buku2.pengarang = "Mitch Albom";
    buku2.penerbit = "Knopf Doubleday Publishing Group";
    buku2.tebal_halaman = 192;
    buku2.harga_buku = 126000;

    // Menampilkan informasi buku
    cout << "Judul Buku     : " << buku1.judul_buku << endl;
    cout << "Pengarang      : " << buku1.pengarang << endl;
    cout << "Penerbit       : " << buku1.penerbit << endl;
    cout << "Tebal Halaman  : " << buku1.tebal_halaman << " halaman" << endl;
    cout << "Harga Buku     : Rp" << buku1.harga_buku << endl;

    cout << "Judul Buku     : " << buku2.judul_buku << endl;
    cout << "Pengarang      : " << buku2.pengarang << endl;
    cout << "Penerbit       : " << buku2.penerbit << endl;
    cout << "Tebal Halaman  : " << buku2.tebal_halaman << " halaman" << endl;
    cout << "Harga Buku     : Rp" << buku2.harga_buku << endl;

    return 0;
}
