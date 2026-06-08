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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return NULL;
        
        if(key<root->val)
            root->left=deleteNode(root->left, key);
        else if(key>root->val)
            root->right=deleteNode(root->right, key);
        else {
            if(root->left==NULL || root->right==NULL) {
                if(root->left==NULL)
                    return root->right;
                return root->left;
            }
            else {
                int val=findMin(root->right);
                root->val=val;
                root->right=deleteNode(root->right, val);
            }
        }

        return root;
    }

    int findMin(TreeNode *root) {
        while(root->left!=NULL)
            root=root->left;
        
        return root->val;
    }
};