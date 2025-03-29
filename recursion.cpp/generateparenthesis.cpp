// generate valid parenthesis from the opening and closing braces provided
#include<iostream>
#include<vector>
using namespace std;
void generateparenthesis(string output, int& n, int open, int close, vector<string>& ans){
    if(open==0 && close==0){
        ans.push_back(output);
        for(int i=0; i<ans.size(); i++){
            cout<< ans[i]<< endl;
        }
        return;
    }
    if(open> 0){
        output.push_back('(');
        generateparenthesis(output,n,open-1, close, ans);
        // backtracking
        output.pop_back();    
    }
    if(close> open){
        output.push_back(')');
        generateparenthesis(output,n,open, close-1, ans);
        output.pop_back();    
    }
}
    
int main(){
    int n=3;
    int open=-n;
    int close= n;
    string output= "";
    vector<string>ans;
    generateparenthesis(output,n,open,close,ans);
    for(int i=0; i<ans.size(); i++){
        cout<< ans[i]<< endl;
    }


    
    
}