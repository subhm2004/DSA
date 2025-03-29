#include<iostream>
#include<string.h>
using namespace std;
void reversestring(char ch[100]) {
    cout<< "enter any string" << endl;
    cin.getline(ch,100);
    int i=0, j=strlen(ch) -1;
    while(i<=j) {
        swap(ch[i], ch[j]);
        i++;
        j--;
    }
}
void printstr(char ch[100]) {
    for(int i=0; i<strlen(ch); i++) {
        cout<< ch[i];
    }
}
int main() {
    char ch[100];   
    reversestring( ch);
    printstr(ch);

}