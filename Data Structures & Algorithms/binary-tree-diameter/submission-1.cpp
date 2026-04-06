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
    int max_h(TreeNode* root,int &maxi){
        if(!root)return 0;

        int left=max_h(root->left,maxi);
        int right=max_h(root->right,maxi);
        maxi=max(maxi,left+right);

        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        int maxi=0;
        max_h(root,maxi);
        return maxi;
        
    }
};
