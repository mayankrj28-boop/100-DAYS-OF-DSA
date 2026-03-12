#include <stdio.h>

// Recursive function to calculate a^b
long long power(int a, int b)
{
    if (b == 0)
        return 1;          // Base case
    else
        return a * power(a, b - 1);   // Recursive case
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    long long result = power(a, b);

    printf("%lld", result);
    return 0;
}
