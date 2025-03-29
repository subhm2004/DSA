// extreme print in an array
#include<iostream>
#include<vector>
using namespace std;
int unique(vector<int>arr) {
    int ans=0;
    for(int i=0; i< arr.size(); i++) {
        ans = ans^arr[i];

    }
    return ans;
}

int main() {
   /* int arr[] = { 10, 20, 30, 40, 60, 70 , 80 };
    int size = 7 ;
    int i = 0;
    int j= size - 1 ;
    while(i<=j) {
        if(i==j) {
            cout<< arr[i] << endl;
        }
        else { cout<< arr[i]<< " ";
               cout<< arr[j] << " ";
        }
               i++;
               j--;
        
    }*/
    // reverse of an array- create the reversed array and then print it.
    /*while(i<=j) {
        int temp;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j ]= temp;
        
        i++;
        j--;

    }
    for(int i=0; i< size ; i++) {
        cout<< arr[i] << " ";
    }

    return 0;*/
    //int uni = unique(arr);
    //cout<< "unique element is "<< uni << endl;
    /*int arr[] = {1,2,3,4,5};
    int brr[] = { 9,8,7,6};
    int sizearr = 5;
    int sizebrr = 4;
    vector<int> ans;
    for(int i=0; i< sizearr; i++) {
        ans.push_back(arr[i]);
    }
    for(int i=0; i< sizebrr; i++) {
        ans.push_back(brr[i]);
    }
    cout<< "elements in new array are "<< endl;
    for(int i=0; i<ans.size(); i++) {
        cout<< ans[i] << " ";
    }
    return 0;*/
    // intersesction of two elements 
    int arr[]  = {1,2,3,4,5};
    int sizearr = 5;
    int brr[] = { 2,5,6,7};
    int sizebrr = 4;
    
    for(int i=0; i< sizearr ; i++) {
        for(int j=0; j< sizebrr; j++) {
            if(arr[i]== brr[j]) {
                cout<< arr[i] << " ";

            }
        }
    }

}