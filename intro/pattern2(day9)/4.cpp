#include<iostream>
using namespace std;

int main()
{
    int i;
    char j, k = 'D';
    for(i = 0; i <= 4; i++){
        for(j = 'A';j <= k; j++){
            cout<<j<<" ";
        }
        k--;
        cout<<endl;
    }
}