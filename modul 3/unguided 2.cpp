#include <iostream>
#include <string>
using namespace std;

// untuk menukar posisi dua elemen
void swap(string &a, string &b)
{
    string temp = a;
    a = b;
    b = temp;
}

// Algoritma Bubble Sort
void bubbleSort(string arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    int length = 10;
    string names[] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};

    cout << "Nama-nama sebelum sorting: " << endl;
    for (int i = 0; i < length; i++)
    {
        cout << names[i] << " ";
    }
    cout << endl;

    bubbleSort(names, length);

    cout << "\nNama-nama setelah sorting: " << endl;
    for (int i = 0; i < length; i++)
    {
        cout << names[i] << " ";
    }
    cout << endl;

    return 0;
}
