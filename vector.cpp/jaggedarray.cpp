// a 2-D vector of vector with different sizes is called jagged array
#include<iostream>
#include<vector>
using namespace std;
int main() {
    // initializing vector of vector
    vector<vector<int> > arr;
    // initialsing individual vectors 
    vector<int>vec1(10,1);
    vector<int>vec2(7,0);
    vector<int>vec3(7,1);
    vector<int>vec4(5,-1);
    // inserting vectors into 2d vector
    arr.push_back(vec1);
    arr.push_back(vec2);
    arr.push_back(vec3);
    arr.push_back(vec4);
    // printing 2d array
    cout<< "vector of vector is"<< endl;
    for(int i=0; i< arr.size(); i++) {
        for(int j=0; j< arr[i].size(); j++) {
            cout<< arr[i][j]<< " ";
        }
        cout<< endl;
    }
}
