#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void insert();
void delete();
void search();
int num;
struct node{
    int data;
    struct node * link;
}*head;

void main()
{
    int ch;
    while(1)
    {
    printf("Select your choise :\n");
    printf("MENU \n 1.Create \n 2.Dispaly \n 3.Insert \n 4.Delete \n 5.Search \n 6.Exit \n");
    printf("Enter Your Choise :\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:create();
        break;
        case 2:display();
        break;
        case 3:insert();
        break;
        case 4:delete();
        break;
        case 5:search();
        break;
        case 6:exit(0);
        break;
    }
    }
}

void create()
{
    int i,n;
    struct node *temp,*next;
    printf("Enter number of nodes :\n");
    scanf("%d",&n);
    printf("Enter number element in node :\n");
    for(i=0;i<n;i++)
    {
       temp=(struct node *)malloc(sizeof(struct node));
       next=(struct node *)malloc(sizeof(struct node));
       temp->link=NULL;
       scanf("%d",&temp->data);
       if(head==NULL)
       {
           head=temp;
       }
       else
       {
           next=head;
           while(next->link!=NULL)
           {
               next=next->link;
           }
           next->link=temp;
       }
    }
}

void display()
{
    struct node *temp,*next;
    next=head;
    while(next!=NULL)
    {
        printf("%d\t",next->data);
        next=next->link;
    }
    printf("\n");
}

void insert()
{
    int i,pos;
    struct node *temp,*next;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter Data in that position \n");
    scanf("%d",&temp->data);
    printf("Enter Position You want to Insert \n");
    scanf("%d",&pos);
    temp->link=NULL;

    if(pos==0)
    {
        temp->link=head;
        temp=head;
    }
    else
    {
        next=head;
        for(i=1;i<pos-1;i++)
        {
            next=next->link;
        }
        temp->link=next->link;
            next->link=temp;
    }
}

void delete()
{
    int i,pos;
    struct node *temp,*next,*prev;
    printf("Enter the position to be Delete :\n");
    scanf("%d",&pos);
    if(pos==1)
    {
        temp=head;
        head=head->link;
        temp->link=NULL;
        free(temp);
    }
    else
    {
        next=head;
        for(i=1;i<pos;i++)
        {
            prev=next;
            temp=next->link;
            next=next->link;
        }
        prev->link=temp->link;
        temp->link=NULL;
        free(temp);
    }
}

void search()
{
    int i,n;
    struct node *temp,*next;
    printf("Enter element to be search \n");
    scanf("%d",&n);
    next=head;
    while(next!=NULL)
    {
        if(next->data==n)
        {
            printf("Element Found!! \n");
        }
        next=next->link;

    }
    printf("\n");
}