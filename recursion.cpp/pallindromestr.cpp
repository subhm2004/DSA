#include<iostream>
using namespace std;

bool checkpallindrome(string& str, int i, int j) {
    if(i>j) {
        return true;
    }
    if(str[i]== str[j]) {
        checkpallindrome(str, i+1, j-1);
    }
    else {
        return false;
    }
}

int main() {
    string str = "aman";
    int i=0, j= str.length() -1;
    bool ans = checkpallindrome(str, i, j);
    cout<< ans<< endl;

}
