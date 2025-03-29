// count number of 0's and 1's in a program
/*#include<iostream>
using namespace std;
int main() {
    int arr[]= {1,0,0,0,1,1};
    int size = 6;
    int j=0;
     int k=0;
     for(int i=0; i< size; i++) {
        if(arr[i]== 1) {
            j++;
        }
        else {
            k++;
        }
     }
     cout<< "number of 1's are "<< j<< endl;
     cout<< "number of 0's are "<< k<< endl;
     return 0;
}*/
// largest element of an array
#include<iostream>
using namespace std;
int main() {
    int n;
    cout<< "enter the size of array"<< endl;
    cin>> n;
    int arr[n];
    cout<< "enter the elemnets of array"<< endl;
    for(int i=0; i<n; i++) {
        cin>> arr[i];
    }
    int largest = arr[0];
    for(int i=0; i<n; i++) {
        if(arr[i]> largest) {
            largest = arr[i];
        }
    }
    cout<< "largest element is "<< largest<< endl;
    }