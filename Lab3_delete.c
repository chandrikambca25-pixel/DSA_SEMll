#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head = NULL;

void insert_at_begining(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void delete_given_data(int data) {
    struct node* temp = head;
    struct node* prev = NULL;

    // If head node has the data to be deleted
    if (temp != NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        printf("Node with data %d deleted\n", data);
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // If node not found
    if (temp == NULL) {
        printf("Node with data %d not found\n", data);
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp);
    printf("Node with data %d deleted\n", data);
}

void traverse()
{
    struct node* curr;
    curr = head;
    while (curr != NULL)
    {
        printf("%d ->", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main()
{
    insert_at_begining(10);
    insert_at_begining(20);
    insert_at_begining(30);
    insert_at_begining(40);
    insert_at_begining(50);
    delete_given_data(30);
    traverse();
  return 0;
}
