#include<iostream>
#include<deque>

using namespace std;

int main(){
    deque<int>q;
    // q.push_back(5);
    // q.push_front(10);
    // cout<<q.front();
    // q.pop_front();
    // cout<<q.front();
    q.assign(5, 10);
    cout<<q.front();
    cout<<q.back()<<endl;
    cout<<q.size();

}