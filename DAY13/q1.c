#include <stdio.h>

int main()
{
    int r, c;

    // Input rows and columns
    scanf("%d %d", &r, &c);

    int matrix[r][c];

    // Input matrix elements
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    // Spiral traversal
    while(top <= bottom && left <= right)
    {
        // Left → Right
        for(int i = left; i <= right; i++)
            printf("%d ", matrix[top][i]);
        top++;

        // Top → Bottom
        for(int i = top; i <= bottom; i++)
            printf("%d ", matrix[i][right]);
        right--;

        // Right → Left
        if(top <= bottom)
        {
            for(int i = right; i >= left; i--)
                printf("%d ", matrix[bottom][i]);
            bottom--;
        }

        // Bottom → Top
        if(left <= right)
        {
            for(int i = bottom; i >= top; i--)
                printf("%d ", matrix[i][left]);
            left++;
        }
    }

    return 0;
}
