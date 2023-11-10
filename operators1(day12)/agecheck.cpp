#include<iostream>
using namespace std;

int main(){
    int i;
    cout<<"Enter the age : "<<" ";
    cin>>i;
    if(i >= 13 && i <= 19){
        cout<<"Teenager!";
    }
    else{
        cout<<"Not a teenager!";
    }
}