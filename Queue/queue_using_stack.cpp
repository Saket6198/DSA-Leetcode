#include<iostream>
#include<stack>

using namespace std;

class queue{
    stack<int>st1;
    stack<int>st2;

    public:

    bool isEmpty(){
        return st1.empty() && st2.empty();
    }

    void push(int x){
        cout<<"Pushed "<<x<<" into the stack\n";
        st1.push(x);
    }
    
    int pop(){
        if(st1.empty() && st2.empty())
            return 0;
        if(!st2.empty()){
            int a = st2.top();
            st2.pop();
            return a;
        }else if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            int a = st2.top();
            st2.pop();
            return a;
        }
    }

    int peek(){
        if(st1.empty() && st2.empty()){
            return 0;
        }
        if(!st2.empty()){
            return st2.top();
        }else if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            return st2.top();
        }
    }
};