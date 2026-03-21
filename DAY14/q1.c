#include <stdio.h>

int main()
{
    int n, i, j;
    int matrix[50][50];
    int isIdentity = 1;

    // Input size
    scanf("%d", &n);

    // Input matrix elements
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check identity matrix condition
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == j) // diagonal elements
            {
                if(matrix[i][j] != 1)
                {
                    isIdentity = 0;
                    break;
                }
            }
            else // non-diagonal elements
            {
                if(matrix[i][j] != 0)
                {
                    isIdentity = 0;
                    break;
                }
            }
        }
        if(isIdentity == 0)
            break;
    }

    // Output
    if(isIdentity == 1)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}
