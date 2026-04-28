void inorder(struct TreeNode* root, int* arr, int* returnSize) {
    if (root == NULL)
        return;

    inorder(root->left, arr, returnSize);

    arr[*returnSize] = root->val;
    (*returnSize)++;

    inorder(root->right, arr, returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    
    int* arr = (int*)malloc(100 * sizeof(int)); // max nodes = 100
    *returnSize = 0;

    inorder(root, arr, returnSize);

    return arr;
}
