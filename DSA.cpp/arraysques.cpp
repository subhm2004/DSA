#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
void printarray(int arr[][3], int row, int col) {
    for(int j=0; j<col; j++) {
        for(int i=0; i<row; i++) {
            cout<< arr[i][j]<< endl;
        }
    }
}
bool linearsearch(int arr[][3], int& row, int& col, int& target) {
    for(int i=0; i<row; i++){
        for(int j=0; j< col; j++) {
            if(arr[i][j] == target) {
                return true;
            }
        }
    }
    return false;
}
int maxelement(int arr[][3], int& row, int& col, int& max) {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    return max;
}
void rowwisesum(int arr[][3], int& row, int& col) {   
    for(int i=0; i<row; i++) {
        int sum =0;
        for(int j=0; j< col; j++) {
            sum = sum + arr[i][j];
        }
        cout<< " sum of " << i << " row is " << sum << endl;
    }
}
void colwisesum(int arr[][3], int& row, int& col) {
    for(int j=0; j<col; j++) {
        int sum =0;
        for(int i=0; i<row; i++) {
            sum = sum + arr[i][j];
        }
        cout<< "sum of "<< j<< " column is "<< sum<< endl;
    }
}
void diagonalsum(int arr[][3], int& row, int& col) {
    int sum =0;
    for(int i=0; i< row; i++) {
        sum = sum + arr[i][i];
    }
    cout<< " sum of diagonal elements is "<< sum<< endl;
}
void printmatrix(int arr[][3], int row, int col) {
    cout<< "matrix is "<< endl;
    for(int i=0; i<row; i++) {
        for(int j=0; j< col; j++) {
            cout<< arr[i][j]<< "  ";
        }
        cout<< endl;
    }
}
void transpose(int arr[][3], int row, int col) {
    cout<< " transpose of the matrix is "<< endl;
    for(int i=0 ; i< row; i++) {
        for(int j=0 ; j< col; j++) {
            cout<< arr[j][i]<< "  ";
        }
        cout<< endl;
    }
}
int main() {
    int arr[3][3] = {
                     {10,20,30},
                     {40,50,60},
                     {70,80,90}
                    } ;

    int row = 3;
    int col = 3;
    int max = INT_MIN;
    //printmatrix(arr, row, col);
    //transpose(arr, row, col);
    vector<int>brr;
    cout<< brr.size() << endl;
    // int ans = maxelement(arr, row, col, max);
    // cout<< ans<< endl;
    // int target = 70;
    // bool ans = linearsearch(arr,row,col, target);
    // cout<< ans<< endl;
    
}