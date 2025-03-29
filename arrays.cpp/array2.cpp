// linear search using functions
#include<iostream>
using namespace std;
bool search(int arr[], int size,int key) {
    for(int i=0; i<size; i++) {
        if(arr[i]== key) {
            return true;
        }

    }
    return false;

}
int main() {
    int arr[] = {2,0,5,1,7} ;
    int size = 5;
    int key;
    cout<< "enter the element to find"<< endl;
    cin>> key;
    bool ans = search(arr, size, key);
    if(ans == true) {
        cout<< "element found"<< endl;
    }
    else {
        cout<< "not found"<< endl;
    }
    return 0;


}