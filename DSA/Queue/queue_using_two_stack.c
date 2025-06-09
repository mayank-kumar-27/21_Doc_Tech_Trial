#include <stdio.h>  
#define N 10  

int s1[N], s2[N];    
int top1 = -1, top2 = -1;    
int count = 0;   

void push1(int data) 
{  
    if(top1 == N - 1) 
    {  
        printf("Stack 1 is full.\n");  
    } 
    else 
    {  
        top1++;  
        s1[top1] = data;  
    }  
}  

int pop1() 
{  
    if(top1 == -1) 
    {  
        printf("Stack 1 is empty.\n");  
        return -1;  
    } 
    else 
    {  
        int data = s1[top1];  
        top1--;  
        return data;  
    }  
}  

void push2(int data) 
{  
    if(top2 == N - 1) 
    {  
        printf("Stack 2 is full.\n");  
    } 
    else 
    {  
        top2++;  
        s2[top2] = data;  
    }  
}  

int pop2() 
{  
    if(top2 == -1) 
    {  
        printf("Stack 2 is empty.\n");  
        return -1;   
    } 
    else 
    {  
        int data = s2[top2];  
        top2--;  
        return data;  
    }  
}  

void enqueue(int data) 
{  
    push1(data);  
    count++;  
}  
int dequeue() 
{  
    if(top1 == -1 && top2 == -1) 
    {  
        printf("Queue is empty.\n");  
        return -1;  
    } 
    else 
    {  
        if(top2 == -1) 
        {  
            while(top1 != -1) 
            {  
                int a = pop1();  
                push2(a);  
            }  
        }  
        return pop2();  
    }  
}  

void display() 
{  
    if(count == 0) 
    {  
        printf("Queue is empty.\n");  
        return;  
    }  

    printf("Queue elements: ");  
    for(int i = top2; i >= 0; i--) 
    {  
        printf("%d ", s2[i]);  
    }  

    for(int i = 0; i <= top1; i++) 
    {  
        printf("%d ", s1[i]);  
    }  

    printf("\n");  
}  

int main() 
{  
    enqueue(10);  
    enqueue(20);  
    enqueue(30);  
    display();  

    printf("Dequeued: %d\n", dequeue());  
    display();  

    printf("Dequeued: %d\n", dequeue());  
    display();  

    enqueue(40);  
    enqueue(50);  
    display();  

    return 0;  
}  