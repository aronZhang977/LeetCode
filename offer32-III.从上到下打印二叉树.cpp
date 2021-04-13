/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 之字形打印

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(nullptr == root)
            return res;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty())
        {
            vector<int> level_data;
            int level_count = que.size();
            while(level_count--)
            {
                level_data.push_back(root->val);
                if(root->left)
                    que.push(root->left);
                if(root->right)
                    que.push(root->right);
                que.pop();
                root = que.front();
            }
            if(res.size() & 1)
                reverse(level_data.begin(),level_data.end());
            res.push_back(level_data);
        }
        return res;
    }
};