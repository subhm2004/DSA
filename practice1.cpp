#include<iostream>
using namespace std;
void solve(int *arr, int& size){
    cout<< "inside soleve: arr is"<< arr<< endl;
    cout<< "inside solve: &arr is"<< &arr<< endl;
}

int main(){
    int arr[5]= {10,20,30,40,50};
    int size= 5;
    cout<< "insise main: arr is"<< arr<< endl;
    cout<< "inside main: &arr is"<< &arr<< endl;
    solve(arr,size);
    //  int* ptr= &arr[0];
     int (*ptr)[5]= &arr;
    // cout<< arr<< endl;
    // cout<< ptr<< endl;
    // cout<< *ptr[0] << endl;
}