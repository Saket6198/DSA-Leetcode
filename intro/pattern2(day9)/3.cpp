#include<iostream>
using namespace std;

int main()
{
    int i, j;
    int k=10;
    for(i=1; i<=6; i++){
        for(j=10; j <= k; j++){
            cout<<j<<" ";
        }
        k++;
        cout<<"\n";
    }
}