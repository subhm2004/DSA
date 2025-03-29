// creating a 2-D array using dyanmic memory
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int row= 5;
    int col=3;
    int **arr= new int*[5];
    for(int i=0; i< row; i++){
        arr[i] = new int[col];
    }
    // vector<vector<int> > arr(row,vector<int>(col,0));
    cout<< "2-D array is\n";
    for(int i=0; i< row; i++){
        for(int j=0; j< col; j++){
            cout<< arr[i][j]<< " ";
        }
        cout<< endl;
    }
    // deallocating
    for(int i=0; i< row; i++){
        delete []arr[i];
    }
    delete []arr;
}