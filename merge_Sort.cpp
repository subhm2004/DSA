#include <iostream>
#include <vector>
using namespace std;

// Merge two sorted halves into a single sorted array
void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int i = low, j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= mid)
        temp.push_back(arr[i++]);
    while (j <= high)
        temp.push_back(arr[j++]);

    // Copy sorted elements back to original array
    for (int k = 0; k < temp.size(); k++)
        arr[low + k] = temp[k];
}

// Recursively divide and sort
void mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);      // Sort left half
    mergeSort(arr, mid + 1, high); // Sort right half
    merge(arr, low, mid, high);    // Merge both halves
}

int main()
{
    vector<int> arr = {9, 1, 4, 14, 4, 15, 6};
    int n = arr.size();

    cout << "Before sorting: ";
    for (int x : arr)
        cout << x << " ";
    cout << "\n";

    mergeSort(arr, 0, n - 1);

    cout << "After sorting: ";
    for (int x : arr)
        cout << x << " ";
    cout << "\n";

    return 0;
}
