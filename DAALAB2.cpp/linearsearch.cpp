//linear search using loop
#include<iostream>
using namespace std;
int main() {
    int arr[8]= {10,20,30,40,50,60,70,80};
    int n= 10;
    cout<< "Name: Vanshika Aggarwal"<< endl;
    cout<< "Roll No. 22001003138"<< endl;
    int search;
    cout<< "enter the element to search"<< endl;
    cin>> search;
    
   int flag=0;
    for(int i=0; i<n; i++) {
        if(arr[i]== search) {
            flag =1;
            cout<< "element is found at position "<< i<< endl;
            break;
        }
    }
    if(flag ==0) {
        cout<< "element not found"<< endl;
    }   
}