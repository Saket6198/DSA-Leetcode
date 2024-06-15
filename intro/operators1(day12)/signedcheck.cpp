#include<iostream>
using namespace std;

int main(){
    int i;
    cout<<"Enter the number:"<<" ";
    cin>>i;
    if(i>0 && (i%2==0)){
        cout<<"Yes!";
    }
    else{
        cout<<"no!";
    }
}