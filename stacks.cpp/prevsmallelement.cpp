#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void prevsmallerelement(int arr[], int& index, int& size){
    stack<int>sp;
    vector<int>ans;
    sp.push(-1);
    while(index< size){
        if(!sp.empty() && (sp.top()< arr[index])){
            ans.push_back(sp.top());
            sp.push(arr[index]);
            index++;
        }
        else {
            sp.pop();
        }
    }
}
int main(){
    int arr[]= {8,4,6,1,2,3};
    int size= 6;
    int index= 0;
}