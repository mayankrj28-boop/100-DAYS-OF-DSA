#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    
    // Read the string
    scanf("%s", str);

    int len = strlen(str);

    // Print mirror (reverse)
    for(int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    return 0;
}
