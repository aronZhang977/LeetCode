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
    // 递归遍历
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!A || !B)
            return false;
        bool res = false;
        // 在A中找与 B的根节点 值一样的节点
        if(A->val == B->val)
            res = doesAHaveB(A,B);
        // 匹配不到  A往左子树去
        if(!res)
            res = isSubStructure(A->left, B);
        // 还匹配不到  A往右子树去
        if(!res)
            res = isSubStructure(A->right, B);
        return res;
    }

    bool doesAHaveB(TreeNode *r1, TreeNode *r2)
    {
        // 如果B已经遍历完了，ture
        if(!r2)
            return true;
        // 如果B还有，但A遍历完了，那B剩下的就没法匹配了，false
        if(!r1)
            return false;
        // 不相等，false
        if(r1->val != r2->val)
            return false;
        return doesAHaveB(r1->left,r2->left) && doesAHaveb(r1->right, r2->right);
    }
};