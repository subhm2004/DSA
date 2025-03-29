// you are given a 2d matrix consisiting of zeroes and ones only
// find the row index that contains maximum ones
// also find the maximum no. of ones
#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
void maximumones(int arr[][3], int&m , int& n, vector<int>&ans) {
    int onecount = INT_MIN;
    int row = -1;
    for(int i=0; i<m; i++) {
        int count = 0;
        for(int j=0; j<n; j++) {
            if(arr[i][j] ==1){
                count++;
            }
        }
        if(onecount< count) {
            row = i;
        }
        if(onecount < count){
            onecount = count;
        }    
    }
    ans.push_back(onecount);
    ans.push_back(row);
}
int main() {
    int arr[][3] = {{1,0,0},{0,0,0}, {1,1,1}, {0,1,1}};
    int m= 4, n=3;
    vector<int>ans;
    
    maximumones(arr , m,n,ans);
    for(int i=0; i< ans.size(); i++) {
        cout<< ans[i]<< " ";
    }
}
