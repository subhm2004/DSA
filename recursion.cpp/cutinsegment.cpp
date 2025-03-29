// you are given a rod of length n and you have to divide the rod into 3 parts x,y,z 
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int maxsegment(int n, int x, int y, int z ){
    if(n==0){
        return 0;
    }
    if(n<0){
        return INT_MIN;
    }
    // x length cut krli
    int a= maxsegment(n-x,x,y,z) +1;
    // y length cut krli
    int b= maxsegment(n-y,x,y,z) +1;
    // z length cut krli
    int c= maxsegment(n-z,x,y,z) +1;
    int ans= max(a, max(b,c));
    return ans;
}
int main() {
    int n;
    cout<< " enter the length of rod"<< endl;
    cin>> n;
    int x,y,z;
    cout<< "enter the three parts"<< endl;
    cin>> x>> y>> z;
    int f = maxsegment(n,x,y,z);
    if(f<0){
        cout<< "length can't be cut"<< endl;
    }
    else{
        cout<<"maximum segment is: "<<  f<< endl;
    }
    
}