#include <stdio.h>
#include <stdbool.h>

typedef struct Deque {
    int n;
    int front; 
    int rear;
    int* arr;
} Deque; 

int main(void) {
    Deque dq;
    int size;
    printf("Enter Deque Size : "); 
    scanf("%d", &size); 
    dq.n = size;
    dq.front = -1;
    dq.rear = -1; 
    dq.arr = (int *)calloc(dq.n, sizeof(int)); 
    while (true) {
        printf("Enter 1 to push to the front.\n");
        printf("Enter 2 to pop from the front.\n");
        printf("Enter 3 to push to the rear.\n"); 
        printf("Enter 4 to pop from the rear.\n"); 
    }
    return 0; 
}