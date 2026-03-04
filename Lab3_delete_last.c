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

void delete_last_node()
{
    // Corner case: List is empty
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    // Corner case: Only one node in the list
    if (head->next == NULL) {
        printf("Deleting the only node with data %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    // General case: Multiple nodes in the list
    struct node* temp = head;
    struct node* prev = NULL;

    // Traverse to find the second last node
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    // Delete the last node
    printf("Deleting last node with data %d\n", temp->data);
    prev->next = NULL;
    free(temp);
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
    delete_last_node();
    traverse();

    printf("\n=== Test Case 2: Insert one node and delete it ===\n");
    insert_at_end(10);
    printf("Linked List: ");
    traverse();
    delete_last_node();
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
    delete_last_node();
    printf("After deletion: ");
    traverse();

    printf("\nDeleting last node:\n");
    delete_last_node();
    printf("After deletion: ");
    traverse();

    printf("\n=== Test Case 4: Delete until empty ===\n");
    while (head != NULL) {
        delete_last_node();
        printf("After deletion: ");
        traverse();
    }

    return 0;
}
