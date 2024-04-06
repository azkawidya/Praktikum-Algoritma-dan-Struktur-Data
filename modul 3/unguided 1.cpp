#include <iostream>
using namespace std;

// untuk menukar posisi dua elemen
void swap(double *xp, double *yp)
{
    double temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// untuk mencetak array
void printArray(double arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Algoritma Selection Sort
void selectionSort(double arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        // menemukan indeks elemen terkecil dalam sub array yang belum diurutkan
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[min_idx])
            {
                min_idx = j;
            }
        }
        // menukar elemen terkecil dengan elemen pertama dalam sub array
        swap(&arr[min_idx], &arr[i]);
    }
}

int main()
{
    int length = 5;
    double ips[] = {3.8, 2.9, 3.3, 4.0, 2.4};

    cout << "Indeks Prestasi Semester sebelum sorting: " << endl;
    printArray(ips, length);

    selectionSort(ips, length);

    cout << "\nIndeks Prestasi Semester setelah sorting: " << endl;
    printArray(ips, length);

    return 0;
}
