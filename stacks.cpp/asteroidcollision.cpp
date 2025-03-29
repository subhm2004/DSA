#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
void asteroidarray(vector<int>&asteroids){
    stack<int> st;
    st.push(asteroids[0]);
    int index=1;
    while(index<asteroids.size()){
        if(asteroids[index]< 0 && st.top()>0){
            int element= max(abs(asteroids[index]), abs(st.top()));
            st.pop();
            st.push(element);
        }
        else {
            st.push(asteroids[index]);
        }
        index++;
    }
}
int main(){
    vector<int>asteroids= {1,-2,10,-5};


}