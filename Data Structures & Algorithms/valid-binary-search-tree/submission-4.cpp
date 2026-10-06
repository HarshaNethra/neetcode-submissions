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
    /*unordered_set<int> values;*/
    vector<int> values;
    bool isValidBST(TreeNode* root) {
        /*if(!root)
            return true;
        
        if(root->left!=NULL && root->left->val >= root->val)
            return false;
        if(root->right!=NULL && root->right->val <= root->val)
            return false;
        
        if(values.size()==0)
            values.insert(root->val);
        else if(values.find(root->val)==values.end())
            values.insert(root->val);
        else
            return false;
        
        return isValidBST(root->left) && isValidBST(root->right);*/

        dfs(root);
        for(int i=0;i<values.size()-1;i++) {
           if(values[i]>=values[i+1])
            return false;
        }

        return true;
    }

    void dfs(TreeNode *root) {
        if(!root)
            return;
        
        dfs(root->left);
        values.push_back(root->val);
        dfs(root->right);
    }
};
