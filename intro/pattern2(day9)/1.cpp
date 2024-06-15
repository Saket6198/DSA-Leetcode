#include<iostream>
using namespace std;

int main()
{
    int i, j;
    for(i = 1; i<=7; i++){
        for(j = 1; j<=i; j++){
            if(i == 7)
                for(j = 1; j<=6; j++)
                cout<<j<<" ";
            else
                cout<<j<<" ";
        }
        cout<<"\n";
    }
}