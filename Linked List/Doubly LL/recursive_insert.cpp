#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

Node* createDLL(int arr[], int index, int size,  Node *back){
    if(size == index)
        return NULL;
    Node *temp = new Node(arr[index]);
    temp -> prev = back;
    temp -> next = createDLL(arr, index+1, size, temp);
    return temp;
}

int main(){
    int arr[] = {1,2, 3, 4};
    Node *head = createDLL(arr, 0, 4, NULL);
    Node *it = head;
    while(it){
        cout<<it->data<<"->";
        it = it -> next;
    }
}