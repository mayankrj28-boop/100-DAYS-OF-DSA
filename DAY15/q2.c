void setZeroes(int** matrix, int matrixSize, int* matrixColSize)
{
    int m = matrixSize;
    int n = matrixColSize[0];

    int i, j;
    int firstRowZero = 0, firstColZero = 0;

    // check first row
    for(j = 0; j < n; j++)
        if(matrix[0][j] == 0)
            firstRowZero = 1;

    // check first column
    for(i = 0; i < m; i++)
        if(matrix[i][0] == 0)
            firstColZero = 1;

    // mark rows & columns
    for(i = 1; i < m; i++)
    {
        for(j = 1; j < n; j++)
        {
            if(matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // update matrix
    for(i = 1; i < m; i++)
    {
        for(j = 1; j < n; j++)
        {
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }

    // update first row
    if(firstRowZero)
        for(j = 0; j < n; j++)
            matrix[0][j] = 0;

    // update first column
    if(firstColZero)
        for(i = 0; i < m; i++)
            matrix[i][0] = 0;
}
