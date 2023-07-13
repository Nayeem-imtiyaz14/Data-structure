#include <stdio.h>
#include <stdlib.h>
struct node{
 int data;
  struct node *next;
  struct node *prev;
};
void create();
void insertion_after();
void display();
void deletion();
void insertion_before();
void reverse();
struct node *head,*tail,*trav,*trav1;
int main()
{
    while(1){
    int choice;
    printf("\nEnter 1 for creation\nEnter 2 for insertion_after\nEnter 3 for display\nEnter 4 for delete\nEnter 5 for insertion_before\nEnter 6 for reverse");
    printf("\nEnter ur choice\n");
    scanf("%d",&choice);
    if(choice==1)
    {
        create();
    }
    else if(choice==2)
    {
        insertion_after();
   }
    else if(choice==3)
    {
        display();
    }
    else if(choice==4)
    {
        deletion();
    }
    else if(choice==5)
    {
        insertion_before();
    }
    else if(choice==6)
    {
       reverse();
    }
    else
    {
        exit(0);
    }
}}
void create()
{
    struct node *temp;
    int n,i;
    head=0,tail=0;
    printf("Enter no of nodes to insert::");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter data::");
        scanf("%d",&temp->data);
        temp->next=0;
        temp->prev=0;
        if(head==0)
        {
            head=tail=temp;

        }
        else
        {
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
    }
//    printf("%d\n",tail->next->data);

}
void display()
{
    printf("\nElements of linked list:");
    trav=head;
    while(trav!=0)
    {
        printf("%d\n",trav->data);
        trav=trav->next;
    }
}
void insertion_after()
{
    trav=head;
    struct node *temp;
    int n;
    printf("Enter the node after which u want to insert");
    scanf("%d",&n);
    while(trav->data!=n)
    {
        trav=trav->next;
    }
    if(trav==tail)
    {
         temp=(struct node*)malloc(sizeof(struct node));
         printf("Enter data to insert");
         scanf("%d",&temp->data);

         temp->next=0;
        trav->next=temp;
        temp->prev=trav;

        tail=temp;
    }
    else
    {
         temp=(struct node*)malloc(sizeof(struct node));
         printf("Enter data to insert");
         scanf("%d",&temp->data);

         temp->next=trav->next;
         trav->next=temp;
         temp->prev=trav;
          temp->next->prev=temp;
    }
}
void insertion_before()
{
     trav=head;
    struct node *temp;
    int n;
    printf("Enter the node before which u want to insert");
    scanf("%d",&n);
    while(trav->data!=n)
    {
        trav=trav->next;
    }
    if(trav==head)
    {
         temp=(struct node*)malloc(sizeof(struct node));
         printf("Enter data to insert");
         scanf("%d",&temp->data);
        temp->next=head;
        head->prev=temp;
        temp->prev=0;
        head=temp;
    }
    else
    {
         temp=(struct node*)malloc(sizeof(struct node));
         printf("Enter data to insert");
         scanf("%d",&temp->data);
         temp->next=trav;
        trav->prev->next=temp;
         temp->prev=trav->prev;
         trav->prev=temp;
    }
}
void deletion()
{
    int n;
    trav=head;
    printf("Enter node to delete");
    scanf("%d",&n);
    while(trav->data!=n)

    {
        trav=trav->next;
    }
    if(trav==head)
    {
        head=trav->next;
        head->prev=0;
        free(trav);
    }
    else if(trav==tail)
    {
        tail=trav->prev;
        tail->next=0;
        free(trav);
    }
    else
    {
        trav->prev->next=trav->next;
        trav->next->prev=trav->prev;
        free(trav);
    }
}
void reverse()
{
    struct node *currentnode,*nextnode;
    currentnode=nextnode=head;
    while(currentnode!=0)
    {
        nextnode=nextnode->next;
        currentnode->next=currentnode->prev;
        currentnode->prev=nextnode;
        currentnode=nextnode;
    }

    currentnode=head;
    head=tail;
    tail=currentnode;

}
