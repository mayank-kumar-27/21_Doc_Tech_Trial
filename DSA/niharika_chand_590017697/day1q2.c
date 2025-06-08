#include<stdio.h>
#define maxsize 10
int arr[maxsize],top=-1;

 void Push()
    {
      int n;
      if(top == maxsize-1)
      {
        printf("stack overflow");
      }
      else
      {
        printf("enter an element:");
        scanf("%d",&n);
        top++;
        arr[top]=n;
      }  
    }

    void Pop()
    {
        int n;
        if(top == -1)
        {
            printf("stack underflow\n");
        }
        else
        {
            n=arr[top];
            top--;
            printf("popped element is %d\n",n);

        }
    }

    void Peek()
    {
        int n;
        if(top == -1)
        {
            printf("stack empty");
        }
        else
        {
            n=arr[top];
            printf("Peek element is %d\n",n);
        } 
    }

    void Display()
    {
        int i;
        if(top == -1)
        {
            printf("stack empty");
        }
        else
        {
            printf("elements of the stack are:\n");
            for(i=top;i>=0;i--)
            {
                printf("%d\n",arr[i]);
            }
        }
    }

int main()
{
    int choice;
    printf("STACK\n");
    do
    {
     printf("enter 1 for push, 2 for pop, 3 for peek, 4 for display and 5 for exit\n");
     scanf("%d",&choice);
     switch(choice)
     {
        case 1: Push();
                break;
        case 2: Pop();
                break;
        case 3: Peek();
                break;
        case 4: Display();
                break;
        case 5: printf("\nExiting....") ;    
                    break;
        default: printf("Invalid choice\n");
     }
    }while(choice != 5);
    return 0;
}
