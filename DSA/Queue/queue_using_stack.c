#include <stdio.h>
#include <stdlib.h>

struct Stack 
{
    int top;
    int capacity;
    int* array;
};
struct Stack* createStack(int capacity) 
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}
int isEmpty(struct Stack* stack) 
{
    return stack->top == -1;
}
void push(struct Stack* stack, int value) 
{
    stack->array[++stack->top] = value;
}
int pop(struct Stack* stack) 
{
    if (isEmpty(stack)) 
    {
        printf("Queue is empty.\n");
        return -1;
    }
    return stack->array[stack->top--];
}
int dequeueHelper(struct Stack* stack) 
{
    if (isEmpty(stack)) 
    {
        printf("Queue is empty.\n");
        return -1;
    }

    int topElement = pop(stack);

    if (isEmpty(stack)) 
    {
        return topElement;
    }

    int front = dequeueHelper(stack);
    push(stack, topElement);
    
    return front;
}
void enqueue(struct Stack* stack, int value) 
{
    push(stack, value);
}
int dequeue(struct Stack* stack) 
{
    return dequeueHelper(stack);
}
void display(struct Stack* stack) 
{
    if (isEmpty(stack)) 
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i <= stack->top; i++) 
    {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}
int main() 
{
    struct Stack* stack = createStack(10);
    enqueue(stack, 10);
    enqueue(stack, 20);
    enqueue(stack, 30);
    printf("Queue after enqueues: ");
    display(stack);
    printf("Dequeued: %d\n", dequeue(stack));
    printf("Queue after dequeue: ");
    display(stack);
    return 0;
}
