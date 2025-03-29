// remove duplicates from a string 
#include<iostream>
#include<string.h>
using namespace std;
void removeduplicate(string& str){
    string str1= "";
    int i=0;
    while(i!= str.length()){
        if(str1.length()>0){
            if(str[i]!= str1[str1.length()-1]){
                str1.push_back(str[i]);
            }
            else{
                str1.pop_back();
            }
        }
        else{
            str1.push_back(str[i]);
        }
        i++;    
    }
    cout<< str1<< endl;
}
int main(){
    string str= "abbaca";
    removeduplicate(str);

}