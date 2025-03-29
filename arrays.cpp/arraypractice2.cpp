// union with duplicates
#include<iostream>
#include<vector>
using namespace std;
int main() {
    int arr[] = { 1,2,3,4,5};
    int sizearr = 5;
    int brr[] = { 2,4,5,6,7};
    int sizebrr = 5;
    vector<int>ans;
    int flag = 1;
    for(int i=0; i<sizearr; i++) {
      for(int j=0; j<sizebrr; j++) {
        if(arr[i] == brr[j]) {
            flag=0;
            break;
        }
        else if(flag == 1) {
            ans.push_back(arr[i]);
            ans.push_back(brr[j]);
        }
    }
}
cout<< "elements of new array are "<< endl;
for(int i=0; i< ans.size(); i++) {
    cout<< ans[i]<< " ";
}

}
