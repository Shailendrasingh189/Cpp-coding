#include <iostream>
using namespace std;
// selection sort algorithm

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int smallestIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[smallestIdx])
            {
                smallestIdx = j;
            }
        }
        swap(arr[i], arr[smallestIdx]);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;

    selectionSort(arr, n);
    printArray(arr, n);

    return 0;
}