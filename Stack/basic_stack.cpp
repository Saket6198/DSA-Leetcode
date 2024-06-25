#include<iostream>

using namespace std;

// Implementation with Array

class Stack{
    int *arr; // integer pointer to array since we are implementing it using array 
    int size; // size of stack
    int top;  // iterator which points to elements

    // Constructor

public:         // we are only making this part public to ensure proper data encapsulation and avoid the complex structures to be seen by others
    bool flag;

        Stack(int s){
            size = s; 
            top = -1;
            arr = new int[s];   // creates a new array of size s and datatype int and returns its base address to the arr pointer
            flag = 1; // indicating it is initially an empty stack
        }

        // Stack full check operation

        int full(int value){
            return(value == size - 1);
        }

        // Stack empty check operation

        int empty(int value){
            return(value == -1);
        }

        // Push operation

        void push(int value){
            if(full(top))
                cout<<"\nStack overflow!\n";
            else{
                top++;
                arr[top] = value;
                cout<<"\nPushed "<<value<<" in to the stack \n";
                flag = 0;
            }
        }

        // Pop operation

        void pop(){
            if(empty(top))
                cout<<"\nStack Underflow!\n";
            else{
                int a = arr[top];
                top--;
                cout<<"\nremoved "<<a<<" from the stack\n";
                if(top == -1)
                    flag = 1;
            }
        }
        
        //Peek operation

        int peek(){
            if(empty(top)){
                cout<<"\nStack Underflow!\n";
                return -1;
            }
            else
                return arr[top];
        }

        bool isEmpty(){
            return (top == -1);
        }
};

int main(){
    Stack s(5); // creating object of class 
     // initializing using constructor

    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // s.push(5);
    // s.push(6); // throws stack overflow
    // s.pop();
    // s.pop();
    // s.pop();
    // s.pop();
    // s.pop();
    // s.pop(); // throws stack underflow
    // s.peek(); // throws stack underflow
    // s.push(9);
    // s.push(3);
    // s.push(1);
    // cout<<s.peek();
    // s.pop();
    // cout<<s.peek();
    // s.pop();
    // cout<<s.peek();
    // s.pop();
    // cout<<s.peek()<<endl;
    // cout<<s.isEmpty();
    // s.push(1);
    // cout<<s.peek()<<endl;
    // cout<<s.isEmpty();
    // s.pop();
    // cout<<s.peek();
    // s.push(-1);
    // cout<<s.peek();
    s.push(-1);
    s.pop();    
    int val = s.peek();
    if(s.flag == 0)
        cout<<val<<endl;
    
}