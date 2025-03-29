#include<iostream>
#include<vector>
using namespace std;
int find(vector<int>arr) {
    int ans=0;
    for(int i=0; i< arr.size(); i++) {
    ans= ans^arr[i];
    }
    return ans;
}
int main() {
    
    int n;
    cout<< "enter number of elements"<< endl;
    cin>> n;
    vector<int> arr(n);
    cout<< "enter the elements in array"<< endl;
    for(int i=0; i<arr.size(); i++) {
        cin>> arr[i];

    }
    int unique= find(arr);
    cout<< "unique element is "<< unique<< endl;
    return 0;

}