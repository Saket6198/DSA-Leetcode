#include<stdio.h>
#define SIZE 10
typedef struct queue{
    int arr[SIZE];
    int front,rear;
}queue;
void initialise(queue *q){
    q->front = -1;
    q->rear = -1;
}
int isEmpty(queue *q){
    return(q->front == -1 && q->rear == -1);
}
int isFull(queue *q){
    return(q->front == (q->rear+1) % SIZE);
}
void enqueue(queue *q, int x){
    if(isEmpty(q))
        q->front = 0;
    q->rear = (q->rear + 1) % SIZE;
    q->arr[q->rear] = x;
}
int dequeue(queue *q){
    int x;
    x = q->arr[q->front];
    if()
}
