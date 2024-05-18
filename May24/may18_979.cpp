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
 int steps = 0;
 int dfs(TreeNode* root){
    if(root == NULL) return 0;
    int leftrequired = dfs(root->left);
    int rightrequired = dfs(root->right);
    steps += abs(leftrequired)+abs(rightrequired);
    return (root->val-1)+leftrequired+rightrequired;
 }
    int distributeCoins(TreeNode* root) {
      dfs(root);
      return steps;  
    }
};
