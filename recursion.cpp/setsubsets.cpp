// find all the subsets of a given set
#include<iostream>
#include<vector>
using namespace std;

void printvecofvec(vector<vector<int>>&brr, vector<int>&ans) {
    for(int i=0; i<brr.size(); i++) {
        for(int j=0; j<brr[i].size(); j++) {
            cout<< brr[i][j]<< " ";
        }
    }
 }
void subsets(int arr[], int& size, int i, vector<int>ans, vector<vector<int>> brr) {
    if(i>=size) {
        for(int j=0; j<ans.size(); j++) {
            brr.push_back(ans);
        }
    }
    // exclude ki call
    subsets(arr, size, i+1, ans, brr);
    // include ki call
    ans.push_back(arr[i]);
    subsets(arr, size, i+1, ans, brr);

}
int main() {
    int arr[] = {1,2,3};
    vector<vector<int>> brr;
    vector<int>ans;
    int size=3;
    int i=0;
    subsets(arr, size, i, ans, brr);
     for(int i=0; i<brr.size(); i++) {
        for(int j=0; j<brr[i].size(); j++) {
            cout<< brr[i][j]<< " ";
        }
     }
      
}