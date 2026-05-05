void dfs(int** image, int imageSize, int* imageColSize, int r, int c, int oldColor, int newColor) {
    // Boundary check
    if (r < 0 || c < 0 || r >= imageSize || c >= imageColSize[0])
        return;

    // If not same color, stop
    if (image[r][c] != oldColor)
        return;

    // Change color
    image[r][c] = newColor;

    // Explore 4 directions
    dfs(image, imageSize, imageColSize, r + 1, c, oldColor, newColor);
    dfs(image, imageSize, imageColSize, r - 1, c, oldColor, newColor);
    dfs(image, imageSize, imageColSize, r, c + 1, oldColor, newColor);
    dfs(image, imageSize, imageColSize, r, c - 1, oldColor, newColor);
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    
    int oldColor = image[sr][sc];

    // If color is same, no need to process
    if (oldColor == color) {
        *returnSize = imageSize;
        *returnColumnSizes = imageColSize;
        return image;
    }

    dfs(image, imageSize, imageColSize, sr, sc, oldColor, color);

    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;

    return image;
}
