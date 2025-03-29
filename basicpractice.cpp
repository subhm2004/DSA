// MATHS FOR DSA
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int slowexponentiation(int &a, int b ){
    if(b==1){
        return a;
    }
    return a*slowexponentiation(a,b-1);
}
int fastexponentiation(int &a, int& b){
    if(b==0){
        return 1;
    }
    int ans= 1;
    while(b>0){
        if(b&1){
            ans= ans*a;
        }
        a= a*a;
        b= b>>1;
    }
    return ans;
}
int sieveeratosthenus(int &n){
    if(n==0){
        return 0;
    }
    vector<bool>prime(n+1,true); // sbko prime mark krdia initially
    prime[0]= prime[1]= false; 
    int ans=0;// ye prime nhi h
    int N= sqrt(n);
    for(int i=2; i<=N; i++){ // optimisation2
        if(prime[i]){
            ans++;
            // uske multiples ko non prime mark krdo
            // int j= i*2; optimisation 1
            int j= i*i;

            while(j<=n){
                prime[j]= false;
                j= j+i;
            }

        }
    }
    return ans;
}
// optimising sieve- jo bhi elements already false mark ho chuke h
//unko dobara visit na kro
int main(){
    // int a,b;
    // cout<< "enter base and power"<< endl;
    // cin>> a>> b;
    int n;
    cout<< "enter any number"<< endl;
    cin>>n;
    int ans= sieveeratosthenus(n);
    cout<< ans<< endl;  
}