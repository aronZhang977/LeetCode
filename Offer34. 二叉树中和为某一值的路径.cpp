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
    vector<vector<int>> m_res;
    vector<int> m_path;

    void dfs(TreeNode* root,int sum)
    {
        if(nullptr == root)
            return;
        m_path.emplace_back(root->val);
        sum -= root->val;
        if(nullptr == root->left && nullptr == root->right && 0 == sum)
            m_res.emplace_back(m_path);
        
        dfs(root->left,sum);
        dfs(root->right,sum);
        m_path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root,sum);
        return m_res;
    }
};



// 方法2：广度优先搜索
/* 
    遍历这棵树，当遍历到叶子节点，且此时路径和恰为目标和时，我们就找到了一条满足条件的路径
    使用哈希表记录树中的每一个节点的父节点。每次找到一个满足条件的节点，我们就从该节点出发不断向父节点迭代，即可还原出从根节点到当前节点的路径
*/
class Solution {
public:

    vector<vector<int>> m_res;
    unordered_map<TreeNode*,TreeNode*> m_parent;

    void getPath(TreeNode* node)
    {
        vector<int> tmp;
        while(nullptr != node)
        {
            tmp.emplace_back(node->val);
            node = m_parent[node];
        }
        reverse(tmp.begin(), tmp.end());
        m_res.emplace_back(tmp);    
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum)
    {
        if(nullptr == root)
            return m_res;

        queue<TreeNode*> que_node;    // 一个队列放节点
        queue<int> que_sum;     // 一个队列放值
        que_node.emplace(root);
        que_sum.emplace(0);

        while(!que_node.empty())
        {
            TreeNode* node = que_node.front();
            que_node.pop();
            int rec = que_sum.front() + node->val;
            que_sum.pop();

            if(nullptr == node->left && nullptr == node->right)
            {
                if(rec == sum)
                    getPath(node);
            }
            else
            {
                if(node->left != nullptr)
                {
                    m_parent[node->left] = node;
                    que_node.emplace(node->left);
                    que_sum.emplace(rec);
                }
                if(node->right != nullptr)
                {
                    m_parent[node->right] = node;
                    que_node.emplace(node->right);
                    que_sum.emplace(rec);
                }
            }
        }
        return m_res;
    }

};