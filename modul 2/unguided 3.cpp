#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // mendeklarasi variabel
  int n;
  vector<int> data;

  // menginput jumlah data
  cout << "Masukkan jumlah data: ";
  cin >> n; // menerima input jumlah data dari pengguna dan disimpan di variabel n

  // menginput data dari user
  for (int i = 0; i < n; i++) // menerima input data sebanyak n kali
  {
    int x;
    cin >> x;
    data.push_back(x); // menambahkan data ke vector
  }

  // mencari nilai maksimum
  int maksimum = data[0]; 
  for (int i = 1; i < n; i++)
  {
    if (data[i] > maksimum)
    {
      maksimum = data[i];
    }
  }

  // mencari nilai minimum
  int minimum = data[0]; 
  for (int i = 1; i < n; i++)
  {
    if (data[i] < minimum)
    {
      minimum = data[i];
    }
  }

  // menghitung nilai rata-rata
  int total = 0;
  for (int i = 0; i < n; i++)
  {
    total += data[i]; // menghitung jumlah total dari semua elemen di dalam vector data
  }
  float rata_rata = (float)total / n; // menghitung nilai rata-rata dari elemen-elemen di dalam vector data

  // menampilkan menu
  int pilihan;
  do // loop do-while untuk menampilkan menu dan memproses pilihan pengguna
  {
    cout << "Menu:" << endl;
    cout << "1. Tampilkan nilai maksimum" << endl;
    cout << "2. Tampilkan nilai minimum" << endl;
    cout << "3. Tampilkan nilai rata-rata" << endl;
    cout << "4. Keluar" << endl;
    cout << "Masukkan pilihan: ";
    cin >> pilihan;

    switch (pilihan) // mengeksekusi blok kode berdasarkan pilihan menu yang diinputkan oleh pengguna
    {
      case 1:
        cout << "Nilai maksimum: " << maksimum << endl;
        break;
      case 2:
        cout << "Nilai minimum: " << minimum << endl;
        break;
      case 3:
        cout << "Nilai rata-rata: " << rata_rata << endl;
        break;
      case 4:
        cout << "Terima kasih!" << endl;
        break;
      default:
        cout << "Pilihan tidak valid!" << endl;
    }
  } while (pilihan != 4);

  return 0;
}
