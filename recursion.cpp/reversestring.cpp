// reverse string using recursion
#include<iostream>
using namespace std;

void printstr(string str) {
    cout<< "string is: "<< " ";
    for(int i=0; i< str.length(); i++) {
        cout<< str[i];
    }
    cout<< endl;
}
void reversestring(string& str, int i, int j) {
    printstr(str);
    if(i>j) {
        cout<< str << endl;
        return;
    }    
    swap(str[i], str[j]);
    reversestring(str, i+1, j-1);
}

int main() {
    string str = "vanshika";
    int i=0, j= str.length()-1;
    reversestring(str,i,j);
}
