// you are given a string, remove k duplicates from the string
#include<iostream>
#include<string.h>
using namespace std;
string removekdup(string& str, int& k){
    string ans= "";
    int i=0;
    while(i!= str.length()){
        if(ans.length()-k+1 > 0){
            for(int j=k-1; j>0;){
                if(str[i]== ans[ans.length()-j]){
                    j--;
                }
                ans.erase(ans.length()- k+1, 2);
            }
        }
        else{
            ans.push_back(str[i]);
        }
    }
    return ans;
}
int main(){
    string str= "deeedbbcccbdaa";
    int k= 3;
    string f= removekdup(str,k);
    cout<< f<< endl;


}