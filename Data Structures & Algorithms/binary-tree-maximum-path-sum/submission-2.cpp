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
int maxsum=INT_MIN;
    int maxpath(TreeNode* root){
        if(!root)return INT_MIN;

        int left=max(0,maxpath(root->left));
        int right=max(0,maxpath(root->right));
        maxsum=max(maxsum,left+right+root->val);

        return root->val + max(left,right);
    }
    int maxPathSum(TreeNode* root) {

        maxpath(root);

        return maxsum;



    }
};
