#include<iostream>
#include<limits.h>
using namespace std;
void columnsum(int arr[3][3]) {
    for(int i=0; i<3; i++) {
        int sum =0;
        for(int j=0; j<3; j++) {
            sum = sum + arr[j][i];
        }
        cout<< "sum of "<< i+1 << "column elements are "<< sum<< endl;
    }
}
void linearsearch(int arr[3][3], int search) {
    int flag =0;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(arr[i][j]== search) {
                cout<< "element found at row "<< i<< "and column "<< j<< endl;
                flag=1;
                break;
            }
        }
    }
    if(flag==0) {
        cout<< "element not found"<< endl;
    }
}
int maxelement(int arr[3][3]) {
    int max = INT_MIN;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(arr[i][j]> max) {
                max = arr[i][j];
            }
        }
    }
    return max;
}
int minelement(int arr[3][3]) {
    int min = INT_MAX;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(arr[i][j] < min) {
                min = arr[i][j];
                
            }
        }
    }
    return min;
}
int main() {
    int search;
    int arr[3][3];
    
    cout<< "enter the elements of array"<< endl;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cin>> arr[i][j];
        }
    }
    cout<< "elements of array are "<< endl;
    for(int i=0; i<3 ; i++) {
        for(int j=0; j<3; j++) {
            cout << arr[i][j]<< " ";

        }
        cout<< "\n";
    }
    //cout<< "enter the element to search"<< endl;
    //cin>> search;
    // column wise sum of array
   /*for(int j=0; j<3; j++) {
        int sum = 0;
        for(int i=0; i<3; i++) {
            sum = sum + arr[j][i];

        }
        cout<< "sum of elements of "<< j+1 << " column is "<< sum<< endl;
    }*/
   
    //columnsum( arr );
   
   // linearsearch(arr, search);
   int maximum = maxelement(arr);
   cout<< "maximum element of array is "<< maximum << endl;
   int minimum = minelement(arr); 
   cout<< "minimum elemnet of array is "<< minimum<< endl;  
    return 0;
}