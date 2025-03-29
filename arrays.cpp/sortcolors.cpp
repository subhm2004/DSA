// 0 represents red, 1 represents white and 2 represents blue
#include<iostream>
#include<vector>
using namespace std;
void sortcolors(vector<int>&nums, int& n) {
    for(int i=0; i<n; i++) {
        nums.push_back(0);
    }
    for(int i=0; i<n; i++) {
        nums.push_back(1);
    }
    for(int i=0; i<n; i++) {
        nums.push_back(2);
    }    
}

void printarray(vector<int>nums) {
    for(int i=0;i< nums.size(); i++) {
        cout<< nums[i]<< "  ";
    }
}
void sortcolors2(vector<int>&nums) {
    for(int i=1; i<nums.size(); i++) {
        int value = nums[i];
        for(int j= i-1; j>=0; j--) {
            if(nums[j]> value) {
                swap(nums[j], nums[j+1]);
            }
        }
    }
}
void sortcolors3(vector<int>&nums) {
    int n= nums.size();
    int j=0, k= n-1;
    int i=0;

        while(i<k) {
        if(nums[i] == 0) {
            swap(nums[i], nums[j]);
            j++;
            i++;
        }
        else if(nums[i] == 2) {
            swap(nums[i], nums[k]);
            k--;
        }
        else{
            i++;
        }
    }
}
int main() {
    // int n;
    // cout<< "enter the objects of each color "<< endl;
    // cin>> n;
    vector<int> nums{1,2,0,1,0,2,2,1,0};
    //sortcolors2(nums);
    //sortcolors(nums, n);
    sortcolors3(nums);
    printarray(nums);
}