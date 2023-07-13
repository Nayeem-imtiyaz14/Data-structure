#include <stdio.h>
#include <stdlib.h>
struct node{
     int data;
     struct node *next;
};
struct node *head=0,*tail;
void create();
void insert_after_node();
void deletion();
void view();
void count();
void duplicates();
void nodes();
void reverse();
void even();
void prime();
int main()
{
    int choice,n;
    while(1)
    {
        printf("Enter 1 for create\nEnter 2 for insert\nEnter 3 for deletion\nEnter 4 for view\nEnter 5 for count\nEnter 6 for insert_before_node\nEnter 7 for remove duplicates\nEnter 8 for delete all nodes\nEnter 9 for reverse\nEnter 10 for exit\nEnter 11 for checking even\nEnter 12 for prime");
        printf("\nEnter ur choice:");
        scanf("%d",&n);
        if(n==1)
        {
            create();
        }
        else if(n==2)
        {
            insert_after_node();
        }
        else if(n==3)
        {
            deletion();
        }
        else if(n==4)
        {
            view();
        }
        else if(n==5)
        {
            count();
        }
        else if(n==6)
        {
            insert_before_node();
        }
        else if(n==7){
            duplicates();
        }
        else if(n==8)
        {
            nodes();
        }
        else if(n==9)
        {
            reverse();
        }
        else if(n==10){
            exit(0);
    }
    else if(n==11){
        even();
    }
    else{
        prime();
    }
    }

}
void create()
{
    struct node *temp;
   struct node *tail;
  int i,n;
  printf("Enter the no of nodes:");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {

      temp=(struct node*)malloc(sizeof(struct node));
      printf("Enter the data:");
      scanf("%d",&temp->data);
      temp->next=0;
      if(head==0)
      {
          head=temp;
          tail=temp;
      }
      else
      {
          tail->next=temp;
          tail=temp;
      }
  }
}
void insert_after_node()
{
    struct node *trav,*temp;
    trav=head;
    if(trav==0)
    {
        printf("list is empty\n");
    }
    else{
     int n;
     printf("Enter the node after which u want to insert:");
     scanf("%d",&n);
      temp=(struct node*)malloc(sizeof(struct node));
     printf("Enter data to insert:");
     scanf("%d",&temp->data);
     while(trav->data!=n)
     {
         trav=trav->next;
     }
     if(trav==tail)
     {
         temp->next=0;
         trav->next=temp;
     }
     else{
     temp->next=trav->next;
     trav->next=temp;
}

}}
void deletion()
{
    int n;
    struct node *trav,*trav1;
    trav=head;
     if(head==0)
     {
         printf("list is empty\n");
     }
     else
        {
        printf("Enter the node u want to delete\n");
        scanf("%d",&n);
        while(trav->data!=n)
        {
            trav1=trav;
            trav=trav->next;
        }
        if(trav==head)
        {
            head=head->next;
            free(trav);
        }
        else if(trav==tail)
        {
            trav1->next=0;
            free(trav);
            tail=trav1;
        }
        else
        {
            trav1->next=trav->next;
            free(trav);
        }

     }
}
void view()
{
    struct node*trav;
     trav=head;
     if(trav==0)
     {
         printf("list is empty\n");
     }
     else{
    while(trav!=0)
    {

        printf("%d  ",trav->data);
        trav=trav->next;
    }
}}
void count()
{
    struct node *trav;
    int count=0;
    trav=head;
  if(head==0)
  {
      printf("list is empty\n");
  }
  else
  {
      while(trav!=0)
      {
        count++;
        trav=trav->next;
      }

  }
  printf("no of nodes are %d\n",count);


}
void insert_before_node()
{
    struct node *trav,*temp,*trav1;
    trav=head;
    if(trav==0)
    {
        printf("list is empty\n");
    }
    else{
     int n;
     printf("Enter the node before which u want to insert:");
     scanf("%d",&n);
      temp=(struct node*)malloc(sizeof(struct node));
     printf("Enter data to insert:");
     scanf("%d",&temp->data);
     while(trav->data!=n)
     {
         trav1=trav;
         trav=trav->next;
     }
     if(trav==head)
     {
         temp->next=head;
         head=temp;
     }
     else{
     temp->next=trav1->next;
     trav1->next=temp;

}
}
}
void duplicates()
{
    struct node *trav,*trav1;
    trav=head;
    trav1=head->next;
    if(head==0)
    {
        printf("list is empty\n");
    }
    else
    {
        while(trav1!=0){
        if(trav->data==trav1->data)
        {
            trav->next=trav1->next;
            free(trav1);
            trav1=trav->next;
        }
        else{
            trav1=trav1->next;
            trav=trav->next;
        }
        }


    }
}
void nodes()
{

    struct node *trav,*store;
    trav=head;
    while(trav!=0)
    {
        store=trav->next;
        free(trav);
        trav=store;
    }
}
void reverse()
{
    struct node *currentnode,*nextnode,*prevnode;

    if(head==0)
    {
        printf("List is empty\n");
    }
    else{

         prevnode=0;
    currentnode=nextnode=head;
        while(nextnode!=0)
        {
           nextnode=nextnode->next;
           currentnode->next=prevnode;
           prevnode=currentnode;
           currentnode=nextnode;
        }
           head=prevnode;
    }
}
void even()
{

    struct node*trav;
    trav=head;
    while(trav!=0)
    {
        if(trav->data%2==0)
            printf("%d  ",trav->data);
        trav=trav->next;
    }
}
 /*    void prime()
{
    int i;
    struct node* trav;
    trav = head;
    while (trav != 0)
    {
        for (i = 2; i < trav->data; i++)
        {
            if (trav->data % i == 0)
            {
                break;
            }
        }
        if (i == trav->data)
        {
            printf("%d ", trav->data);
        }
        trav = trav->next;
    }


}*/
void prime()
{
    struct node *trav;
    trav=head;
    while(trav!=0)
    {
        if(prime1(trav->data)==1)
        {
            printf("%d ",trav->data);}
            trav=trav->next;

    }
}
int prime1(int n)
{
    int i,flag=0;
    for(i=2;i<n;i++)
    {
        if(n%i==0)
        {
            flag=1;
            break;
        }

    }
    if(flag==1)
    {
        return(0);
    }
    else return(1);
}
