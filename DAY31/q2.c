#include <stdbool.h>
#include <string.h>

bool isValid(char *s) {

    int n = strlen(s);
    char stack[n];      // dynamic size based on input
    int top = -1;

    for (int i = 0; i < n; i++) {

        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        } 
        else {
            if (top == -1)
                return false;

            char popped = stack[top--];

            if ((s[i] == ')' && popped != '(') ||
                (s[i] == '}' && popped != '{') ||
                (s[i] == ']' && popped != '[')) {
                return false;
            }
        }
    }

    return (top == -1);
}
