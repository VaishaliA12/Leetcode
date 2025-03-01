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
        int sum(TreeNode* root,int &ans){
            if(root==NULL) return 0;
            int leftMaxPath=max(0,sum(root->left,ans));
            int rightMaxPath=max(0,sum(root->right,ans));
            ans=max(ans,leftMaxPath+rightMaxPath+root->val);
            return max(leftMaxPath,rightMaxPath)+root->val;
        }
        int maxPathSum(TreeNode* root) {
            int ans=INT_MIN;
            sum(root,ans);
            return ans;
        }
    };