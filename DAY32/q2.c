#include <stdlib.h>

typedef struct {
    int *stack;       // main stack
    int *minStack;    // stack to track minimums
    int top;
    int minTop;
    int capacity;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    
    obj->capacity = 30000;   // max constraints
    obj->stack = (int*)malloc(obj->capacity * sizeof(int));
    obj->minStack = (int*)malloc(obj->capacity * sizeof(int));
    
    obj->top = -1;
    obj->minTop = -1;
    
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    obj->stack[++obj->top] = val;
    
    // If minStack empty OR new value <= current min
    if (obj->minTop == -1 || val <= obj->minStack[obj->minTop]) {
        obj->minStack[++obj->minTop] = val;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->stack[obj->top] == obj->minStack[obj->minTop]) {
        obj->minTop--;
    }
    obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->minStack[obj->minTop];
}

void minStackFree(MinStack* obj) {
    free(obj->stack);
    free(obj->minStack);
    free(obj);
}
