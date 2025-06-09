#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct Queue 
{
    struct Node *front, *rear;
};

struct Queue* createQueue() 
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, int value) 
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    
    if (q->rear == NULL) 
    {
        q->front = q->rear = temp;
        return;
    }
    
    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(struct Queue* q) 
{
    if (q->front == NULL) 
    {
        printf("Queue is empty.\n");
        return -1;
    }
    struct Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    
    free(temp);
    return value;
}

int peek(struct Queue* q) 
{
    if (q->front == NULL) 
    {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->front->data;
}

int isEmpty(struct Queue* q) 
{
    return q->front == NULL;
}

void display(struct Queue* q) 
{
    if (q->front == NULL) 
    {
        printf("Queue is empty.\n");
        return;
    }
    
    struct Node* temp = q->front;
    while (temp != NULL) 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() 
{
    struct Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    
    printf("Queue: ");
    display(q);
    
    printf("Dequeued: %d\n", dequeue(q));
    printf("Queue after dequeue: ");
    display(q);
    
    printf("Front element: %d\n", peek(q));
    
    return 0;
}
