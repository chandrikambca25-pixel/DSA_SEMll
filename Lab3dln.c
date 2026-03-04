#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head = NULL;

void insert_at_end(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void delete_at_end()
{
    // Case 1: If list is empty
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    // Case 2: If only one node exists
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    // Case 3: More than one node
    struct node* curr = head;

    // Traverse till second last node
    while (curr->next->next != NULL)
    {
        curr = curr->next;
    }

    // Delete last node
    free(curr->next);
    curr->next = NULL;
}

void traverse()
{
    // Corner case: List is empty
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node* curr = head;
    while (curr != NULL)
    {
        printf("%d ->", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main()
{
    printf("=== Test Case 1: Delete from empty list ===\n");
    delete_at_end();
    traverse();

    printf("\n=== Test Case 2: Insert one node and delete it ===\n");
    insert_at_end(10);
    printf("Linked List: ");
    traverse();
    delete_at_end();
    printf("After deleting last node: ");
    traverse();

    printf("\n=== Test Case 3: Multiple nodes ===\n");
    insert_at_end(20);
    insert_at_end(30);
    insert_at_end(40);
    insert_at_end(50);
    printf("Linked List: ");
    traverse();

    printf("\nDeleting last node:\n");
    delete_at_end();
    printf("After deletion: ");
    traverse();

    printf("\nDeleting last node:\n");
    delete_at_end();
    printf("After deletion: ");
    traverse();

    printf("\n=== Test Case 4: Delete until empty ===\n");
    while (head != NULL) {
        delete_at_end();
        printf("After deletion: ");
        traverse();
    }

    return 0;
}
