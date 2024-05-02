#include <iostream>
#include <string>

using namespace std;

// Mendefinisikan struktur buku dengan array
struct buku {
    string judul_buku[5];
    string pengarang[5];
    string penerbit[5];
    int tebal_halaman[5];
    int harga_buku[5];
};

int main() {
    // Mendeklarasikan variabel BukuFavorit dengan tipe buku
    buku BukuFavorit;

    // Mengisi data ke dalam array di variabel BukuFavorit
    BukuFavorit.judul_buku[0] = "Tuesdays with Morrie";
    BukuFavorit.judul_buku[1] = "Life of Pi";
    BukuFavorit.judul_buku[2] = "The Sorcery Little Magacal Piya";
    BukuFavorit.judul_buku[3] = "Jakarta Sebelum Pagi";
    BukuFavorit.judul_buku[4] = "Northanger Abbey";

    BukuFavorit.pengarang[0] = "Mitch Albom";
    BukuFavorit.pengarang[1] = "Yann Martel";
    BukuFavorit.pengarang[2] = "Cindyana H.";
    BukuFavorit.pengarang[3] = "Ziggy Zezsyazeoviennazabrizkie";
    BukuFavorit.pengarang[4] = "Jane Austen";

    BukuFavorit.penerbit[0] = "Sinar Star Book";
    BukuFavorit.penerbit[1] = "Gramedia Pustaka Utama";
    BukuFavorit.penerbit[2] = "Fantasious";
    BukuFavorit.penerbit[3] = "Grasindo";
    BukuFavorit.penerbit[4] = "Gramedia Pustaka Utama";

    BukuFavorit.tebal_halaman[0] = 192;
    BukuFavorit.tebal_halaman[1] = 448;
    BukuFavorit.tebal_halaman[2] = 476;
    BukuFavorit.tebal_halaman[3] = 280;
    BukuFavorit.tebal_halaman[4] = 328;

    BukuFavorit.harga_buku[0] = 125000;
    BukuFavorit.harga_buku[1] = 88000;
    BukuFavorit.harga_buku[2] = 99500;
    BukuFavorit.harga_buku[3] = 92000;
    BukuFavorit.harga_buku[4] = 59000;

    // Menampilkan informasi BukuFavorit
    cout << "\tBuku Favorit Saya" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "\tBuku ke-" << i + 1 << endl;
        cout << "\tJudul Buku    : " << BukuFavorit.judul_buku[i] << endl;
        cout << "\tPengarang     : " << BukuFavorit.pengarang[i] << endl;
        cout << "\tPenerbit      : " << BukuFavorit.penerbit[i] << endl;
        cout << "\tTebal Halaman : " << BukuFavorit.tebal_halaman[i] << " halaman" << endl;
        cout << "\tHarga Buku    : Rp " << BukuFavorit.harga_buku[i] << endl << endl;
    }

    return 0;
}