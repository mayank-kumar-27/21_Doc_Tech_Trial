#include <stdio.h>
#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, int val) {
    if (s->top != MAX-1)
        s->arr[++(s->top)] = val;
}

int pop(Stack *s) {
    if (s->top == -1) return -1;
    return s->arr[(s->top)--];
}

typedef struct {
    Stack s1, s2;
} Queue;

void initQueue(Queue *q) {
    initStack(&q->s1);
    initStack(&q->s2);
}

void enqueue(Queue *q, int val) {
    push(&q->s1, val);
}

int dequeue(Queue *q) {
    if (q->s2.top == -1) {
        while (q->s1.top != -1)
            push(&q->s2, pop(&q->s1));
    }
    return pop(&q->s2);
}

void display(Queue *q) {
    for (int i = 0; i <= q->s1.top; i++)
        printf("%d ", q->s1.arr[i]);
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("Queue: ");
    display(&q);
    printf("Dequeued: %d\n", dequeue(&q));
    printf("After dequeue: ");
    display(&q);
    return 0;
}
