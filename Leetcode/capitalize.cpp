#include<iostream>ss
using namespace std;

char capital(char x){
    char ans = x - 'a' + 'A'; // or x - 97 + 65;
    return ans;
}
int main(){
    char a;
    cin>>a;
    cout<<capital(a);
}