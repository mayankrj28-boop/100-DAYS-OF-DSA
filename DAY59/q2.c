#include <stdlib.h>

// Create node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* build(int* inorder, int* postorder, int inStart, int inEnd, int* postIndex, int* map) {
    if (inStart > inEnd)
        return NULL;

    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode* root = newNode(rootVal);

    int inIndex = map[rootVal + 3000];

    // build right first
    root->right = build(inorder, postorder, inIndex + 1, inEnd, postIndex, map);
    root->left  = build(inorder, postorder, inStart, inIndex - 1, postIndex, map);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    int map[6001];

    for (int i = 0; i < inorderSize; i++) {
        map[inorder[i] + 3000] = i;
    }

    int postIndex = postorderSize - 1;

    return build(inorder, postorder, 0, inorderSize - 1, &postIndex, map);
}
