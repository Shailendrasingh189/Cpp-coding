#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int st, int mid, int end) // TC - O(n)
{
    vector<int> temp;

    int i = st;      // left half
    int j = mid + 1; // right half

    while (i <= mid && j <= end) // sorting
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid) // left half remaining
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= end) // right half remaining
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int idx = st; idx <= end; idx++) // copy back to original array
    {
        arr[idx] = temp[idx - st];
    }
}

void mergeSort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2; // mid point

        mergeSort(arr, st, mid);      // left half
        mergeSort(arr, mid + 1, end); // right half

        merge(arr, st, mid, end); // merge both halves - backtracking
    }
}

int main()
{

    vector<int> arr = {12, 31, 35, 8, 32, 17};

    mergeSort(arr, 0, arr.size() - 1); // merge sort call

    for (int val : arr) // print values
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
