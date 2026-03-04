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
   
  void insert_after_key(int key, int data)
{
    struct node* curr = head;

    // Step 1: Search for key
    while(curr != NULL && curr->data != key)
    {
        curr = curr->next;
    }

    // If key not found
    if(curr == NULL)
    {
        printf("Key not found\n");
        return;
    }

    // Step 2: Create new node
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;

    // Step 3: Adjust pointers
    newnode->next = curr->next;
    curr->next = newnode;
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
        insert_after_key(5, 10);
        traverse();
    }