// find minimum number of coins required to make the target 
#include<iostream>
#include<limits.h>
using namespace std;
int minimumcoins(int *arr, int& size, int target){
    if(target==0){
        return 0;
    }
    if(target<0){  //target mhi bn skta aur out of bound chla gya
        return INT_MAX;
    }
    int mini = INT_MAX;
    // we will find ki target-arr[i] bnaane me kitne coins lge

    for(int i=0; i<size; i++){
        int ans= minimumcoins(arr,size,target-arr[i]);
         cout<< "ans is:" << ans<< endl;
         if(ans!= INT_MAX){
         mini = min(mini, ans+1);
         cout<< "mini is:"<< mini<< endl;
    }
 }
    return mini;     
}
int main() {
    int arr[] = {1,2,3};
    int size= 3;
    int target =5;
    int f= minimumcoins(arr,size,target);
    cout<< f<< endl;
   
}
