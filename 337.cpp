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
        int solve(TreeNode* root,unordered_map<TreeNode*,int> &dp){
            if(root==NULL) return 0;
            if(dp.find(root)!=dp.end()) return dp[root];
            int rob1=root->val;
            if(root->left){
                rob1+=solve(root->left->left,dp);
                rob1+=solve(root->left->right,dp);
            }
            if(root->right){
                rob1+=solve(root->right->left,dp);
                rob1+=solve(root->right->right,dp);
            }
            int rob2=solve(root->left,dp)+solve(root->right,dp);
            return dp[root]=max(rob1,rob2);
        }
        int rob(TreeNode* root) {
            if(root==NULL) return NULL;
            if(root->left==NULL && root->right==NULL) return root->val;
            unordered_map<TreeNode*,int> dp;
            return solve(root,dp);
        }
    };