// length of string
#include<iostream>
#include<string.h>
using namespace std;
int length(char arr[100]) {
    cout<< "enter the string"<< endl;
    cin.getline(arr,100);
    int i=0, count=0;
    while(arr[i]!='\0') {
         count++;
         i++;
    }
    return count;
}
void reverse(char arr[100]) {
    cout<< "enter the string"<< endl;
    cin.getline(arr,100);
    int i=0, j = strlen(arr) -1;
    while(i<=j) {
        int temp= arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}
void printarray(char arr[100]) {
    for(int i=0; i<strlen(arr); i++) {
        cout<< arr[i];
    }
}

bool pallindrome(char arr[100]) {
    cout<< "enter string"<< endl;
    cin.getline(arr,100);
    int i=0, j= strlen(arr) -1;
    bool same= false;
    while(i<=j) {
        if(arr[i] == arr[j]) {
            same = true;
        }
        else {
            same= false;
            break;
        }
        i++;
        j--;
    }
    return same;
}

int main() {
    char arr[100];
    string str;
   // int ans= length(arr);
    //cout<< "length of char array is "<< ans<< endl; 
   // reverse(arr);
   // printarray(arr);  
   //bool ans= pallindrome(arr);
  // cout<< ans<< endl; 
  /*cout<< "enter string"<< endl;
  getline(cin, str);
  cout<< str.substr(1,5)<< endl;
  str.push_back('A');
  cout<< str<< endl;
  str.pop_back();
  cout<< str<< endl;*/
   str = "this is my first message";
   string str2= "vanshika";
   str.replace(0,4,str2);
   cout<< str<< endl;
   str.erase(0,4);
   cout<< str<< endl;


}