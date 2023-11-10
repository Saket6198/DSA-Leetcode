#include<iostream>
using namespace std;

int main()
{
    int i, j, n, space;
    cout<<"Enter the value of n : "<<" ";
    cin>>n;
    cout<<"\n";
    for(i = 1; i <= n; i++){
        space = n - i;
        for(j = 1; j <= space; j++){
            cout<<" "<<" ";
        }
        for(j = 1; j <= i; j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
