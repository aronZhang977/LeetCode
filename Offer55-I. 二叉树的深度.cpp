/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// dfs
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (nullptr == root)
            return 0;
        return max(maxDepth(root->left),maxDepth(root->right)) + 1;
    }
};

// bfs
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(nullptr == root)
            return 0;
        queue<TreeNode*> que;
        que.push(root);
        int ans = 0;
        while(!que.empty())
        {
            int sz = que.size();
            while(sz > 0)
            {
                TreeNode* node = que.front();
                if(node->left)
                    que.push(node->left);
                if(node->right)
                    que.push(node->right);
                que.pop();
                --sz;
            }
            ++ans;
        }
        return ans;
    }
};