#include<iostream>
#include<string.h>
using namespace std;
int findlength(char ch[], int& size){
    int i=0;
    while(ch[i]!='\0'){
        i++;
    }
    return i;
}
void reversestring(char ch[], int& size){
    int i=0, j= strlen(ch)-1;
    while(i<=j){
        swap(ch[i], ch[j]);
        i++;
        j--;
    }
    cout<< ch<< endl;
}
// character arrays are passed by reference in string
void uppercase(char ch[], int& size){
    int i=0;
    while(ch[i]!= '\0'){
        if(ch[i] >= 'a' && ch[i] <= 'z'){
            ch[i]= ch[i] - 'a'+ 'A';
        } 
        i++; 
    }
}
// replace string
void replacestring(char ch[], int& size){
    int i=0;
    while(ch[i]!= '\0'){
        if(ch[i] == '@'){
            ch[i] = 32;
            ch[i] = ' ';
        }
        i++;
    }
}
int main(){
    char ch[50];
    int size= 50;
    cout<< "enter character array"<< endl;
    cin.getline(ch,50);
    replacestring(ch,size);
    cout<< "output is "<<ch<< endl;
    

    // int ans= findlength(ch,size);
    // cout<< ans<< endl;
    // cout<< strrev(ch)<< endl;
    // reversestring(ch,size);
    // string temp= '\0';
    // cout<< temp.length() << endl;

    


}