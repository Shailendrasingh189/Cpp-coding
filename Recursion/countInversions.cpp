#include <iostream>
#include <vector>
using namespace std;
// using merge sort

int merge(vector<int> &arr, int st, int mid, int end) // TC - O(n)
{
    vector<int> temp;

    int i = st;      // left half
    int j = mid + 1; // right half
    int invCount = 0;

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
            invCount += (mid - i + 1);
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

    for (int idx = 0; idx < temp.size(); idx++) // copy back to original array
    {
        arr[idx + st] = temp[idx];
    }

    return invCount;
}

int mergeSort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2; // mid point

        int leftInvCount = mergeSort(arr, st, mid);       // left half count
        int rightInvCount = mergeSort(arr, mid + 1, end); // right half count

        int invCount = merge(arr, st, mid, end);

        return leftInvCount + rightInvCount + invCount;
    }
    return 0;
}

int main()
{
    vector<int> arr = {6, 3, 5, 2, 7};

    int ans = mergeSort(arr, 0, arr.size() - 1);

    cout << "Inversion count : " << ans << endl;

    return 0;
}