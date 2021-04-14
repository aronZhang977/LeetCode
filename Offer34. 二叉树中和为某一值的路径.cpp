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

// 方法1：深度优先搜索

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(TreeNode* root,int sum)
    {
        if(nullptr == root)
            return;
        path.emplace_back(root->val);
        sum -= root->val;
        if(nullptr == root->left && nullptr == root->right && 0 == sum)
            res.emplace_back(path);
        
        dfs(root->left,sum);
        dfs(root->right,sum);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root,sum);
        return res;
    }
};


// 方法2：广度优先搜索
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {

    }
};