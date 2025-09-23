#include <iostream>
using namespace std;

class MergeSort
{
public:
    void merge(int *arr, int low, int mid, int high)
    {
        int n = high - low + 1;
        int *temp = new int[n];
        int left = low, right = mid + 1, idx = 0;

        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
                temp[idx++] = arr[left++];
            else
                temp[idx++] = arr[right++];
        }

        while (left <= mid)
            temp[idx++] = arr[left++];
        while (right <= high)
            temp[idx++] = arr[right++];

        for (int i = 0; i < n; ++i)
            arr[low + i] = temp[i];

        delete[] temp; // free memory
    }

    void mergeSort(int *arr, int low, int high)
    {
        if (low >= high)
            return;

        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }

    void sort(int *arr, int n)
    {
        mergeSort(arr, 0, n - 1);
    }
};
int main()
{
    int arr[] = {5, 3, 8, 4, 2, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    MergeSort sorter;
    sorter.sort(arr, n);

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
