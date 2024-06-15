#include<iostream>
using namespace std;

int main()
{
    int i, j, n, k, m;
    cout<<"Enter the value of n : "<<" ";
    cin>>n;
    for(i = 1; i <= n; i++){
        if(i == 4){
            continue;
        }
        else{
            for(j = 1; j <= i; j++){
                cout<<"* ";
            }        
            for(j = 1; j <= 2*n-2*i; j++){
                cout<<"  ";
            }
            for(j = 1; j <= i; j++){
                cout<<"* ";
            }
        cout<<"\n";
        }
    } 
    for(i = n-2; i >= 1; i--){
        for(j = 1; j <= i; j++){
            cout<<"* ";
        }
        for(j = 1; j <= 2*n-2*i; j++){
            cout<<"  ";
        }
        for(j = 1; j <= i; j++){
            cout<<"* ";
        }
        cout<<"\n";
    }
}