#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int factorial(int n){
    if(n==0|| n==1){
        return 1;
    }
    return n*factorial(n-1);
}
int sum(int n){
    if(n==1){
        return 1;
    }
    if(n==0){
        return 0;
    }
    return n+ sum(n-1);
}
int climbstairs(int n){
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    return climbstairs(n-1)+ climbstairs(n-2);
}
void printcount(int n){
    if(n==1){
        cout<< 1<< " ";
        return;
    }
    //cout<< n<< " ";   tail recursion
    printcount(n-1);
    cout<< n << " ";
}
int fibonacci(int n){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    return fibonacci(n-1)+ fibonacci(n-2);
}
void linearsearch(int *arr, int &size, int index, int& target){
    if(index>= size){
        return ;
    }
    if(arr[index]== target){
        cout<< index<< " ";
    }
    
    return linearsearch(arr,size,index+1,target);
}

void printarray(int arr[], int n){
    if(n<=0){
        return;
    }
    // cout<< arr[n-1]<< " ";
    printarray(arr,n-1);
    cout<< arr[n-1]<< " ";
}

int binarysearch(int arr[], int &n, int s, int e, int &target){
        if(s>e){
            return -1;
        }
        int mid= s+(e-s)/2;
        if(arr[mid]== target){
            return mid;
        }
        else if(arr[mid] > target){
            return binarysearch(arr,n,s,mid-1,target);
        }
        else{
            return binarysearch(arr, n,mid+1, e,target);
        }
}
int minimumno(int *arr, int& size, int& mini, int index){
    cout<< index<< endl;
    if(index>= size){
        return mini;
    }
    if(arr[index] < mini){
        mini= arr[index];
    }
    cout<< mini<< endl;
    minimumno(arr,size,mini,index+1);

}

void evennum(vector<int>&nums, int* arr, int index, int& size){
    if(index ==size){
        for(int i=0; i<nums.size(); i++){
            cout<< nums[i]<< " ";
        }
        return;
    }
    if(arr[index]%2== 0){
        nums.push_back(arr[index]);
    }
    evennum(nums,arr,index+1,size);
}
void doubleeach(int *arr, int index, int& size){
    if(index==size){
        for(int i=0; i<size; i++){
            cout<< arr[i]<< " ";
        }
        return;
    }
    arr[index]= 2*arr[index];
    doubleeach(arr,index+1, size);   
}
void printdigits(int n){
    if(n==0){
        return;
    }
    int rem= n%10;
    // cout<< rem<< " ";
    printdigits(n/10);
    cout<< rem<< endl;  
}
bool sortedarray(int *arr, int index, int& size){
    if(index+1 >= size){
        return true;
    }
    if(arr[index+1] > arr[index]) {
        return sortedarray(arr, index+1 ,size);
    }
    else {
        return false;
    }
}
void subsequence(string str, string ans,int index){
    if(index>= str.length()){
        cout<< ans << endl;
        return;
    }
    char ch= str[index];
    subsequence(str,ans,index+1);
    ans.push_back(ch);
    subsequence(str,ans,index+1);
}
void subsequence2(string str, string ans, int index){
    if(index>= str.length()){
        cout<< ans<< endl;
        return;
    }
    char ch= str[index];
    // include ki call
    ans.push_back(ch);
    subsequence2(str,ans,index+1);
    // exclude ki call me ans me already element include ho chuke h 
    // isliye pehle unhe pop back kro
    ans.pop_back();
    subsequence2(str, ans, index+1);
}
int maximumsum(int *arr,int sum, int& size, int index){
    if(index>= size){
        return sum;   
    }
    // exclude 1st element 
    int a= maximumsum(arr,sum,size,index+1);
    // include element
    sum= sum+ arr[index];  
    int b= maximumsum(arr,sum,size,index+2);
    //cout<< b<< endl;
    sum= max(a,b);   
}
void mergearray(int *arr, int& size, int s, int e){
    int mid= s+(e-s)/2;
    int length1= mid-s+1;
    int length2= e-mid;
    int *left= new int[length1];
    int *right= new int[length2];
    // copy the values in left and right subarrays
    int k=s;
    for(int i=0; i< length1; i++){
        left[i]= arr[k];
        k++;
    }
    k= mid+1;
    for(int i=0; i< length2; i++){
        right[i]= arr[k];
        k++;
    }
    // merging the two arrays
    int i=0, j=0;
    k=s;
    while(i<length1 && j<length2){
        if(left[i]<= right[j]){
            arr[k++]= left[i++];
        }
        else {
            arr[k++]= right[j++];
        }
    }
    while(i<length1){
        arr[k++]= left[i++];
    }
    while(i<length2){
        arr[k++]= right[j++];
    }

}
void mergesort(int* arr, int& size, int s, int e){
    // base case
    if(s>=e){
        return;
    }
    int mid= s+(e-s)/2;
    mergesort(arr,size,s,mid);
    mergesort(arr,size,mid+1,e);
    mergearray(arr,size,s,e);
}
int partitionlogic(int *arr, int& size, int s, int e){
    int pivotindex= s;
    int pivotelement= arr[s];
    int count= 0;
    for(int i=s+1; i<=e; i++){
        if(arr[i] <= pivotelement){
            count++;
        }
    }
    int rightindex= s+count;
    swap(arr[rightindex], arr[pivotindex]);
    pivotindex= rightindex;
    int i=s, j=e;
    while(i<pivotindex && j> pivotindex){
        while(arr[i]<=arr[pivotindex] ){
            i++;
        }
        while(arr[j]> arr[pivotindex]){
        
            j--;
        }
        if(i<pivotindex && j> pivotindex){
            swap(arr[i], arr[j]);
        }
    }
    return pivotindex;
}
void quicksort(int *arr, int& size, int s,int e){
    if(s>=e){
        return;
    }
    int p= partitionlogic(arr,size,s,e);
    quicksort(arr,size,s,p-1);
    quicksort(arr,size,p+1,e); 
}
// permutations of a string
void permutations(string str, int index){
    if(index>= str.length()){
        cout<< str<< endl;
        return;
    }
    for(int j=index; j< str.length(); j++){
        swap(str[index], str[j]);
        permutations(str,index+1);
        swap(str[index], str[j]);
    }
}
int main(){
    int arr[]= {7,3,2,2,16,25,4,11,9};
    string str= "abc";
    int index=0;
    permutations(str,index);
   
    int sum= 0;
    int size= 9;
    int s=0, e= size-1;
    int target= 5;
    //int index=0;
    // quicksort(arr,size,s,e);
    // for(int i=0; i<size; i++){
    //     cout<< arr[i]<< " ";
    // }




    // int ans= maximumsum(arr,sum,size,index);
    // cout<< ans<< endl;
    // int n= 54897;
    // int arr[]= {10,20,50,70,11,500};
    // vector<int>nums;
    // string str= "abc";
    // string ans= "";

    //int index=0;
    //subsequence2(str,ans,index);

    // int mini= INT_MAX;
    // int size= 6;
    // int s=0, e= n-1;
    // int target= 50;
    // bool ans= sortedarray(arr,index,size);
    // cout<< ans<< endl;
    
    return 0;
}