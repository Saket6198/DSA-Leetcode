#include<iostream>
using namespace std;

int main(){
    int a, b, c;
    cout<<"Enter the numbers:  "<<" ";
    cin>>a>>b>>c;
    if(a > b || a > c){
        cout<<"yes!";
    }
    else{
        cout<<"no!";
    }
}