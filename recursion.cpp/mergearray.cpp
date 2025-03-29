// merge two sorted arrays
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int arr1[] = {2,4,6};
    int size1= 3;
    int arr2[] = {3,5,7,9,11};
    int size2 = 5;
    int ans[sizeof(arr1) + sizeof(arr2)];
    int i=0, j=0, k=0;
    // inserting the elements into array
    while(i<size1 && j<size2 ) {
    if(arr1[i]< arr2[j]) {
        ans[k] = arr1[i];
        i++;
    }
    else {
        ans[k] = arr2[j];
        j++;
    }
    k++;
    }
    // copy the elements of first array
    while(i< size1) {
        ans[k] = arr1[i];
        i++;
        k++;
    }
    while(j< size2) {
        ans[k] = arr2[j];
        j++;
        k++;
    }

    // printing the elements of sorted array
    for(int i=0; i< (size1 + size2); i++) {
        cout<< ans[i]<< "  ";
    }

}
