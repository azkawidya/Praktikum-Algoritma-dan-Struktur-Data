#include <iostream>
#include <map>
using namespace std;

int main()
{
    // Contoh penggunaan map dengan key bertipe int dan value bertipe string
    map<int, string> book;
    book[1] = "Tuesdays with Morrie";
    book[2] = "The Magic Library";
    book[3] = "Animal Farm";

    // Menampilkan elemen-elemen dalam map
    for (const auto & pair: book) {
        cout << "Book Title: " << pair.second << endl;
    }

    return 0;
}
