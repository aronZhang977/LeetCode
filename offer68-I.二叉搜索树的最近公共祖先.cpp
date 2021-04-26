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


// 两次遍历 取路径   找路径最后一个相同节点
class Solution {
public:
    // 利用二叉搜索树 中序 递增的特性 两条路径都从根开始录入
    vector<TreeNode*> getPath(TreeNode* root,TreeNode* target)
    {
        vector<TreeNode*> path;
        TreeNode* node = root;
        while (node != target)
        {
            path.push_back(node);
            if(target->val < node->val)
                node = node->left;
            else
                node = node->right;            
        }
        path.push_back(node);
        return path;        
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p = getPath(root,p);
        vector<TreeNode*> path_q = getPath(root,q);
        TreeNode* ancestor;
        
        for(int i = 0; i < path_p.size() && i < path_q.size(); ++i)
        {
            if(path_p[i] == path_q[i])
                ancestor = path_p[i];
            else
                break;
        }
        return ancestor;
    }
};

// 优化整合
class Solution{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ancestor = root;
        
        while(true)
        {
            if(p->val < ancestor->val && q->val < ancestor->val)
                ancestor = ancestor->left;
            else if(p->val > ancestor->val && q->val > ancestor->val)
                ancestor = ancestor->right;
            else
                break;
        }
        return ancestor;
    }
};