/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // 递归解法
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root)
            return root;
        TreeNode* pTemp = root->left;
        root->left = mirrorTree(root->right);    
        root->right = mirrorTree(pTemp);

        return root;
    }
};
