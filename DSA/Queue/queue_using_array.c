#include <stdio.h>  
#include <stdlib.h>  
#define MAX 5  

int Queue[MAX];  
int front = -1, rear = -1;  

void enqueue(int value) 
{  
    if (rear == MAX - 1) 
    {  
        printf("Overflow: Queue is full.\n");  
        return;  
    }  
    if (front == -1) 
    {  
        front = 0;  
    }  
    rear++;  
    Queue[rear] = value;  
    printf("Enqueued: %d\n", value);  
}  

void dequeue() 
{  
    if (front == -1 || front > rear) 
    {  
        printf("Underflow: Queue is empty.\n");  
        return;  
    }  
    int item = Queue[front];  
    printf("Dequeued: %d\n", item);  
    front++;  
}  

void display() 
{  
    if (front == -1 || front > rear) 
    {  
        printf("Queue is empty.\n");  
        return;  
    }  
    printf("Queue elements: ");  
    for (int i = front; i <= rear; i++) 
    {  
        printf("%d ", Queue[i]);  
    }  
    printf("\n");  
}  

int main() {  
    enqueue(10);  
    enqueue(20);  
    enqueue(30);  
    display();  
    
    dequeue();  
    display();  
    
    enqueue(40);  
    enqueue(50);  
    enqueue(60);  
    display();  

    return 0;  
}  