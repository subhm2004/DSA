// you are given an array, find the k closest elemnets to the given target
// closest elemnets are in the array
#include<iostream>
#include<vector>
using namespace std;
void closestpairs(vector<int>& nums, int& k, int& target){
    int l=0, h= nums.size()-1;
    while(h-l >=k){
        if(abs(nums[l]-target)> abs(nums[h]-target)){
            l++;
        }
        else{
            h--;
        }
    }
    for(int i=0; i<k; i++){
        cout<< nums[l]<< endl;
        l++;
    }
}
int main(){
    vector<int>nums= {12,16,22,30,35,39,42,45,48,50,53,55,56};
    int k=4;
    int target= 35;
    closestpairs(nums,k,target);

}