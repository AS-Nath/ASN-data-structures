#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue {
    int n;
    int front;
    int rear;
    int* arr;
} Queue;

void push(Queue* q, int v);
void pop(Queue* q);
void display(Queue* q);

int main(void) {
    Queue q;
    q.n = 5;
    q.front = -1;
    q.rear = -1;
    q.arr = (int *)calloc(q.n, sizeof(int));

    while (true) {
        printf("Enter 1 to push : \n");
        printf("Enter 2 to pop : \n");
        printf("Enter 3 to display : \n");
        printf("Enter anything else to exit. \n");
        int c;
        scanf("%d", &c);
        switch (c) {
            case 1 :
                printf("Enter value to push : ");
                int v;
                scanf("%d", &v);
                push(&q, v);
                break;
            case 2 :
                pop(&q);
                break;
            case 3 :
                display(&q);
                break;
            default :
                printf("Exiting.\n");
                return 0;
        }
    }
}

void push(Queue* q, int v) {
    if (q -> rear == q -> front - 1) {
        printf("Queue is full.\n");
        return;
    }
    if (q -> front == -1 && q -> rear == -1) {
        q -> front = 0;
        q -> rear = 0;
        q -> arr[q -> rear] = v;
        printf("Pushed %d to queue.\n", v);
    }
    else if (q -> rear < q -> n - 1) {
        q -> rear += 1;
        q -> arr[q -> rear] = v;
        printf("Pushed %d to queue.\n", v);
    }
    else if (q -> rear == q -> n - 1 && q -> front > 0) {
        q -> rear = 0;
        q -> arr[q -> rear] = v;
    }
    else {
        printf("Queue is full.\n");
    }
}

void pop(Queue* q) {
    if (q -> front == -1 && q -> rear == -1) {
        printf("Queue is empty.\n");
    }
    else if (q -> front == q -> rear) {
        printf("Popped %d from queue.\n", q -> arr[q -> front]);
        q -> front = -1;
        q -> rear = -1;
    }
    else if (q -> front == q -> n-1 && q -> rear < q -> front) {
        printf("Popped %d from queue.\n", q -> arr[q -> front]);
        q -> front = 0;
    }
    else {
        printf("Popped %d from queue.\n", q -> arr[q -> front]);
        q -> front += 1;
    }
}

void display(Queue* q) {
    if (q -> front == -1 && q -> rear == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue Elements (front to rear) : ");
    if (q -> rear >= q -> front) {
        for (int i = q -> front; i <= q -> rear; i++) {
            printf("%d ", q -> arr[i]);
        }
    }
    else {
        for (int i = q -> front; i < q -> n; i++) {
            printf("%d ", q -> arr[i]);
        }
        for (int i = 0; i <= q -> rear; i++) {
            printf("%d ", q -> arr[i]);
        }
    }
    printf("\n");
}
