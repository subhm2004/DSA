// check whether a given array of characters is pallindrome or not
#include<iostream>
#include<string.h>
using namespace std;
bool checkpallindrome(char ch[], int size){
    int i=0;
    int j= strlen(ch) -1;
    while(i<=j){
        if(ch[i]== ch[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    return true;
}
int main(){
    char ch[50];
    int size= 50;
    cout<< "enter character array"<< endl;
    cin.getline(ch,50);
    bool ans= checkpallindrome(ch,size);
    cout<< ans<< endl;


}