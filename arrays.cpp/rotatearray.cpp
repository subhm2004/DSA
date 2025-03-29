// rotate array k times
#include<iostream>
#include<vector>
using namespace std;
void rotatearray(int arr[], int& size, int& k, vector<int>&ans ) {
    for(int i=0; i<size; i++) {
      ans[(i+k)%size] = arr[i];  
    }
}
void printarray(vector<int>& ans) {
    for(int i=0; i<ans.size(); i++) {
        cout<< ans[i]<< " ";
    }
}
int main() {
    int arr[] = {10,20,30,40,50,60,70,80};
    int k, size = 8;
    cout<< " enter number of times to rotate "<< endl;
    cin >> k;
    vector<int>ans(size);
    rotatearray(arr, size, k, ans);
    printarray(ans);

}