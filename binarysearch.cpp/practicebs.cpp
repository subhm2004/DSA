 // first occurrence of an eleemnt in a sorted array
 #include<iostream>
 #include<algorithm>
 #include<set>
 using namespace std;
// int firstocc(int *arr, int& size, int& target){
//     int s=0;
//     int e = size-1;
//     int mid = s+(e-s)/2;
//     int ans= -1;
//     while(s<=e){
//         if(arr[mid] == target){
//             ans = mid;
//             e= mid-1;
//         }
//         else if(arr[mid]> target){
//             e= mid-1;
//         }
//         else {
//             s= mid+1;
//         }
//         mid= s+(e-s)/2;
//     }
//     return ans;
// }
// // last occureence of an element in a sorted array
// int lastocc(int *arr, int& size, int& target){
//     int s=0, e= size-1;
//     int mid= s+(e-s)/2;
//     int ans= -1;
//     while(s<=e){
//         if(arr[mid]== target){
//             ans= mid;
//             s= mid+1;
//         }
//         else if(arr[mid] > target){
//             e= mid-1;
//         }
//         else {
//             s= mid+1;
//         }
//         mid= s+(e-s)/2;
//     }
//     return ans;
// }
// // find the missing element in a sorted array
// int missingelement(int *arr, int& size){
//     int s=0, e= size-1;
//     int mid= s+(e-s)/2;
//     while(s<=e){
//         if(arr[mid]== mid+1){
//             if(s==e){
//                 return arr[mid] + 1 ;
//             }
//             s= mid+1;
//         }
//         else {
//             if(s==e){
//                 return arr[mid] - 1 ;
//             }
//             e= mid-1;
//         }
//         mid= s/2 + e/2;
//     }
// }
// // peak element in a mountain array
// int peakelement(int *arr, int& size){
//     int s=0, e= size-1;
//     int mid= s+(e-s)/2;
//     while(s<=e){
//         if(s==e){
//             return arr[mid];
//         }
//         else if(arr[mid] < arr[mid+1]){
//             s= mid+1;
//         }
//         else{
//             e= mid;
//         }
//         mid= s+(e-s)/2;
//     }
// }
// // find the maximum elemnet in a rotated and sorted array
// int pivotindex(int *arr, int& size){
//     int s=0, e= size-1;
//     int mid= s+(e-s)/2;
//     while(s<=e){
//         if(s==e){
//             return s;
//         }
//         else if(arr[mid]> arr[mid+1] && mid+1< size){
//             return mid;
//         }
//         else if(arr[mid]< arr[mid-1] && mid-1>=0){
//             return mid-1;
//         }
//         else if(arr[mid]< arr[s]){
//             e= mid-1;
//         }
//         else {
//             s= mid+1;
//         }
//         mid= s+(e-s)/2;
//     }
// }
// int binarysearch(int *arr, int& size, int s, int e, int& target){
//     s=0, e= size-1;
//     int mid= s+(e-s)/2;
//     while(s<=e){
//         if(arr[mid]== target){
//             return mid;
//         }
//         else if(arr[mid]> target){
//             e= mid-1;
//         }
//         else {
//             s= mid+1;
//         }
//         mid= s+(e-s)/2;
//     }
// }
// // search target in rotated and sorted array
// int search(int *arr, int& size, int& ans, int& target){
//     int s=0, e= size-1;
//     int mid= s+(e-s)/2;
//     if(target<arr[ans] && target> arr[s] ){
//         // search in first part
//         return binarysearch(arr, size, 0, ans, target);
//     }
//     else {
//         return binarysearch(arr, size, ans+1, size-1, target);
//     }
// } 
// int sqrt(int &n){
//     int s=0;
//     int e= n;
//     int mid= s+(e-s)/2;
//     int ans= -1;
//     while(s<=e){
//         if(mid*mid== n){
//             return mid;
//         }
//         else if(mid* mid> n){
//             e= mid-1;
//         }
//         else {
//             ans = mid;
//             s= mid+1;
//         }
//         mid= s+(e-s)/2;
//     }
//     return ans;
// }
// // search in a 2D array
// int binarysearch(int *arr, int& row, int& col) {
    
// }

// int main(){
//     int n;
//     cout<< "enter any number"<< endl;
//     cin>> n;
//     int ans = sqrt(n);
//     cout<< ans << endl;
//     // int arr[] = {12,14,15,16,2,4,6,8,10};
//     // int size= 9;
//     // int s=0, e= size-1;
//     // int target= 4;
//     // int ans= pivotindex(arr, size);
//     // cout<< ans<< endl;
//     // int fans= search(arr, size, ans, target);
//     // cout<< fans<< endl;
//     // int ans= peakelement(arr, size);
//     // cout<< ans<< endl;
//     // int ans= missingelement(arr, size);
//     // cout<< ans<< endl;
//     // int target= 30;
//     // int f= lastocc(arr, size,target);
//     // cout<< f<< endl;

// }

