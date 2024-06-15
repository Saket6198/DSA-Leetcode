#include<iostream>
using namespace std;

int main()
{
    int i, n, space, l;
    char j;
    char k = 'E';
    cout<<"Enter the value of n : "<<" ";
    cin>>n;
    cout<<"\n";
    for(i = 1; i <= n; i++){
        space = n - i;
        for(l = 1; l <= space; l++){
            cout<<" "<<" ";
        }
        for(j = 'E'; j >= k; j--){
            cout<<j<<" ";
        }
        cout<<endl;
        k = k - 1;
    }
}
