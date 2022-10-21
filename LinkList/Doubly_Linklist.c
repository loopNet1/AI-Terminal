#include<stdio.h>
#include<stdlib.h>

void create();
void display();
void insert();
void delete();

struct node{
    int data;
    struct node *llink,*rlink;
}*head=NULL;

//8am - 4pm , 
//1pm - 9pm , 
//6am - 11pm ,

void main()
{
    while(1)
    {
        int ch;
        printf("\nChoose from menu : ");
        printf("\n1.Create\n2.Display\n3.Insert\n4.Delete\n5.Exit\n");
        printf("Enter Your choose : ");
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
            case 5:exit(0);
            break;
        }
    
    }
}

void create()
{
    int i,n;
    struct node *temp,*next;
    printf("Enter number of nodes : ");
    scanf("%d",&n);
    printf("Enter data in node : ");

    for(i=0;i<n;i++)
    {
        
        temp = (struct node *)malloc(sizeof(struct node));
        next = (struct node *)malloc(sizeof(struct node));

        temp->llink = NULL;
        temp->rlink = NULL;

        scanf("%d",&temp->data);

        if(head==NULL)
        {
            head = temp;
        }
        else{
            next = head;
            while(next->rlink!=NULL)
            {
                next = next->rlink;
            }
            next->rlink = temp;
            temp->llink = next;
        }
    }

}

void display()
{
    struct node *next;
    next = (struct node *)malloc(sizeof(struct node));
    next = head;
    while(next!=NULL)
    {
        printf("%d",next->data);

        next = next->rlink;
        
    }
}

void insert()
{
    int pos,i,n;
    struct node *temp,*next;
    temp = (struct node *)malloc(sizeof(struct node));
    next = (struct node *)malloc(sizeof(struct node));
    printf("Enter data to be insert at that position : ");
    scanf("%d",&n);
    printf("Enter podition of an node : ");
    scanf("%d",&pos);
    temp->data = n;
    temp->rlink = NULL;
    temp->llink = NULL;
        if(pos==1)
        {
            temp ->rlink = head;
            temp = head;
            
                 
        }
        else
        {
            next = head;
            for(i=1;i<pos-1;i++)
            {
                next = next->rlink;
            }
            temp->rlink = next->rlink;
            next->rlink = temp; 
        }
}

void delete()
{
    int i,pos;
    struct node *temp,*next,*prev;
     temp = (struct node *)malloc(sizeof(struct node));
    // next = (struct node *)malloc(sizeof(struct node));
    // prev = (struct node *)malloc(sizeof(struct node));
    
    
    printf("Enter position to be deleted : ");
    scanf("%d",&pos);
    
    if(pos==1)
    {
        temp = head;
        head = head->rlink;
        temp->rlink = NULL;
        free(temp);
    }
    else{
        next = head;
        for(i=1;i<pos;i++)
        {
            prev = next;
            temp=next->rlink;
            next=next->rlink;
        }
        prev->rlink = temp->rlink;
        temp->rlink = NULL;
        free(temp);
    }
}