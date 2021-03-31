/*
输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

 

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;

*     TreeNode(int x) : val(x), left(NULL), right(NULL) {} * }; */
/*  中序遍历中对根节点进行定位时， 一种简单的办法是，直接扫描整个中序遍历的结构并找出根节点,这种方法时间复杂度高。
另一种方法，可以考虑适用hash表来帮助快速定位根节点。
对于哈希映射中的每个键值对，键表示一个元素（节点的值），值表示其在中序中出现的位置。
在构造此二叉树之前，可以对中序遍历的列表进行一遍扫描，就可以构造出这个哈希映射

*/

// 递归
class Solution {
public:
    // 前序数组  中序数组  前序左  前序右  中序左 中序右
    TreeNode* myBuildTree(const vector<int> &preorder, const vector<int> &inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right)
    {
        if (preorder_left > preorder_right)
        {
            return nullptr;
        }

        // 前序遍历中的第一个节点就是根节点
        int preorder_root = preorder_left;
        // 在中序遍历中定位根节点
        int inorder_root = index[preorder[preorder_root]];

        // 先把根节点建立出来
        TreeNode *root = new TreeNode(preorder,preorder_root);
        // 得到左子树的节点数目
        int size_left_subtree = inorder_root - inorder_left;

        // 递归构造左子树并连接到根节点；
        root->left = myBuildTree(preorder,inorder,preorder_left + 1,preorder_right + size_left_subtree,inorder_left, inorder_root - 1);
        // 递归构造右子树并连接到根节点
        root->right = myBuildTree(preorder,inorder,preorder_root + size_left_subtree + 1,preorder_right,inorder_root + 1,inorder_right);
        // 这个位置要算准给个点的位置。。。
    
        return root;       
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 构造哈希映射，帮助快速定位根节点
        for(auto &i : preorder)
        {
            index[inorder[i]] = i;
        }
        return myBuildTree(preorder,inorder,0,preorder.size() - 1, 0,preorder.size() - 1)
    }

private:
    unordered_map<int,int> index;
};

// 迭代
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
//  前序 [根左右]   中序 [左根右]
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!preorder.size())
            return nullptr;
        stack<TreeNode*> stk;
        // 构造根节点 并 入栈
        TreeNode* root = new TreeNode(preorder[0]);
        stk.push(root);
        int inorderIndex = 0;
        for(int i = 1; i < preorder.size(); ++i)
        {
            int preorderVal = preorder[i];
            TreeNode* node = stk.top();     
            //  如果栈顶和index指针 相等 将当前节点作为上一个弹出节点的右儿子；不同就将当前节点作为最后一个弹出的节点的左儿子
            if(node->val != inorder[inorderIndex])
            {
                node->left = new TreeNode(preorderVal);
                // 入栈
                stk.push(node->left);
            }
            else
            {
                while(!stk.empty() && stk.top()->val == inorder[inorderIndex])
                {
                    node = stk.top();
                    stk.pop();
                    ++inorderIndex;
                }
                node->right = new TreeNode(preorderVal);
                //入栈
                stk.push(node->right);
            }
        }
        return root;
    }
};


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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

    }
};
