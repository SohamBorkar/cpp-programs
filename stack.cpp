// write code for stack implementation  


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100

typedef struct Stack
{
    int *data;
    int top;
} Stack;

Stack *createStack();

void push(Stack *stack, int value){
    stack->data[stack->top++] = value;
    return;
}

int pop(Stack *stack){
    return stack->data[--stack->top];
    return;
}

int peek(Stack *stack){
    return stack->data[stack->top - 1];
    return;
}

int isEmpty(Stack *stack){
    return stack->top == 0;
    return;
}

void printStack(Stack *stack){
    for(int i = 0; i < stack->top; i++){
        printf("%d\n", stack->data[i]);
    }
    return;
}

void freeStack(Stack *stack){
    free(stack);
    return;
}

int main(){
    Stack *stack = createStack();
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    push(stack, 6);
    push(stack, 7);
    push(stack, 8);
    push(stack, 9);
    push(stack, 10);
    push(stack, 11);
    push(stack, 12);
    push(stack, 13);
    push(stack, 14);
    push(stack, 15);
    push(stack, 16);
    push(stack, 17);
    push(stack, 18);
    push(stack, 19);
    push(stack, 20);
    push(stack, 21);
    push(stack, 22);

    // printf(isEmpty(stack));
    printStack(stack);
    pop(stack);
    printStack(stack);
}