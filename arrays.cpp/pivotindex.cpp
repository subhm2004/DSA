// find the pivot index of array
// that index which has same sum of elements on its left and right
#include<iostream>
using namespace std;
// int bruteforce(int arr[], int& size) {
//    for(int i=0; i<size; i++) {
//        int leftsum =0, rightsum =0;
//       // left ke elements ka sum nikalo
//       for(int j=0; j<i; j++) {
//           leftsum = leftsum + arr[j];
//       }
//       // right k elements ka sum nikalo
//       for(int j= i+1; j< size; j++) {
//          rightsum = rightsum + arr[j];
//       }
//       if(leftsum == rightsum ){
//          return i;
//       }
//    }
//    return -1;
// }
int pivot(int arr[], int size) {
   int sum =0;
   int left =0;
   cout<< "left is "<< left<< endl;
   for(int i=0; i< size; i++) {
      sum = sum + arr[i];
   }
   cout<< sum<< endl;

      for(int i=0; i< size; i++) {
         sum = sum - arr[i];
         cout<< "updated sum is "<<sum<< endl;
         if(i>0) {
         left = left + arr[i-1];
         cout<< " updated leftsum is "<< left<< endl;
         }
      if(left == sum) {
         return i;
         break;
      }
   }
   return -1;
}
int main() {
    int arr[] = {-1,-1,-1,-1,-1,0};
    int size = 6;
   //  int i=0, j = size-1;
   //  int leftsum =0, rightsum =0;
   //  leftsum = leftsum + arr[i];
   //  rightsum = rightsum + arr[j];
         int ans = pivot(arr, size);
         cout<< ans;
//     while(i<=j) {
//          if(leftsum == rightsum) {
//             if(i<j) {
//             i++;
//             j--;
//             leftsum = leftsum + arr[i];
//             rightsum = rightsum + arr[j];
//          }   
//             cout<< "pivot index is "<< i << endl;
//             break;
//          }
//          else if(leftsum > rightsum) {
//             j--;
//             rightsum = rightsum + arr[j];
//          }
//          else if(leftsum < rightsum) {
//             i++;
//             leftsum = leftsum + arr[i];
//          }    
//     }
//      if(i>j) {
//       cout<< -1;
//     }
 }