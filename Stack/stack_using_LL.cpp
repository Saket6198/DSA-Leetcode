#include<iostream>

using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int value){
        data = value;
        next = NULL;
    }
};

class Stack{
    Node *top;
    int size;
public:
    Stack(){ // telling size beforehand is not necessary in stack since it is dynamic unlike just stack using array
        top = NULL;
        size = 0;
    }
    // push opr

    void push(int value){
        Node *temp = new Node(value);
        temp -> next = top; // top initially NULL
        top = temp; // here top acts as a head, so we are basically pushing all new nodes to the head 
        cout<<"\ninserted "<<temp -> data<<" into the stack";
        size++;
    }

    void pop(){
        if(!top){
            cout<<"\nstack underflow!";
            return;
        }
        Node *temp = top;
        cout<<"\npopped "<<temp -> data<<" from the stack";
        top = top -> next;
        delete temp;
        size--;
    }

    int peek(){
        if(!top){
            cout<<"\nstack underflow!";
            return -1;
        }else{
            return top -> data;
        }
    }
    bool IsEmpty(){
        if(!top)
            return 1;
        else return 0;
    }
    int IsSize(){
        return size;
    }
};

int main(){
    Stack S;
    S.push(6);
    S.push(16);
    S.push(62);
    S.push(86);
    S.pop();
    cout<<S.peek()<<endl;
    cout<<endl<<S.IsSize()<<endl;
    cout<<S.IsEmpty();
}