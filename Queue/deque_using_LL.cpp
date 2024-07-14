#include<iostream>

using namespace std;

class Node{
public:
// using Doubly Linked List
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

    void push_front(int x){      // pushing new elements at the front/start of the deque
        if(front == NULL){  // when dequeu is empty, both pointers will point to the same node
            front = rear = new Node(x);
            cout<<"pushed "<<x<<" at the start of the deque\n";
            return;
        }else{
            Node *temp = new Node(x);
            temp -> next = front;
            front -> prev = temp;
            front = temp;
            cout<<"pushed "<<x<<" at the front of the deque\n";
            return;
        }
    }

    void push_back(int x){      // pushing new elements at the rear/end of the deque 
        if(front == NULL){
            front = rear = new Node(x);
            cout<<"pushed "<<x<<" at the start/rear of the deque\n";
            return;
        }else{
            Node *temp = new Node(x);
            rear -> next = temp;
            temp -> prev = rear;
            rear = temp;
            cout<<"pushed "<<x<<" at the end of the deque\n";
            return;
        }
    }

    void pop_front(){   // removing elements from the start of the deque
        if(front == NULL){  // if already empty return
            cout<<"deque underflow!\n";
            return;
        }else{
            Node *temp = front; 
            front = front -> next;
            if(front){   // when next front exists meaning there are more elements in the deque
                cout<<"removed "<<temp->data<<" from the front of the deque\n";
                front -> prev = NULL;
            }else{   
                cout<<"removed "<<temp->data<<" from the front of the deque, deque is empty now!\n";
                rear = front = NULL;    // when there are no next element, meaning deque is empty hence making rear and front to NULL
            }
            delete temp;
            return;
        }
    }

    void pop_back(){        // removing elements from the end of the deque
        if(front == NULL){      // when deqeu is empty, we simply return
            cout<<"deque Underflow!\n";
            return;
        }else{
            Node *temp = rear;
            rear = rear -> prev;
            if(rear){    // if there are elements present behind rear, otherwise we reset front and rear to NULL
                cout<<"removed "<<temp->data<<" from the rear of the deque\n";
                rear -> next = NULL;
            }else{
                cout<<"removed "<<temp->data<<" from the rear of the deque, deque is empty now!\n";
                front = rear = NULL;
            }
            delete temp;
        }
    }

    int start(){
        return front == NULL ? -1 : front-> data;
    }

    int end(){
        return front == NULL ? -1 : rear -> data;
    }

};

int main(){
    Deque d;
    d.push_back(5);
    d.push_front(8);
    cout<<d.end()<<endl;
    d.pop_back();
    d.pop_back();
    d.pop_back();
    d.push_back(6);
    d.push_back(7);
    cout<<d.start()<<endl;
}