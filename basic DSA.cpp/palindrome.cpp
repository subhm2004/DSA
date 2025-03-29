#include<iostream>
#include<string.h>
using namespace std;
bool pallindrome(char ch[100]) {
    cout<< "enter any string"<< endl;
    cin.getline(ch,100);
    int i=0, j= strlen(ch)-1;
    bool same= false;
    while(i<=j) {
        if(ch[i] == ch[j]) {
            same= true;
        }
        else {
            same = false;
            break;
        }
        i++;
        j--;
    }
    return same;
}
int main() {
    char ch[100];
    bool ans = pallindrome(ch);
    cout<< ans<< endl;
}