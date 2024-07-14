#include<iostream>

using namespace std;
// implementing using circular array concept
class Deque{
    int front, rear, size;
    int *arr;   // pointing to an array
public:
    Deque(int n){      // since we are implementing using array, and they have fixed size
        front = rear = -1;
        size = n;   
        arr = new int[n];
    }

    bool isEmpty(){
        return front == -1; 
    }

    bool isFull(){
        return (rear + 1) % size == front;
    }

    void push_front(int x){
        if(isEmpty()){
            front = rear = 0;
            arr[0] = x;
            cout<<"Pushed "<<arr[front]<<" into the start/front\n";
            return;
        }else{
            if(isFull()){
                cout<<"Deque Overflow!\n";
                return;
            }
            front = (front - 1 + size) % size;  // since we are also doing operations on the front, so to act as an circular array
            // - whenever we push at front we will move the front backwards in a circular fashion (0-1 + 5) % 5 = 4 % 5 = 4 
            arr[front] = x;
            cout<<"pushed "<<arr[front]<<" into the front\n";
            return;
        }
    }

    void push_back(int x){
        if(isEmpty()){
            front = rear = 0;
            arr[rear] = x;
            cout<<"Pushed "<<arr[rear]<<" into the rear/start\n";
            return;
        }else{
            if(isFull()){
                cout<<"Deque overflow!\n";
                return;
            }
            rear = (rear + 1) % size;
            arr[rear] = x;
            cout<<"Pushed "<<arr[rear]<<" into the rear\n";
            return;
        }
    }

    void pop_front(){
        if(isEmpty()){
            cout<<"Deque Underflow!\n";
            return;
        }else{
            if(front == rear){
                int a = arr[front];
                front = rear = -1;
                cout<<"popped "<<a<<" from the front/last\n";
                return;
            }
            int a = arr[front];
            front = (front + 1) % size;
            cout<<"popped "<<a<<" from the front\n";
            return;
        }
    }

    void pop_back(){
        if(isEmpty()){
            cout<<"Deque Underflow!\n";
            return;
        }else{
            if(front == rear){
                int a = arr[front];
                front = rear = -1;
                cout<<"Popped "<<a<<" from the rear/last\n";
                return;
            }
            int a = arr[rear];
            rear = (rear - 1 + size) % size;
            cout<<"popped "<<a<<" from the rear\n";
            return;
        }
    }

    int start(){
        return front == -1 ? -1 : arr[front];
    }

    int end(){
        return front == -1 ? -1 : arr[rear];
    }
};
int main(){
    Deque d(5) ;
    d.push_front(5);
    d.push_back(8);
    cout<<d.end()<<endl;
    d.pop_front();
    d.pop_back();
    d.pop_back();
    d.push_back(6);
    d.push_back(7);
    cout<<d.start()<<endl;
}