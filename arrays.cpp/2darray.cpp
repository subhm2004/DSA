#include<iostream>
using namespace std;
int main() {
    int row, col;
    cout<< "enter the number of rows and columns"<< endl;
    cin>> row>> col;
    int arr[20][20];
    cout<< "enter the elements of array"<< endl;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cin>> arr[i][j];
        }
    }
    // printing 2D array
    cout<< "2-D array is"<< endl;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cout<< arr[i][j]<< "\t";
        }
        cout<< "\n";
    }
    // printing row sum
    for(int i=0; i<row; i++) {
        int sum=0;
        for(int j=0; j<col; j++) {
            sum = sum + arr[i][j];

        }
        cout<< "sum of elements of row "<< i<< "is "<< sum<< endl;
    }
    return 0;
}