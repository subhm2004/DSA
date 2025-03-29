#include<iostream>
#include<string>
using namespace std;
int main(){
    string name;
    cout<< "enter name"<< endl;
    getline(cin,name);
    // length of string
    cout<< "length is: "<< name.length()<< endl;
    // string is empty or not
    cout<< "is string empty: "<< name.empty()<< endl;
    // at
    cout<< "size taken by string is: "<< sizeof(name)<< endl;
    cout<< "character at index 2: "<< name.at(2)<< endl;
    // first cahracter
    cout<< "front character is: "<< name.front()<< endl;
    // last character
    cout<< "back character is: "<< name.back()<< endl;
    // concatenating two strings
    string str1= "vanshika";
    string str2= "aggarwal";
    cout<< "before joining: string1: "<< str1<< " and str2: "<< str2<< endl;
    str1.append(str2);
    cout<< "after joining: "<< str1<< endl;
}