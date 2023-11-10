#include<iostream>
using namespace std;

int main()
{
    int i, n;
    char j, m='A';
    int c = 1;
    cout<<"Enter the value of n : "<<" ";
    cin>>n;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n-i; j++){
            cout<<"  ";
        }
        for(j = 0; j <= c/2; j++){
            cout<<m<<" ";
            m++;
        }
        m = m - 2;
        for(j = 0; j < c/2; j++){
            cout<<m<<" ";
            m--;
        }
        c = c + 2;
        m = 'A';
        cout<<"\n";
    }
}
