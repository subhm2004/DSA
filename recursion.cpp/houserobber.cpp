#include<iostream>
using namespace std;
int rob(int arr[], int& size, int index){
    if(index >= size){
        return 0;
    }
   // exclude 1st ghar
   int ans= 0+ rob(arr,size,index+1);
   // include 1st ghar

   int ans2= arr[index] + rob(arr,size,index+2);
   return max(ans,ans2);
}
int main(){
    int arr[]= {1,2,3,1};
    int size= 4;
    int index=0;
    cout<< "maximum amount is: "<< rob(arr,size,index)<< endl; 

}