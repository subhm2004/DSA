// unique element in a vector
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int find(vector<int> arr) {
    int ans=0;
    for(int i=0; i< arr.size(); i++) {
        ans = ans^ arr[i];
    }
    return ans;
}
int main() {
    /*vector<int> arr{1,9,4,2};
    int sizearr = 4;
    vector<int> brr {6,7,8,0,3};
    int sizebrr = 5;
    vector<int> ans;
    for(int i=0; i < arr.size(); i++) {
        ans.push_back(arr[i]);
    }
    for(int i=0; i < brr.size(); i++) {
        ans.push_back(brr[i]);
    }*/
   /* cout<< "resulting array is"<< endl;
    for(int i=0; i< ans.size(); i++) {
        cout<< ans[i] << " ";
    }
     int unique= find(arr);
    cout<< "unique element is "<< unique<< endl;*/

    vector<int> crr{1,2,3,3,4,4};
    int sizecrr = 4;
    vector<int> drr{6,3,3,1,1,9,0};
    int sizedrr = 5;
    vector<int> ans;
    for(int i=0; i< crr.size(); i++) {
        for(int j=0; j< drr.size(); j++) {
            if(crr[i]== drr[j]) {
                
                ans.push_back(crr[i]); 
                crr[i] = INT_MIN;               
            }
        }
    }
    cout<< "intersection array is"<< endl;
    for(int i=0; i<ans.size(); i++) {
        cout<< ans[i]<< " ";

    }





}