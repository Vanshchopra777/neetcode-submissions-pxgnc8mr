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

class Codec {
public:
   void dfs(TreeNode* root,string &data){
        if(!root){
            data+="#,";
            return;
        }


        data+=to_string(root->val)+',';


        dfs(root->left,data);
        dfs(root->right,data);



    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        string data="";

        dfs(root,data);
        return data;
        
    }



    // Decodes your encoded data to tree.
    TreeNode* build(vector<string>&node, int &i){
        
        if(node[i]=="#"){
            i++;
            return NULL;
        }
        
        TreeNode* root=new TreeNode(stoi(node[i]));
        i++;

        root->left=build(node, i);
        root->right=build(node, i);
        return root;

    }

    TreeNode* deserialize(string data) {

        vector<string>node;
        string temp="";
        for(auto it:data){
            if(it==','){
                node.push_back(temp);
                temp="";
            }
            else temp+=it;

        }
        int i=0;
       return  build(node,i);

        
    }
};
