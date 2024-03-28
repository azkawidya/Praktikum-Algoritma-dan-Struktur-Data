#include <iostream>
#include <vector>
using namespace std;

int main()
{
  // mendeklarasi variabel
  int n, m, o;
  vector<vector<vector<int>>> data;

  // menginput jumlah elemen di setiap dimensi
  cout << "Masukkan jumlah elemen di dimensi pertama: ";
  cin >> n;
  cout << "Masukkan jumlah elemen di dimensi kedua: ";
  cin >> m;
  cout << "Masukkan jumlah elemen di dimensi ketiga: ";
  cin >> o;

  // mendeklarasi array tiga dimensi
  data.resize(n); // mengubah ukuran data untuk memiliki n elemen
  for (int i = 0; i < n; i++)
  {
    data[i].resize(m); // mengubah ukuran elemen ke-i dari data untuk memiliki m elemen
    for (int j = 0; j < m; j++)
    {
      data[i][j].resize(o); // mengubah ukuran elemen ke-j dari data[i] untuk memiliki o elemen
    }
  }

  // menginput data dari user
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      for (int k = 0; k < o; k++)
      {
        cin >> data[i][j][k];
      }
    }
  }

  // menampilkan data array
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      for (int k = 0; k < o; k++)
      {
        cout << data[i][j][k] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}

