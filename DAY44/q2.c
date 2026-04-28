void preorder(struct TreeNode* root, int* arr, int* size) {
    if (root == NULL)
        return;

    arr[(*size)++] = root->val;

    preorder(root->left, arr, size);
    preorder(root->right, arr, size);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    
    int* result = (int*)malloc(1000 * sizeof(int));
    *returnSize = 0;

    preorder(root, result, returnSize);

    return result;
}
