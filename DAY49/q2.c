/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* insertIntoBST(struct TreeNode* root, int val)
{
    // If tree empty, create new node
    if (root == NULL)
    {
        struct TreeNode* node =
            (struct TreeNode*)malloc(sizeof(struct TreeNode));

        node->val = val;
        node->left = NULL;
        node->right = NULL;

        return node;
    }

    // Go left
    if (val < root->val)
    {
        root->left = insertIntoBST(root->left, val);
    }
    // Go right
    else
    {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}
