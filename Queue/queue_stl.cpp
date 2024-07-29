#include<iostream>
#include<queue>

using namespace std;


int main(){
    queue<int>q;
    q.push(5);
    q.push(10);
    q.pop();
    q.push(8);

    cout<<q.front()<<endl;
    int b = q.back();
    cout<<b;
    cout<<q.size();
}