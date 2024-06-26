#include <iostream>
#include <string>
using namespace std;

int main()
{
    string kalimat;
    int jumlah_vokal = 0;
    
    // Menginput kalimat
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);
    
    // Menghitung jumlah huruf vokal
    for (int i = 0; i < kalimat.length(); ++i)
    {
        char huruf = tolower(kalimat[i]); // Mengubah huruf menjadi lowercase untuk memudahkan dalam pengecekan
        if (huruf == 'a' || huruf == 'e' || huruf == 'i' || huruf == 'o' || huruf == 'u')
        {
            ++jumlah_vokal;
        }
    }
    
    // Menampilkan hasil
    cout << "Jumlah huruf vokal dalam kalimat adalah " << jumlah_vokal << endl;
    
    return 0;
}
