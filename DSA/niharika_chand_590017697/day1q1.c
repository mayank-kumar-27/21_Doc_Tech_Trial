#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *add;
};
struct node *start=NULL, *temp, *new1, *prev, *next;

void display()
{
    if(start == NULL)
    {
        printf("List not found\n");
    }
    else
    {
        temp=start;
        while(temp != NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->add;
        }
        printf("\n");
    }
}

void insertF()
{
    int x;
    if(start == NULL)
    {
        printf("list not found\n");
    }
    else
    {
        printf("Enter element to be inserted at first:\n");
        scanf("%d",&x);
        new1=(struct node*)(malloc(sizeof(struct node)));
        new1->data=x;
        new1->add=NULL;
        new1->add=start;
        start=new1;
    }
}

void insertL()
{
    int y;
    if(start == NULL)
    {
        printf("list not found\n");
    }
    else
    {
        printf("Enter element to be inserted at last: \n");
        scanf("%d",&y);
        new1=(struct node*)(malloc(sizeof(struct node)));
        new1->data=y;
        new1->add=NULL;
        temp=start;
        while(temp->add != NULL)
        {
            temp=temp->add;
        }
        temp->add=new1;
    }
}

void insertM()
{
    int z,p;
    if(start == NULL)
    {
        printf("List not found\n");
    }
    else
    {
        printf("Enter element to be inserted: \n");
        scanf("%d",&z);
        printf("Enter element to be inserted after:\n");
        scanf("%d",&p);
        new1=(struct node*)(malloc(sizeof(struct node)));
        new1->data=z;
        new1->add=NULL;
        temp=start;
        while(temp != NULL)
        {
            if(temp->data == p)
            {
                new1->add=temp->add;
                temp->add=new1;
            }
            temp=temp->add;
        }
    }
}

void deleteF()
{
    if(start == NULL)
    {
        printf("List not found\n");
    }
    else
    {
        temp=start;
        start=start->add;
        printf("Deleted element = %d\n",temp->data);
        free(temp);
    }
}

void deleteL()
{
    if(start == NULL)
    {
       printf("List not found\n");
    }
    else
    {
        temp=start;
        while(temp->add != NULL)
        {
            prev=temp;
            temp=temp->add;
        }
        prev->add=NULL;
        printf("Deleted element = %d\n",temp->data);
        free(temp);
    }
}

void deleteM()
{
    if(start == NULL)
    {
        printf("List not found\n");
    }
    else
    {
        temp=start;
        int s;
        printf("Enter data to be deleted: ");
        scanf("%d",&s);
        while(temp->add != NULL)
        {
            if(s == temp->data)
            {
                prev->add=temp->add;
                free(temp);
                printf("%d has been deleted from the list\n",s);
                break;
            }
            else
            {
                prev=temp;
                temp=temp->add;
            }
        }
    }
}

void search()
{
    if(start == NULL)
    {
        printf("List not found\n");
    }
    else
    {
        int s,f=0,p,i=1;
        printf("Enter element to be searched: ");
        scanf("%d",&s);
        temp=start;
        while(temp!=NULL)
        {
            if(temp->data == s)
            {
                f=1;
                p=i;
                break;
            }
            temp=temp->add;
            i++;
        }
        if(f==1)
        {
            printf("%d found at %d position",s,p);
        }
        else
        {
            printf("%d not found",s);
        }
    }
}

void main()
{
    printf("LINKEDLIST\n");
    int n;
    printf("enter an element:\n");
    scanf("%d",&n);
    start=(struct node*)(malloc(sizeof(struct node)));
    start->data=n;
    start->add=NULL;
    temp=start;
    int choice;
    do
    {
        printf("\n Enter 1 for display \n Enter 2 for insertion at beginning\n Enter 3 for insertion at last\n Enter 4 for insertion after a specific element\n Enter 5 for deletion of first element\n Enter 6 for deletion of last element\n Enter 7 for deletion of a specific element \n Enter 8 for searching a specific element \n Enter 9 for exit \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: display();
                    break;
            case 2: insertF();
                    break;
            case 3: insertL();
                    break;
            case 4: insertM();
                    break;      
            case 5: deleteF();
                    break;  
            case 6: deleteL();
                    break;
            case 7: deleteM();
                    break;  
            case 8: search();
                    break; 
            case 9: printf("\nExiting....") ;    
                    break;
            default: printf("invalid choice\n");
        }
    } while (choice != 9);
    free(start);
}