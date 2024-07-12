#include<iostream>

using namespace std;

class Node{
public:

    int data;
    Node *prev, *next;

    Node(int value){
        data = value;
        next = prev = NULL;
    }
};

class Deque{
    Node *front, *rear;
public:
    Deque(){
        front = rear = NULL;
    }
    void push_front(int x){
        if(front == NULL){
            return;
        }else{
            if(head == NULL){
                head = new Node(x);
                front = head;
            }
        }
    }
};

int main(){
    Deque q;
    q.push_front(x)
}