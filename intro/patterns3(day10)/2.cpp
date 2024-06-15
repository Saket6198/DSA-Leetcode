#include<iostream>
using namespace std;

int main()
{
    int i, n, j, space, l;
    char k = 'A';
    cout<<"Enter the value of n : "<<" ";
    cin>>n;
    cout<<"\n";
    for(i = 1; i <= n; i++){
        space = n - i;
        for(l = 1; l <= space; l++){
            cout<<" "<<" ";
        }
        for(j = 1; j <= i; j++){
            cout<<k<<" ";
        }
        cout<<endl;
        k++;
    }
}
