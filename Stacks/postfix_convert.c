#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int n;
    int top;
    int *arr; 
};


void push(struct Stack* st, int v);
void pop(struct Stack* st);
void display(struct Stack* st); 

int main(void) {
    struct Stack st;
    st.n = 100;
    st.top = -1; 
    st.arr = (int *)calloc(st.n, sizeof(int)); 
    
}

void push(struct Stack* st, int v) {
    if (st -> top == (st -> n) - 1) {
        printf("Stack is full.\n"); 
    }
    else {
        st -> top += 1;
        st -> arr[st -> top] = v;
        printf("Pushed %d to stack\n", v); 
    }
}

void pop(struct Stack* st) {
    if (st -> top == -1) {
        printf("Stack is empty.\n"); 
    }
    else {
        printf("Popped %d\n", (st -> arr[st -> top]));
        st -> top -= 1; 
    }
}

void display(struct Stack* st) {
    if (st -> top == -1) {
        printf("Stack is empty.\n");
    }
    else {
        printf("Stack Values : <top to bottom> \n"); 
        for (int i = st -> top; i >= 0; i--) {
            printf("%d ", st -> arr[i]);
        }
        printf("\n"); 
    }
}