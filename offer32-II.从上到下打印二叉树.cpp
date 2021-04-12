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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return root;

        vector<vector<int>> res;
        queue<int> que;     //辅助队列
        queue.push(root);
       
        while(!que.empty())
        {
            int count = que.size();  // 本层节点数
            vector<int> level;      // 层数据

            while(count)
            {
                if(root->left)
                    que.push(root->left);
                if(root->right)
                    que.push(root->left);
                level.push_back(root->val);
                que.pop();
                root = que.top();
                --count;
            }
        
            res.push_back(level);
        }
        return res;
    }
};