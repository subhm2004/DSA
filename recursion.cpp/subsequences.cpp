// you are given a string and you have to print subsequences of the string without changing the order
#include<iostream>
#include<vector>
using namespace std;
void subsequence(string str, string ans, int i ) {
    if(i== str.length()) {
        cout<< ans<< " ";
        return;
    }
    // exclude krne ka logic
     subsequence(str, ans, i+1);

    // include krne ka logic
    ans.push_back(str[i]);
    subsequence(str, ans, i+1);
    
}
void subsequence2(string str, string ans, int i){
    if(i>= str.length()){
        cout<< ans<< endl;
        return;
    }
    char ch= str[i];
    // include
    ans.push_back(ch);
    subsequence2(str,ans,i+1);
    // exclude
    // pehle ans me already stored char ko pop kro and then exclude ki call
    ans.pop_back();
    subsequence2(str,ans,i+1);
}

int main() {
    string str= "abc";
    string ans= "";
    int i=0;
    subsequence2(str,ans, i);

}