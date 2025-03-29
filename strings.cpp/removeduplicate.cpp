// remove all duplicate elements from the string
#include<iostream>
#include<string>
using namespace std;
void duplicate() {
    string str = "abbaca";
    string ans = "";
    int i=0;
    while(i< str.length()) {
        if(ans.length() >0) {
            if(str[i] != ans[ans.length()-1]) {
               ans.push_back(str[i]);
            }
            else {
               ans.pop_back();
            }
        }
        else {
            ans.push_back(str[i]);
        }
        i++;
    }    
    cout<< ans;       
}
int main() {
    duplicate();
}