#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void insert();
void delete();
void search();
struct node
{
    int data;
    int *rlink,*llink;
}*head;

void main()
{
    int s;
    while(1)
    {
        printf("Select from menu \n ");
        printf("1.Create \n2.Display \n3.Insert \n4.Delete \n5.Search \n6.exit \n");
        printf("Enter your choice \n");
        scanf("%d",&s);
        switch (s)
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
            break;        }
    }
}
 void create()
{
    int i,n;
    printf("Enter numbers of node : \n");
    scanf("%d",&n);
    printf("Enter value in node : \n");
    for (i = 0; i < n; i++)
    {
        struct node *temp,*next;
        temp=(struct node *)malloc(sizeof(struct node));
        next=(struct node *)malloc(sizeof(struct node));
        temp->rlink=NULL;
        temp->llink=NULL;
        scanf("%d",&temp->data);
        if(head==NULL)
        {
            head=temp;
        }
        else{
            next=head;
            while (next->rlink!=NULL)
            {
                next=next->rlink;
            }
            next->rlink=temp;
            temp->llink=next;
            
        }

    }
    
}
void display()
{
    struct node *next;
    next=head;
    while (next!=NULL)
    {
        printf("%d \n",next->data);
        next=next->rlink;
    }
    
}
void insert()
{
    int i,pos;
    printf("Enter your position \n");
    scanf("%d",&pos)
}
void delete()
{

}
void search()
{

}