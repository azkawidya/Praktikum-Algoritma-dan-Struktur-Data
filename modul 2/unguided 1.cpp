#include <iostream>
#include <vector>
using namespace std;

int main()
{
  // deklarasi variabel
  int n;
  vector<int> data;

  // input jumlah data
  cout << "Masukkan jumlah data: ";
  cin >> n;

  // input data dari user
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    data.push_back(x); // menambahkan elemen x ke akhir vector data
  }

  // tampilkan data array
  cout << "Data Array: ";
  for (int i = 0; i < n; i++)
  {
    cout << data[i] << " ";
  }
  cout << endl;

  // tampilkan nomor genap
  cout << "Nomor Genap: ";
  for (int i = 0; i < n; i++)
  {
    if (data[i] % 2 == 0) // memeriksa apakah elemen ke-i dari vector data adalah bilangan genap
    {
      cout << data[i] << " ";
    }
  }
  cout << endl;

  // tampilkan nomor ganjil
  cout << "Nomor Ganjil: ";
  for (int i = 0; i < n; i++) 
  {
    if (data[i] % 2 == 1) // memeriksa apakah elemen ke-i dari vector data adalah bilangan ganjil
    {
      cout << data[i] << " ";
    }
  }
  cout << endl;

  return 0;
}

