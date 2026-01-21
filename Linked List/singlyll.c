#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next; 
}; 

void display(struct Node* head) {
    struct Node* travNode = head;
    printf("Linked List Elements : ");
    while (travNode != NULL) {
        printf("%d ", travNode -> data); 
        travNode = travNode -> next; 
    }
    printf("\n"); 
}

// Deletion, Searching, Reversal 

void delete(struct Node** head, int position) {
    struct Node* travNode = *head;
    if (*head == NULL) {
        printf("Linked List is empty.\n"); 
    }
    else if (position == 1) {
        struct Node* newhead = travNode -> next; 
        *head = newhead; 
        free(travNode);
    }
    else {
        int c = 1; 
        while (travNode -> next != NULL && c != position - 1) {
            travNode = travNode -> next;
            c += 1;
        }
        struct Node* delNode = travNode -> next; 
        travNode -> next = delNode -> next; 
        free(delNode);
    }
}

void insert(struct Node** head, int n, int position) {
    struct Node* newnode = (struct Node *)malloc(sizeof(struct Node)); 
    newnode -> data = n;
    if (*head == NULL) {
        newnode -> next = NULL; 
        *head = newnode; 
    }
    else if (position == 1) {
        newnode -> next = *head;
        *head = newnode; 
    }
    else {
        int c = 1;
        struct Node* travNode = *head;  
        while (travNode -> next != NULL && c != position - 1) {
            travNode = travNode -> next; 
            c += 1; 
        }
        newnode -> next = travNode -> next; 
        travNode -> next = newnode; 
    }
}

int main(void) {
    struct Node* head = NULL; 
    insert(&head, 1, 1);
    insert(&head, 2, 2);
    insert(&head, 3, 3);
    insert(&head, 4, 4);
    insert(&head, 5, 5); 
    insert(&head, 6, 2); 
    insert(&head, 7, 1); 
    delete(&head, 2); 
    display(head); 
    return 0; 
}