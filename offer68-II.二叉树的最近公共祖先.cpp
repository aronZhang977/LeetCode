/**
 * Definition for a binary tree node.
 * 
 */
struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



// 递归
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || p == root || q == root)
        {
            return root;
        }    
        
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        return left == nullptr ? right :(right == nullptr ? left:root);
    }
};

// 递归
class Solution {
public:
    TreeNode* m_ans;

    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))) {
            m_ans = root;
        } 
        return lson || rson || (root->val == p->val || root->val == q->val);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return m_ans;
    }
};

// 用哈希存储父节点
/*
    1.从根节点开始遍历用哈希表记录每个节点的父节点指针。
    2.从p开始不断往祖先移动，并记录已经访问过得祖先节点
    3.从q节点开始往祖先移动，如果有祖先已经被访问过，即所求LCA节点
*/
class Solution
{
public:
    unordered_map<int, TreeNode*> m_father;   //   父节点
    unordered_map<int,bool> m_vis;      // 是否访问过

    void dfs(TreeNode* root)
    {
        if(root->left != nullptr)
        {
            m_father[root->left->val] = root;
            dfs(root->left);
        }  
        if(root->right != nullptr)
        {
            m_father[root->right->val] = root;
            dfs(root->right);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        m_father[root->val] = nullptr;
        dfs(root);
        while (p != nullptr)
        {
            m_vis[p->val] = true;
            p = m_father[p->val];
        }
        while (q != nullptr)
        {
            if(m_vis[q->val])
                return q;
            q = m_father[q->val];
        }
        return nullptr;     
    }
};