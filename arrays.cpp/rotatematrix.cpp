// given a 2d matrix, rotate it in clockwise direction by 90 degree
#include<iostream>
using namespace std;
int main() {
    int arr[3][3] = {{1,2,3},
                     {4,5,6},
                     {7,8,9}
                    };
    // approach- pehle transpose kro fir hr row ko reverse kro
    for(int i=0; i<3; i++) {
        int k = 2;
        for(int j=0; j<3; j++) {
            c[j][k] = arr[i][j];
        }
        k--;
    }
    cout<< "new array is\n"<< endl;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cout<< c[i][j]<< " ";
        }
        cout<< endl;
    } 
           
}