/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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

 // 递归
class Solution {
public:
    void func(TreeNode* root,vector<int>& res)
    {
        if(root == nullptr)
            return;
        res.push_back(root->val);
        func(root->left,res);
        func(root->right,res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        func(root,res);
        return res;
    }
};

// 迭代  利用栈结构
/*
迭代和递归是等价的，区别在于递归的时候隐式的维护了一个栈
*/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr)
            return {};
        
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* node = root;
        while(!stk.empty() || node != nullptr)
        {
            while (node != nullptr)
            {
                res.emplace_back(node->val);
                stk.emplace(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            node=node->right;
        }
        return res;
    }
};
// @lc code=end

