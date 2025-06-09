#include <stdio.h>  
#include <stdlib.h>  

struct Queue 
{  
    int *items;  
    int front;  
    int rear;  
    int maxSize;  
};  

struct Queue* createQueue(int size) 
{  
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));  
    q->maxSize = size;  
    q->front = -1;  
    q->rear = -1;  
    q->items = (int*)malloc(size * sizeof(int));  
    return q;  
}  

void enqueue(struct Queue *q, int value) 
{  
    if (q->rear == q->maxSize - 1) 
    {  
        printf("Overflow: Queue is full.\n");  
        return;  
    }  
    if (q->front == -1) 
    {  
        q->front = 0;  
    }  
    q->rear++;  
    q->items[q->rear] = value;  
    printf("Enqueued: %d\n", value);  
}  

void dequeue(struct Queue *q) 
{  
    if (q->front == -1 || q->front > q->rear) 
    {  
        printf("Underflow: Queue is empty.\n");  
        return;  
    }  
    int item = q->items[q->front];  
    printf("Dequeued: %d\n", item);  
    q->front++;  
}  

void display(struct Queue *q) 
{  
    if (q->front == -1 || q->front > q->rear) 
    {  
        printf("Queue is empty.\n");  
        return;  
    }  
    printf("Queue elements: ");  
    for (int i = q->front; i <= q->rear; i++) 
    {  
        printf("%d ", q->items[i]);  
    }  
    printf("\n");  
}  

void freeQueue(struct Queue *q) 
{  
    free(q->items);  
    free(q);  
}  

int main() 
{  
    int size;  
    printf("Enter the maximum size of the queue: ");  
    scanf("%d", &size);  
    
    struct Queue *myQueue = createQueue(size);  
    
    for (int i = 0; i < size; i++) 
    {  
        int value;  
        printf("Enter value to enqueue: ");  
        scanf("%d", &value);  
        enqueue(myQueue, value);  
    }  
    
    display(myQueue);  
    
    char choice;  
    do {  
        printf("Do you want to dequeue an element? (y/n): ");  
        scanf(" %c", &choice);  
        if (choice == 'y') 
        {  
            dequeue(myQueue);  
            display(myQueue);  
        }  
    } while (choice == 'y');  

    freeQueue(myQueue);  
    return 0;  
}  