#include<stdio.h>
#include<stdlib.h>

int n;

struct node{
    int data;
    struct node *link;

}*head=NULL;

void display();
void create();
void insert();
void delete();
void reverse();

void main()
{
    int i,ch;
    while(1)
    {
        printf("Select from menu : \n");
        printf("1.Create \n2.Display \n3.Insert \n4.Delete \n5.Reverse \n6.Exit \n");
        printf("Enter your choise : ");
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
            case 5:reverse();
            break;
            case 6:exit(0);
            break;
        }
    }
    
}

void create()
{
    int i;
    struct node *temp,*next;
    
    printf("Enter no. of nodes :");
    scanf("%d",&n);
    printf("Enter data in nodes : ");
    for(i=0;i<n;i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        next = (struct node *)malloc(sizeof(struct node));
        temp->link = NULL;
        scanf("%d",&temp->data);
        if(head == NULL)
        {
            head = temp;
        }
        else
        
        {
        next = head;
        while(next->link!=NULL)    
            {
            next = next->link;
            }
            next->link = temp;
        }
        
    }
}

void display()
{
    int i;
    struct node *next;
    next = head;
    printf("Display : ");
    while(next != NULL)
    {
        printf("%d",next->data);
        next = next->link;
    }
}

void insert()
{
    int i,pos;
    struct node *temp,*next;
    temp = (struct node *)malloc(sizeof(struct node));
    next = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data want to insert : ");
    scanf("%d",&temp->data);
    printf("Enter the position in list : \n");
    scanf("%d",&pos);

    temp->link = NULL;
   
        if(pos==1)
        {
            temp->link=head;
            temp = head;
        }
        else
        {
            next = head;
            for(i=1;i<pos-1;i++)
            {
                next = next->link;
            }
            temp->link = next->link;
            next->link = temp;
        }

}

void delete()
{
    int i,pos;
    struct node *temp,*next,*prev;
    temp = (struct node *)malloc(sizeof(struct node));
    next = (struct node *)malloc(sizeof(struct node));
    prev=(struct node *)malloc(sizeof(struct node));

    printf("Enter position want to delete : ");
    scanf("%d",&pos);
    temp->link=NULL;
    
    if(pos == 1)
    {
        temp = head;
        temp->link = head;
        temp->link = NULL;
        free(temp);
    }
    else
    temp = head;
    for(i=1;i<pos;i++)
    {
       prev = temp;
       temp=temp->link;
       next=temp->link;
    }
    prev->link = temp->link;
    temp->link =NULL;
    free(temp);
}

void reverse()
{
    struct node *p1,*p2,*p3;
    p1 = head;
    p2 = p1->link;
    p3 = p2->link;
    p1->link = NULL;
    p2->link = p1;
    while(p3!=NULL)
    {
        p1 = p2;
        p2 = p3;
        p3 = p3->link;
        p2->link = p1;
    }head = p2;

}