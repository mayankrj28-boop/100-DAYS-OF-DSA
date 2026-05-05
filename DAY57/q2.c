void flatten(struct TreeNode* root) {
    struct TreeNode* curr = root;

    while (curr != NULL) {
        if (curr->left != NULL) {
            struct TreeNode* prev = curr->left;

            // Find rightmost node of left subtree
            while (prev->right != NULL) {
                prev = prev->right;
            }

            // Attach right subtree
            prev->right = curr->right;

            // Move left subtree to right
            curr->right = curr->left;
            curr->left = NULL;
        }

        curr = curr->right;
    }
}
