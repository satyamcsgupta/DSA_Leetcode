/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void find(TreeNode* root , int start , TreeNode* &burnNode){
    if(!root){
        return ;
    }
    if(root->val == start ){
        burnNode = root;
        return ;
    }

    find(root->left ,start ,burnNode);
    find(root->right ,start ,burnNode);
}
int Height(TreeNode* root ){
    if(!root){
        return 0;
    }
    return 1+max(Height(root->left) ,Height(root->right));
}
int burn(TreeNode*  root ,int &time ,int start){
    if(!root){
        return 0;
    }
    if(root ->val == start ){
        return -1;
    }
    int left = burn(root->left , time , start );
    int right = burn(root->right , time , start );
    if(left <0){
        time = max(time ,abs(left)+right );
        return left-1;
    }
    if(right <0){
        time = max(time , abs(right)+left);
        return right -1 ;
    }
    return 1+max(left ,right);

}
    int amountOfTime(TreeNode* root, int start) {
        int time =0;
        burn(root ,time ,start);
       TreeNode* burnNode = NULL;
       find(root, start ,burnNode);
       int high = Height(burnNode)-1;

       return max(time ,high);
    }
};