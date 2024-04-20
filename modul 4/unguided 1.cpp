#include <iostream>
#include <algorithm>
using namespace std;

// Fungsi untuk melakukan binary search pada string
int binarySearch(const string& arr, char x, int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid; // Huruf ditemukan
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // Huruf tidak ditemukan
}
int main()
{
    string kalimat;
    char huruf;
    
    // Menginputkan kalimat dan huruf yang dicari
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);
    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> huruf;
    
    // Sort kalimat terlebih dahulu sebelum binary search
    sort(kalimat.begin(), kalimat.end());
    
    // Binary search
    int result = binarySearch(kalimat, huruf, 0, kalimat.length() - 1);
    if (result != -1)
        cout << "Huruf '" << huruf << "' ditemukan pada indeks ke-" << result << endl;
    else
        cout << "Huruf '" << huruf << "' tidak ditemukan dalam kalimat." << endl;
    
    return 0;
}

