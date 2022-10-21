#include<stdio.h>
#include<stdlib.h>
#include<structuredquerycondition.h>
int display();
int push();
int pop();
int peek();
int init();

struct node{
    struct node *link;
    int data;
}*top;

void main()
{
    int ch;
    while(1)
    {
        printf("Chose from menu : ");
        printf("\n1.init\n2.push\n3.pop\n4.display\n5.peek\n6.Exit\n");
        printf("Enter your choise");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:init();
            break;
            case 2:push();
            break;
            case 3:pop();
            break;
            case 4:display();
            break;
            case 5:peek();
            break;
            case 6:exit(0);
            break;
        }
    }
}

int init()
{
    top = NULL;

}

int push()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->link = NULL;
    printf("Enter numuber to push : ");
    scanf("%d",temp->data);
    if(top==NULL)
    {
       top = temp;
    }
    else
    {
        top = temp;
        temp->link = top;
    }
    
}

int pop()
{
    struct node *temp,*next;
    temp = (struct node *)malloc(sizeof(struct node));
    next = (struct node *)malloc(sizeof(struct node));
    if(top==NULL)
    {
        printf("Stack is empty : ");
    }
    else{
        next = temp->link;
        temp = top;
        temp->link = NULL;
        printf("POp element is : %d",next->data);
        free(next);
    }
    


}

int display()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    top = temp;
    while(temp->link == NULL)
    {
        printf("Display : %d",temp->data);
        temp = temp->link;
    }
}

int peek()
{
    struct node *temp;
    printf("%d",temp->data);
    if(temp->link == NULL)
    {
        printf("Stack is empty : ");
    }
    else{
        printf("%d",top->data);
    }
}