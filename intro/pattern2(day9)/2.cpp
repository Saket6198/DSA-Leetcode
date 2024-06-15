#include<iostream>
using namespace std;

int main()
{
    int i;
    char j;
    char k = 'A';
    for(i = 1; i<=5; i++){
        for(j = 'A'; j <= k; j++){
           cout<<j<<" ";
        }
        cout<<"\n";
        k++;
    }
}