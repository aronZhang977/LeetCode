/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */

// @lc code=start
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
            // 用栈 模拟
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> stk;
        stk.push(root);

        while(!stk.empty())
        {
            TreeNode* node = stk.top();
            stk.pop();
            if(NULL == node)
                continue;
            swap(node->left,node->right);
            stk.push(node->left);
            stk.push(node->right);
        }
        
        return root;
    }
};
// @lc code=end

