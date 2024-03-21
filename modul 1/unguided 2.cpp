#include <iostream>
#include <string>
using namespace std;

// Definisikan class Film
class Film {
private:
    string title;
    int releaseYear;

public:
    // Constructor
    Film(string t, int year) : title(t), releaseYear(year) {}

    // Getter untuk judul film
    string getTitle() {
        return title;
    }

    // Getter untuk tahun rilis
    int getReleaseYear() {
        return releaseYear;
    }
};

// Definisikan struct Film
struct FilmStruct {
    string title;
    int releaseYear;
};

int main() {
    // Membuat objek Film menggunakan class
    Film myFilm("Anne with an A", 2019);

    // Membuat variabel FilmStruct menggunakan struct
    FilmStruct myFilmStruct;
    myFilmStruct.title = "Lttle Women";
    myFilmStruct.releaseYear = 1994;

    // Menampilkan data anggota dari class
    cout << "\nFilm (Class):" << endl;
    cout << "Judul film: " << myFilm.getTitle() << endl;
    cout << "Tahun rilis: " << myFilm.getReleaseYear() << endl;

    // Menampilkan data anggota dari struct
    cout << "\nFilm (Struct):" << endl;
    cout << "Judul film: " << myFilmStruct.title << endl;
    cout << "Tahun rilis: " << myFilmStruct.releaseYear << endl;

    return 0;
}
