// find the target element present in the string using recursion
#include<iostream>
using namespace std;

void findelement(string str, int size, int i, char target) {
    if(i>= size) {
        return;
    }
    if(str[i] == target) {
        cout<< "target found at index "<< i<< endl;
    }
    findelement(str, size, i+1, target);
}
int main() {
    string str = "vanshika";
    int size = str.length();
    int i=0;
    char target = 'a';
    findelement(str, size, i, target);
    return 0;
}