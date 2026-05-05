int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {

    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int** result = (int**)malloc(2000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));

    int levelCount = 0;

    while (front < rear) {

        int size = rear - front;   // nodes in current level

        result[levelCount] = (int*)malloc(size * sizeof(int));
        (*returnColumnSizes)[levelCount] = size;

        for (int i = 0; i < size; i++) {

            struct TreeNode* node = queue[front++];

            result[levelCount][i] = node->val;

            if (node->left)
                queue[rear++] = node->left;

            if (node->right)
                queue[rear++] = node->right;
        }

        levelCount++;
    }

    *returnSize = levelCount;
    return result;
}
