#include<iostream>

using namespace std;

class queue{
    int front, rear; //front points to first element for dequeue and rear points to new elements added behind for push
    int *arr;   // pointer pointing to an array of integers since we are implementing using an array 
    int size;   // size of the queue

    public:

    queue(int n){   // constructor to create a queue of defined size n
        arr = new int[n];   // creates a queue using array of size n
        front = rear = -1;   // initially
        size = n;   // to check for full
    }
    // If queue is empty
    bool isEmpty(){
        return front == -1;
    }
    // If queue is full
    bool isFull(){
        return rear == size - 1;
    }
    // adding elements into queue

    void push(int x){
        if(isFull()){
            cout<<"\nQueue is Full!\n";
            return;
        }else{
            if(isEmpty()){
                front = rear = 0;   // when it is the first element in the queue
                arr[0] = x;
                cout<<"\nPushed "<<x<<" into the start of queue\n";
            }else{
                arr[++rear] = x;
                cout<<"\nPushed "<<x<<" into queue\n";
            }
        }
    }

    // Removing elements from Queue
    void pop(){
        if(isEmpty()){
            cout<<"\nQueue is already Empty!\n";
        }else{
            if(front == rear){  // meaning only 1 element remain in the queue
                cout<<"\nRemoved the last element "<<arr[front]<<" from the queue\n";
                front = rear = -1;
                
            }else{
                cout<<"\nRemoved "<<arr[front]<<" from the queue\n";
                front++;
            }
        }
    }

    // points to the first element of the queue
    int start(){
        if(isEmpty()){
            cout<<"Queue is Empty!";
            return -1;
        }else{
            return arr[front];
        }
    }

    // Points to the last most added element in the queue
    int end(){
        if(isEmpty()){
            cout<<"\nqueue is Empty!\n";
            return -1;
        }else{
            return arr[rear];
        }
    }
};

int main(){
    queue q(5);
    q.push(1);
    q.push(2);
    // q.pop();
    // q.pop();
    // cout<<q.isEmpty();
    // q.pop();
    // q.push(1);
    // q.push(2);
    // q.push(3);
    // q.push(4);
    // q.push(5);
    // q.push(6);
    // cout<<q.isEmpty();
    // cout<<q.start()<<endl<<q.end();
    // cout<<q.isFull();
    // q.pop();
    // cout<<q.start();
    // q.pop();
    // cout<<q.start();
    // q.pop();
    // cout<<q.start();
    // q.pop();
    // cout<<q.start();
    // q.pop();
    // cout<<q.start();
    // cout<<endl<<q.start();
    // q.push(-1);
    cout<<q.start();
    q.pop();
    q.pop();
    int x = q.start();
    if(!q.isEmpty())
        cout<<x;
}