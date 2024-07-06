#include<iostream>

using namespace std;

class queue{
    int front, rear, size;
    int *arr;

    public:

    queue(int s){
        front = rear = -1;
        arr = new int[s];
        size = s;
    }

    bool isEmpty(){
        return front == -1;
    } 

    bool isFull(){
        return (rear + 1) % size == front;  // accomodates when lets say front is 0 and rear is at last 5, then (5 + 1) % 6 = 0 which satisfies our condition   
    }

    void push(int a){
        if(isFull()){
            cout<<"\nQueue is Full!\n";
            return;
        }else{
            if(isEmpty()){       
                front = rear = 0;
                arr[0] = a;
                cout<<"\nPushed "<<a<<" into the start of queue\n";

            }else{
                cout<<"\nPushed "<<a<<" into the queue\n";
                rear = (rear + 1) % size;
                arr[rear] = a;
            }
        }
    }

    void pop(){
        if(isEmpty()){
            cout<<"Queue is Empty!\n";
            return;
        }else{
            if(front == rear){
                cout<<"removed the last element "<<arr[front]<<" from the C Queue\n";
                front = rear = -1;
            }else{
                cout<<"Removed "<<arr[front]<<" from the C Queue\n";
                front = (front + 1) % size;
            }
        }
    }

    int start(){
        if(isEmpty()){
            cout<<"Queue is Empty!\n";
            return -1;
        }else
            return arr[front];
    }

    int end(){
        if(isEmpty()){
            cout<<"Queue is Empty!\n";
            return -1;
        }else
            return arr[rear];
    }
};

int main(){
    queue q(5);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(6);
    q.push(9);
    q.push(10);
    q.pop();
    q.push(10);
    q.push(11);
    q.pop();
    cout<<q.start()<<endl;
    cout<<q.end()<<endl;
    q.push(11);
    q.push(12);
    cout<<endl<<q.isEmpty();
    cout<<endl<<q.isFull();

}