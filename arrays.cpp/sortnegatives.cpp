#include<iostream>
using namespace std;
void sortnegative(int arr[], int& size,int& i, int& j) {
    while(i<size) {
        if(arr[i]>= 0) {
            i++;
        }
        else {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
    }

}
int main() {
    int arr[] = {23,-7, 12, -10, -11, 40, 60};
    int size = 7;
    int i=0, j=0;
    sortnegative(arr, size, i, j);

    // int brr[size];
    // int j=0, k= size-1;
    // for(int i=0; i< size; i++) {
    //     if(arr[i] >0) {
    //         brr[k] = arr[i];
    //         k--;
    //     }
    //     else {
    //         brr[j] = arr[i];
    //         j++;
    //     }
    //}
    //printing  array
    for(int i=0; i< size; i++) {
        cout<< arr[i] << "  ";
    }
}