#include<iostream>
using namespace std;
int main (){
    //for(int i =5; i>0; i--){
      //  cout << i << " ";
      //  --i;
        
   // }
   int a,b=1;
       a=10;
       cout<< "hi"<< endl;
       if(++a) {
        cout<< b << endl;
       }
       else {
        cout<< ++b << endl;
       }
       bool x= false;
       cout<< ~(x)<< endl ;

       cout<< (5<<1) << endl;
       cout<< (3<<2) << endl;

       
       for(int i=1; i<=14; i++) {
        cout<< (2<<i) << endl;
       }


    return 0;
}