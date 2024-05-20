#include<iostream>
using namespace std;

bool rectangle(int A, int B, int C, int D){
    return((A==C && B == D) || (A==B && C==D) || (A==D) && (B==C));
}
int main(){
    int a, b, c, d;
    cout<<"enter the 4 nos :";
    cin>>a>>b>>c>>d;
    cout<<rectangle(a,b,c,d);
}