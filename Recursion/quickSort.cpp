#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int st, int end)
{
    int idx = st - 1, pivot = arr[end];

    for (int j = st; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            idx++;
            swap(arr[idx], arr[j]); // left partition
        }
    }

    idx++;
    swap(arr[idx], arr[end]); // pivot to the right place

    return idx; // return pivot index
}

void quickSort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int pivIdx = partition(arr, st, end);

        quickSort(arr, st, pivIdx - 1); // left half call

        quickSort(arr, pivIdx + 1, end); // right half call
    }
}

int main()
{
    vector<int> arr = {5, 2, 6, 4, 1, 3};

    quickSort(arr, 0, arr.size() - 1);

    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}