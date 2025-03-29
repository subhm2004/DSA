#include<iostream>
#include<stack>
using namespace std;
void findmid(stack<int> &sp,int temp,int position ){
    if(position==1) {
        cout<< temp<< endl;
        return;
    }
    sp.pop();
    findmid(sp,sp.top(), position-1);
    sp.push(temp);
}
int main(){
    stack<int>sp;
    sp.push(10);
    sp.push(20);
    sp.push(30);
    sp.push(40);
    sp.push(50);
    sp.push(60);
    int position;
    int temp= sp.top();
    if(sp.size()&1){ 
        position = sp.size() /2 +1;    
    }
    else{
        position= sp.size()/2 ;    
    }
    findmid(sp,temp,position);
    


}
