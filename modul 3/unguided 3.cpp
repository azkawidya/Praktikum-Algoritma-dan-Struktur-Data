#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cout << "Masukkan jumlah karakter (n): ";
    cin >> n;

    vector<char> characters(n);
    
    for(int i = 0; i < n; ++i)
    {
        cout << "Karakter ke-" << i+1 << ": ";
        cin >> characters[i];
    }

    cout << "Urutan karakter sebelum sorting: ";
    for(char c : characters) 
    {
        cout << c << ' ';
    }
    
    // mengurutkan karakter-karakter secara ascending
    sort(characters.begin(), characters.end());
    
    cout << "\nUrutan karakter setelah ascending sort: ";
    for(char c : characters)
    {
        cout << c << ' ';
    }

   // mengurutkan karakter-karakter secara descending
   sort(characters.rbegin(), characters.rend());

   cout << "\nUrutan karakter setelah descending sort: ";
   for(char c : characters)
   {
       cout << c << ' ';
   }

   return 0;
}
