#include<iostream>
#include<vector>
using namespace std;
class minStack{
    vector<pair<int,int>>sp;
    void push(int data){
        if(sp.empty()){
            pair<int,int>p;
            p.first= data;
            p.second= data;
            sp.push_back(p);
        }
        else {
            pair<int,int>p;
            int prevmin= sp.back().second;
            p.second= min(prevmin, data);
            p.first= data;
            sp.push_back(p);
        }
    }
    void pop(){
        if(!sp.empty()){
            sp.pop_back();
        }
    }
    int topvalue(){
        if(!sp.empty()){
            return sp.back().first;
        }
    }
    int getmin(){
        if(!sp.empty()){
            return sp.back().second;
        }
    }
};
int main(){
   

}