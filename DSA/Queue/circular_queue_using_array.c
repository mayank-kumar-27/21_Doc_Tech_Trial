#include <stdio.h>  
#include <stdlib.h>  
#define MAX 5  

int Queue[MAX];  
int f = -1, r = -1;  

void dequeue() 
{  
    if (f == -1) 
    {   
        printf("Underflow.\n");  
        return;  
    }  

    int item = Queue[f];  
    printf("Dequeued: %d\n", item);  

    if (f == r) 
    { 
        f = r = -1; 
    } else 
    {  
        f = (f + 1) % MAX;
    }  
}  

void enqueue(int d) 
{  
    if ((r + 1) % MAX == f) 
    {  
        printf("Overflow.\n");  
        return; 
    }  

    if (f == -1) 
    { 
        f = r = 0;  
    } else 
    {  
        r = (r + 1) % MAX;  
    }  

    Queue[r] = d;  
    printf("Enqueued: %d\n", d);  
}  

void display() 
{  
    if (f == -1) 
    {  
        printf("Queue is empty.\n");  
        return;  
    }  
    printf("Queue elements: ");  
    for (int i = f; i != r; i = (i + 1) % MAX) 
    {  
        printf("%d ", Queue[i]);  
    }  
    printf("%d\n", Queue[r]); 
}  

int main() 
{  
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