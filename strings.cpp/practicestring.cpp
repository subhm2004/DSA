#include<iostream>
#include<string>
using namespace std;
void duplicate() {
    string str = "abbaca";
    string ans = "";
    for(int i=0; i< str.length(); i++) {
        if(ans.length() > 0 && str[i] == ans[ans.length()-1]) {
            ans.pop_back();
        }
        else {
            ans.push_back(str[i]);
        }
    }
    cout<< ans<< endl;
}
void removepart() {
    string str = "daabcbaabcbc";
    string target = "abc";
    int i=0;
    while(i < str.length()) {
        if(str.find(target)) {
            str.erase(i,3);
        }
    }
    cout<< str;
}

int main() {
    //duplicate();
    removepart();
}