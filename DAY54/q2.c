int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int** result = (int**)malloc(2000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));

    int leftToRight = 1;
    int levelCount = 0;

    while (front < rear) {
        int size = rear - front;
        int* level = (int*)malloc(size * sizeof(int));

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];

            int index = leftToRight ? i : (size - 1 - i);
            level[index] = node->val;

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }

        result[levelCount] = level;
        (*returnColumnSizes)[levelCount] = size;
        levelCount++;

        leftToRight = !leftToRight;
    }

    *returnSize = levelCount;
    return result;
}
