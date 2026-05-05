/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int preIndex;

// Helper to build tree
struct TreeNode* build(int* preorder, int* inorderIndexMap, int left, int right) {
    if (left > right)
        return NULL;

    int rootVal = preorder[preIndex++];
    
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = rootVal;
    root->left = root->right = NULL;

    int inIndex = inorderIndexMap[rootVal + 3000]; // shift for negative values

    root->left = build(preorder, inorderIndexMap, left, inIndex - 1);
    root->right = build(preorder, inorderIndexMap, inIndex + 1, right);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int* inorderIndexMap = (int*)malloc(sizeof(int) * 6001);

    // Store index of each value
    for (int i = 0; i < inorderSize; i++) {
        inorderIndexMap[inorder[i] + 3000] = i;
    }

    preIndex = 0;

    return build(preorder, inorderIndexMap, 0, inorderSize - 1);
}
