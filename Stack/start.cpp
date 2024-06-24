#include<iostream>

using namespace std;

// Implementation with Array

class Stack{
    int *arr; // integer pointer
    int size; // size of stack
    int top;  // iterator which points to elements

    // Constructor

public:         // we are only making this part public to ensure proper data encapsulation and avoid the complex structures to be seen by others

        Stack(int s){
            size = s; 
            top = -1;
            arr = int arr[s];
        }

        // Stack full check operation

        int full(int value){
            return(value == size);
        }

        // Stack empty check operation

        int empty(int value){
            return(value == -1);
        }

        // Push operation

        void push(int value){
            if(full(top))
                cout<<"Stack overflow!";
            else{
                top++;
                arr[top] = value;
                cout<<"Pushed "<<value<<" in to the stack ";
            }
        }

        // Pop operation

        void pop(){
            if(empty(top))
                cout<<"Stack Underflow!";
            else{
                int a = arr[top];
                top--;
                cout<<"removed "<<a<<" from the stack";
            }
        } 
    
};