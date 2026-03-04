#include<stdio.h>
#include<stdlib.h>

  struct node
  {
    int data;
    struct node*next; 
   };
   struct node*head=NULL;
   
   void insert_at_begining(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}
   void traverse()
   {
   struct node*curr;
   curr=head;
   while(curr!=NULL)
   {
     printf("%d ->",curr->data);
     curr=curr->next;
    }
    printf("NULL\n");
    }

    int main()
    {
      insert_at_begining(1);
      insert_at_begining(5);
      insert_at_begining(7);
      traverse();
      
    }