// remove at most one character to make a string a pallindrome
#include<iostream>
#include<string>
using namespace std;
bool pallindrome() {
    string str = "abca";
    int i=0;
    int j= str.length() - 1;
    while(i<j) {
        if(str[i] == str[j]) {
            i++;
            j--;
        }
        else if(str[i] != str[j]){
            str.pop_back();   
        }
    }
    
}
int main() {
    bool ans = pallindrome();
    cout<< ans<< endl;
}

