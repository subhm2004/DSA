// transpose of a matrix
#include<iostream>
using namespace std;
void transpose(int arr[3][3]) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cout << arr[j][i] << " ";
        }
        cout<< endl;
    }
}
int main() {
    int arr[3][3];
    cout<< "enter the elements of array"<< endl;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cin>> arr[i][j];
        }
    }
    cout<< "elements of array are\n";
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cout<< arr[i][j]<< " ";
        }
        cout<< endl;
    }
    cout<< "transpose of the matrix is "<<endl;
    transpose(arr);
    return 0;
}
