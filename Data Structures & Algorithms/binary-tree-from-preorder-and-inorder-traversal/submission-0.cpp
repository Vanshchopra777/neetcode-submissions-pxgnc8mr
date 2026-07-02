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
unordered_map<int,int>mpp;
TreeNode* build(vector<int>& preorder, vector<int>& inorder,int prestart,int preend,int instart,int inend){
    if(prestart>preend || instart >inend)return NULL;
    TreeNode* root=new TreeNode(preorder[prestart]);
    int rootidx=mpp[preorder[prestart]];
    int leftsize=rootidx-instart;

    root->left=build(preorder,inorder,prestart+1,prestart+leftsize,instart,rootidx-1);
    root->right=build(preorder,inorder,prestart+leftsize+1,preend,rootidx+1,inend);

    return root;





    
}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        if(n==0)return NULL;

        for(int i=0;i<n;i++){
            mpp[inorder[i]]=i;
        }
        return build(preorder,inorder,0,n-1,0,n-1);
        
    }
};
