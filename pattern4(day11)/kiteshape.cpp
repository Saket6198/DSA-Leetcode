#include<iostream>
using namespace std;

int main()
{
    int i, j, n, k, m;
    cout<<"Enter the value of n : "<<" ";
    cin>>n;
    cout<<"\n";
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n - i; j++){
            cout<<" ";
        }
        for(j = 1; j <= i; j++){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    for(k = n; k>=1; k--){
        for(m = 1; m <= n - k; m++){
            cout<<" ";
        }
        for(m = 1; m <= k; m++){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}