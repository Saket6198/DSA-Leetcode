#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int value){
        data = value;
        next = NULL;
    }
};

class queue{
    Node *front, *rear;

    public: 

    queue(){
        front = rear = NULL;
    } 

    bool isEmpty(){
        return front == NULL;
    }

    void push(int x){
        if(isEmpty()){
            front = rear = new Node(x);
            
            cout<<"Inserted "<<rear->data<<" in the start of queue\n";
            return;
        }else{
            rear -> next = new Node(x);
            rear = rear -> next;
            cout<<"Inserted "<<rear -> data<<" in the queue\n";
        }
    }

    void pop(){
        if(isEmpty()){
            cout<<"Queue underflow!\n";
            return;
        }else{
            Node *temp = front;
            cout<<"popped "<<front->data<<" from queue\n";
            front = front -> next;
            delete temp;
        }
    }

    int start(){
        if(isEmpty()){
            cout<<"Queue Underflow!\n";
            return -1;
        }else{
            return front -> data;
        }
    }

    int end(){
        if(isEmpty()){
            cout<<"Queue UnderfloW!\n";
            return -1;
        }else{
            return rear -> data;
        }
    }

};

int main(){
    queue q;
    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);
    cout<<q.start()<<endl;
    cout<<q.end();
    q.pop();
    cout<<q.start();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.push(1);
    cout<<q.start()<<q.end();
}