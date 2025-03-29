// print sum of elements of array
#include<iostream>
using namespace std;
int sumarray(int arr[], int& size, int i, int& sum) {
    if(i>= size) {
        return sum;
    }
    sum = sum + arr[i];
    sumarray(arr, size, i+1, sum);
}
int main() {
    int arr[] = {1,2,3,4,5,6} ;
    int size= 6;
    int i=0;
    int sum =0;
    int ans = sumarray(arr, size, i, sum);
    cout<< "sum of array elements are "<< ans<< endl;
}


