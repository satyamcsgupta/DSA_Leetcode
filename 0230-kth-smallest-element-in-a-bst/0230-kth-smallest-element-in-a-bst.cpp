class Solution {
public:
    int find(TreeNode* root, int &k) {

        if (!root) {
            return -1;
        }

        // Go to left subtree
        int left = find(root->left, k);

        // If answer was found in left subtree
        if (left != -1) {
            return left;
        }

        // Visit current node
        k--;

        if (k == 0) {
            return root->val;
        }

        // Go to right subtree
        return find(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        return find(root, k);
    }
};