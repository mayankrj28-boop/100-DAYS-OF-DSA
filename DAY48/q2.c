int isLeaf(struct TreeNode* node)
{
    if (node == NULL) return 0;
    return (node->left == NULL && node->right == NULL);
}

int sumOfLeftLeaves(struct TreeNode* root)
{
    if (root == NULL)
        return 0;

    int sum = 0;

    if (root->left != NULL && isLeaf(root->left))
        sum += root->left->val;

    sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);

    return sum;
}
