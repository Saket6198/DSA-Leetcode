#include<iostream>
#include<deque>

using namespace std;

class Queue{
    deque<int>q;
public:

     void push(int x){
        if(q.empty()){
            return;
        }else{
            q.push_back(x);
        }
     }
};

int main(){
    
}