int firstocc(int *arr, int& size, int& target){
    int s=0, e= size-1;
    int mid= s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(arr[mid]== target){
            ans= mid;
            e= mid-1;
        }
        else if(arr[mid]> target){
            e= mid-1;
        }
        else {
            s= mid+1;
        }
        mid= s+(e-s)/2;   
    }
    return ans;
}
int lastocc(int *arr, int& size, int& target){
    int s=0, e= size-1;
    int mid= s+(e-s)/2;
    int ans= -1;
    while(s<=e){
        if(arr[mid]== target){
            ans= mid;
            s= mid+1;    
        }
        else if(arr[mid]> target){
            e= mid-1;
        }
        else {
            s= mid+1;
        }
        mid= s+(e-s)/2;
    }
    return ans;
}
int missingelement(int *arr, int& size){
    int s=0, e= size-1;
    int mid= s+(e-s)/2;
    while(s<=e){
        if(arr[mid]== mid+1){

            s= mid+1;
        }
        else if(arr[mid]== mid+2){
            if(s==e){
                return arr[mid]-1;
            }
            e= mid;
        }
        mid= s+(e-s)/2;
    }
}
int peakelement(int *arr, int& size){
    int s=0, e= size-1;
    int mid= s+(e-s)/2;
    while(s<e){
    if(arr[mid+1]>arr[mid] ){
        s= mid+1;
    }
    else if(arr[mid+1]< arr[mid]){
        e= mid;
    }
    mid= s+(e-s)/2;
    }
    return mid;
}
// pivot element: find the maximum elemnet in a rotated and sorted array
int pivotindex(int* arr, int& size){
    int s=0, e= size-1;
    int mid= s+(e-s)/2;
    while(s<=e){
        if(s==e){
            return s;
        }
        if(arr[mid]> arr[mid+1] && mid+1< size){
            return mid;
        }
        else if(arr[mid]< arr[mid-1] && mid-1>=0){
            return mid-1;
        }
        else if(arr[mid]< arr[s]){
            e= mid-1;
        }
        else {
            s= mid+1;
        }
        mid= s+(e-s)/2;
    }
}
// search in a rotated and sorted array
int search(int *arr, int& size, int& target){
    int s=0, e= size-1;
    int index= pivotindex(arr,size);
    if(target>= arr[s] && target<= arr[index]){
        // search in left part
        return binarysearch(arr,size,s,index,target);
    }
    else if(target>= arr[index+1] && target< arr[size-1]){
        // search in right part
        return binarysearch(arr,size,index+1,size-1, target);
    }
}
int sqrt(int& n){
    int s=0, e= n;
    int mid= s+(e-s)/2;
    int ans= -1;
    while(s<=e){
        if(mid*mid > n){
            e= mid-1;
        }
        else {
            ans = mid;
            s= mid+1;
        }
        mid= s+(e-s)/2;
    }
    return ans;
}
int quotient(int& dividend, int& divisor){
    int s=0, e= dividend;
    int mid= s+(e-s)/2;
    int ans= -1;
    while(s<=e){
        if(mid*divisor> dividend){
            e= mid-1;
        }
        else {
            ans= mid;
            s= mid+1;
        }
        mid= s+(e-s)/2;
    }
    return ans;
}
// binary search in a nearly sorted array
int nearlysorted(int *arr, int& size, int& target){
    int s=0, e= size-1;
    int mid= s+(e-s)/2;
    while(s<=e){
        if(arr[mid]== target){
            return mid;
        }
        else if(arr[mid+1]== target){
            return mid+1;
        }
        else if(arr[mid-1]== target){
            return mid-1;
        }
        else if(arr[mid]> target){
            e= mid-2;
        }
        else {
            s= mid+2;
        }
        mid= s+(e-s)/2;
    }
    return mid;
}
// k different pairs in an array
int kdiffpairs(int *arr, int& size, int& k){
    sort(arr,arr+size);
    int i=0;
    int j= i+1;
    set<pair<int,int>>ans;
    while(i<=j){
        if(arr[j]-arr[i]==k){
            ans.insert(arr[i], arr[j]);
            i++;
            j++;
        }
        else if(arr[j]- arr[i]> k){
            i++;
        }
        else {
            j++;
        }
        if (i==j){
            j++;
        }
    }
    return ans.size();
}
int binarysearch(int *arr, int& size, int s, int e, int target){
    int mid= s+(e-s)/2;
    while(s<=e){
        if(arr[mid]== target){
            return mid;
        }
        else if(arr[mid]> target){
            e= mid-1;
        }
        else {
            s= mid+1;
        }
        mid= s+(e-s)/2;
    }
    return -1;
}
int findpairs(int *arr, int& size, int& k){
    set<pair<int,int>>ans;
    for(int i=0; i<size-1; i++){
        if(binarysearch(arr, size, i+1, size-1, arr[i]+k)!=-1){
            ans.insert({arr[i], arr[i]+k});
        }
    }
    return ans.size();
}
int main(){
    // int dividend= 29;
    // int divisor= 7;
    // int f= quotient(dividend, divisor);
    // cout<< f<< endl;

    int n=66;
    int arr[]= {3,1,4,1,5};
    int size= 5;
    int k=2;
    int target= 50;
    // int ans= nearlysorted(arr,size, target);
    // cout<< ans<< endl;
    // int ans= sqrt(n);
    // cout<< ans<< endl;
    // int ans= search(arr,size,target);
    // cout<< ans<< endl;ne
    // int ans= search(arr,size,target);
    // cout<< ans<< endl;
    // int f= lastocc(arr,size, target);
    // cout<< f<< endl;
    // int ans= binarysearch(arr, size, target);
    // cout<< ans<< endl;

}


