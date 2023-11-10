#include<iostream>
using namespace std;

int main()
{
    int i, j, n;
    cout<<"Enter the value of n : "<<" ";
    cin>>n;
    cout<<"\n";
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n-i; j++){
            cout<<"  ";
        }
        for(j = 1; j <= (2*i)-1; j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
