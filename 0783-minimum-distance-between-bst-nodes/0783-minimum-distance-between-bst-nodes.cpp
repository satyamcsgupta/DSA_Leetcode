class Solution {
public:

    void distance(TreeNode* root, int &prev, int &ans, bool &hasPrev) {

        if (!root) {
            return;
        }

        distance(root->left, prev, ans, hasPrev);

        if (hasPrev) {
            ans = min(ans, root->val - prev);
        }

        prev = root->val;
        hasPrev = true;

        distance(root->right, prev, ans, hasPrev);
    }

    int minDiffInBST(TreeNode* root) {

        int ans = INT_MAX;
        int prev = 0;
        bool hasPrev = false;

        distance(root, prev, ans, hasPrev);

        return ans;
    }
};