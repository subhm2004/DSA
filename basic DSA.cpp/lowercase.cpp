#include<iostream>
#include<string.h>
using namespace std;
void lowercase(char ch[00]){
    cout<< "enter any string"<< endl;
    cin.getline(ch,100);
    for(int i=0; i<strlen(ch); i++) {
        ch[i] = ch[i] - 'A' + 'a';
    }
 }
int main() {
    char ch[100];
    lowercase(ch);
    cout<< ch;
}
// CHARACTER ARRAY CONSISTS OF AN ARRAY IN WHICH EACH ELEMENT IS OF CHARAXTER TYPE WHEREAS STRING IS A DATA TYPE