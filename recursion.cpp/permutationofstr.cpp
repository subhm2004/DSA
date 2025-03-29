// you are given a string, find all permutations of the string
#include<iostream>
using namespace std;
void permutations(string &str, int index){
    if(index>= str.length()){
        cout<< str << endl;
        return;
    }
    for(int j=index; j<str.length();j++){
        swap(str[index],str[j]);
        permutations(str,index+1);
        swap(str[index],str[j]); // in the end original string return
        //krne k liye
    }
    //time complexity- n factorial
}
int main(){
    string str= "abcd";
    int index= 0;
    permutations(str,index);
} 