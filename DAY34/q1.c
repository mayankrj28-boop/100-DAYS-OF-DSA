// Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;


void push(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main() {
    char exp[100];
    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    char *token = strtok(exp, " ");

    while (token != NULL) {

        // If operand
        if (isdigit(token[0])) {
            push(atoi(token));
        }
        
        else {
            int b = pop();
            int a = pop();
            int res;

            switch(token[0]) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
            }

            push(res);
        }

        token = strtok(NULL, " ");
    }

    printf("%d\n", pop());

    return 0;
}
