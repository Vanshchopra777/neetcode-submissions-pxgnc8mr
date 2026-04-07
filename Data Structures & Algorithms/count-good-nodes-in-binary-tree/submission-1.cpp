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

    void solve(TreeNode* temp,int maxi,int &cnt){
       if(!temp) return;

        if(temp->val>=maxi){
            cnt++;
            maxi=temp->val;
        }
        solve(temp->left,maxi,cnt);
        solve(temp->right,maxi,cnt);



        
    }
    int goodNodes(TreeNode* root) {
        int cnt=0;
        int maxi=root->val;
        solve(root,maxi,cnt);
        return cnt;
        
    }
};
