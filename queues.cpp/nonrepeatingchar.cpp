// print the first non repearting character in the string
#include<iostream>
#include<queue>
#include<string>
using namespace std;
int main(){
    string str= "fafcdcad";
    string ans="";
    int freq[26]= {0};
    queue<int>q;
    for(int i=0; i< str.length(); i++){
        char ch= str[i];
        freq[ch-'a']++;
        q.push(ch);
        // answer find karo
        while(!q.empty()){
            if(freq[q.front()- 'a'] ==1){
                ans.push_back(q.front());
                break;
            }
            else {
                q.pop();
            }
        }
        if(q.empty()){
            ans.push_back('#');
        }
    }
    for(int i=0; i< ans.length(); i++){
        cout<< ans[i]<< "->";
    }

}