#include<iostream>
#include<vector>
using namespace std;
int main() {
    //declaring vector
    vector<int> arr;
    arr.push_back(5);
    arr.push_back(7);
    // size denotes number of elements in the vector
    // capacity denotes number of a vector can store in total
    cout<< arr.size() << endl;
    cout<< arr.capacity() << endl;
    
    for(int i=0; i< arr.size(); i++) {
        cout<< arr[i]<< " ";
    }
    cout<< "\n";
    arr.pop_back();
    for(int i=0; i< arr.size(); i++) {
        cout<< arr[i]<< " ";
    }
    cout<< endl;
    cout<< arr.size() << endl;
    cout<< arr.capacity() << endl;
    // initialisation of vector
    vector<int> brr{10, 20, 30};
    for(int i=0; i< brr.size(); i++) {
        cout<< brr[i] << " ";
    }
    cout<< "\n";
    // second way of initialisation
    vector<int> crr(10, -2);
    for(int i=0; i< crr.size(); i++) {
        cout<< crr[i]<< " ";
    }
    return 0;

}