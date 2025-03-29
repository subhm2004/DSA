#include<iostream>
using namespace std;
void printarray(int arr[], int size) {
    cout<< "array is"<< " ";
    for(int i=0; i<size; i++) {
        cout<< arr[i]<< " ";

    }
    cout<< endl;
}
bool uniqueocc(int arr[], int size) {
    int a=0, b=0, c=0;
    for(int i=0; i<size; i++) {
        if(arr[i] == 1) {
            a++;
        }
        else if(arr[i]==2) {
            b++;
    }
    else {
        c++;
    }
}
 cout<< "occurrence of 1 is "<< a<<" times"<< endl;
 cout<< "occurrence of 2 is "<< b<< " times" << endl;
 cout<< "occurrence of 3 is "<< c<<" times"<<  endl;
 if(a!=b && b!=c && c!=a) {
    return true;
 }
 else {
    return false;
 }

}
void duplicate(int arr[], int size) {
    int ans=0;
    for(int i=0; i<size; i++) {
        ans = ans^arr[i];
        cout<< ans<< " ";
    }    
}
int main() {
    int arr[]= { 1, 2 ,3,3,4};
    int size = 5;
    printarray(arr, size);
   // int ans= uniqueocc(arr, size);
   // cout<< ans<< endl;
    duplicate(arr, size);   
}