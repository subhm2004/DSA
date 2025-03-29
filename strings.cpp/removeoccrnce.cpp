#include<iostream>
#include<string>
using namespace std;
string removeoccur() {
    string str = "daabcbaabcbc";
    string part = "abc";
    int pos = str.find(part);
    while(pos != string::npos) {
        str.erase(pos, part.length());
        pos = str.find(part);
    }
    return str;
}
int main() {
   string ans= removeoccur();
   cout<< ans<< endl;

}