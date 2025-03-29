#include<iostream>
#include<string.h>
using namespace std;
void uppercase(char ch[100]) {
    cout<< "enter any string"<< endl;
    cin.getline(ch,100);
    for(int i=0; i<strlen(ch); i++) {
        ch[i]= ch[i]-'a'+'A';
    }
}
int main() {
    char ch[100];
    uppercase(ch);
    cout<< ch;

}