// replace spaces in the string with another character
#include<iostream>
#include<string.h>
using namespace std;
void replace_space(char ch[100]) {
    cout<< "enter any string"<< endl;
    cin.getline(ch,100);
    int i=0;
    while(ch[i] != '\0') {
        if(ch[i] == ' ') {
            ch[i] = '@';
        }
        i++;
    }
}

int main() {
    char ch[100];
    cout<< ch;
    
}
