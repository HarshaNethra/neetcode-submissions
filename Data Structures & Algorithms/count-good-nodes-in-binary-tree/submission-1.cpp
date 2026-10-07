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
    int goodNodes(TreeNode* root) {
        return countGoodNodes(root, INT_MIN);
    }

    int countGoodNodes(TreeNode* root, int maxSoFar) {
        if(!root)
            return 0;
        
        if(maxSoFar<=root->val) {
            maxSoFar=root->val;
            int count=countGoodNodes(root->left, maxSoFar)+1;
            return count+countGoodNodes(root->right, maxSoFar);
        }
        
        return countGoodNodes(root->left, maxSoFar)+countGoodNodes(root->right, maxSoFar);
    }
};
