#include<iostream>
#include<vector>

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

Node* CreateLL(int arr[], int index, int size){
    if(index == size){
        return NULL;    // to indicate the end of the LL since last node has next -> NULL
    }
    Node *temp = new Node(arr[index]); // if not then it creates new nodes with the array elements
    temp -> next = CreateLL(arr, index + 1, size); //  and then we recursively return the address of the next node created using this recursive function, thus returning the address of the next node created to the temp -> next
    

    return temp;
}

int main(){
    Node *Head = NULL;

    int arr[] = {2, 4, 6, 8, 10};
    Head = CreateLL(arr, 0, 5 );

    Node *temp = Head;

    while(temp){
        cout<<temp->data<<"->";
        temp = temp -> next;
    }
}