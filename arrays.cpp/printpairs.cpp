// print all the pairs for the given array
#include<iostream>
using namespace std;

int main() {
    int arr[] = {10,20,30};
    int size =3;
    cout<< "pairs of the array are"<< endl;
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            cout<< arr[i]<< ","<< arr[j]<< endl;
        }
    }
}