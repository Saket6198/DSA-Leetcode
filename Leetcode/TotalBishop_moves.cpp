#include<iostream>
#include<cmath>
using namespace std;

class Solution{
public:
    int BishopMoves(int A, int B){
        int count = 0;
        count += min(abs(A-8), abs(B-1));
        count += min(abs(A-8), abs(B-8));
        count += min(abs(A-1), abs(B-8));
        count += min(abs(A-1), abs(B-1));
    return count;           

    }
};

int main(){
    Solution solution;
    int a, b;
    cout<<"enter the position of the bishop : ";
    cin>>a>>b;
    cout<<solution.BishopMoves(a, b);
}