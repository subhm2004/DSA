// maximum sum of no adjacent elements
// return the maximum sum of subsequence in which no two elements are adjacent
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
void maximumsum(vector<int>&arr, int i, int& maxi, int sum) {
    if(i>= arr.size()) {
        // return max(maxi, sum)  mistake 1
       maxi= max(maxi, sum); 
       return;
    } 
       
    // include   
   // sum = sum + arr[i]; mistake 2
    maximumsum(arr, i+2, maxi, sum+ arr[i]); 
     // exclude
    maximumsum(arr, i+1, maxi, sum);
          
}

int main() {
    vector<int>arr = {2,1,4,9};
    int i=0, sum =0;
    int maxi= INT_MIN;
    maximumsum(arr, i, maxi, sum);
    cout<< "maximum sum is "<< maxi << endl;
}
