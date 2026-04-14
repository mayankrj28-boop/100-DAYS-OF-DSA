//Given a string s which represents an expression, evaluate this expression and return its value. 
//The integer division should truncate toward zero.

#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int calculate(char* s) {

    int n = strlen(s);
    int *stack = (int*)malloc(n * sizeof(int));
    int top = -1;

    int num = 0;
    char sign = '+';

    for (int i = 0; i < n; i++) {

        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }

        if ((!isdigit(s[i]) && s[i] != ' ') || i == n - 1) {

            if (sign == '+')
                stack[++top] = num;

            else if (sign == '-')
                stack[++top] = -num;

            else if (sign == '*')
                stack[top] = stack[top] * num;

            else if (sign == '/')
                stack[top] = stack[top] / num;

            sign = s[i];
            num = 0;
        }
    }

    int result = 0;

    for (int i = 0; i <= top; i++)
        result += stack[i];

    free(stack);
    return result;
}
