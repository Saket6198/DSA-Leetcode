#include<iostream>
using namespace std;

int main(){
    int i;
    cout<<"Enter the temperature of the pool : "<<" ";
    cin>>i;
    if(i > 70 && i < 90){
        cout<<"Yes!";
    }
    else{
        cout<<"No!";
    }
}