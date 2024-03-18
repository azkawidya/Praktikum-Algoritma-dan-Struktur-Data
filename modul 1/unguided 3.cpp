#include <iostream>
#include <map>

int main()
{
    // Contoh penggunaan map dengan key bertipe int dan value bertipe string
    std::map<int, std::string> student;
    student[1] = "Jake";
    student[2] = "Annelies";
    student[3] = "Rachel";

    // Menampilkan elemen-elemen dalam map
    for (const auto& pair : student) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    return 0;
}
