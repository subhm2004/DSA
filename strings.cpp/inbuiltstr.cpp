// inbuilt string functions
// erase, insert
#include<iostream>
#include<string.h>
using namespace std;
int main(){
    
    string str = "this is a car";
    //erasing a portion of string
    str.erase(4,3);
    cout<< "after erasing: "<< str<< endl;
    // inserting an element in string
    string str2= "beautiful";
    str.insert(9,str2);
    cout<< "after inserting: "<< str << endl;
    // inserting and deleting at end
    string str1= "vanshika";
    str1.push_back('V');
    cout<< str1<< endl;
    str1.pop_back();
    cout<< str1<< endl;
    // find a string in another string
    string str3 = "hello everyone myself vanshika";
    string str4 = "myself";
    if(str3.find(str4)== string::npos){
        cout<< "string not found"<< endl;
    }
    else {
        cout<< "string found"<< endl;
    }
    // compare two strings
    string str5= "vanshika";
    string str6= "vanshika";
    if(str5.compare(str6)== 0){
        cout<< "strings are equal"<< endl;
    }
    else{
        cout<< "strings are not equal"<< endl;
    }
    // print substring of a string
    cout<< str3.substr(6,8)<< endl;




}