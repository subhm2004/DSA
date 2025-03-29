#include<iostream>
using namespace std;
int main() {
    int m,n;
    cout<< "enter row and column number"<< endl;
    cin>>m>> n;
    for(int i=0; i<m; i++) {
        if(i==0 || i==m-1) {
            for(int j=0; j<n; j++ ) {
                cout<< "* ";
            }
        }
        else { cout<< "* ";
            for(int j=1; j<=n-2; j++) {
                cout<< "  ";
            }
            cout<< "* ";
        }
        cout<< "\n";

    }
}
