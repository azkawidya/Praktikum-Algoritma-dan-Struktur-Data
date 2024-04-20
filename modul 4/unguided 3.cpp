#include <iostream>
using namespace std;

// Fungsi untuk melakukan Sequential Search
int sequentialSearch(int arr[], int size, int key)
{
    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == key)
        {
            ++count;
        }
    }
    return count;
}

int main()
{
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int dataSize = sizeof(data) / sizeof(data[0]);
    int target = 4;

    int result = sequentialSearch(data, dataSize, target);

    cout << "Jumlah angka 4 dalam data adalah " << result << endl;

    return 0;
}
