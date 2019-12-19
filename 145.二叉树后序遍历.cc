
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

struct  TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x),left(NULL),right(NULL){}
    /* data */
};

class Solution
{
    public:
    vector<int> postorderTracersal(TreeNode* root)
    {
        vector<int> ret;
        stack<TreeNode *> stack;
        unordered_set<TreeNode*> visit_set;

        if (root)
        {
            stack.push(root);
        }

        while (!stack.empty())
        {
            TreeNode* node =stack.top();
            bool right_visit = true ,left_vist = true;
            //right  left root
            if (node->right && visit_set.find(node->left) == visit_set.end())
            {
                right_visit = false;
                stack.push(node->right);
            }
            if (node->left && visit_set.find(node->left) == visit_set.end() )
            {
                left_vist = false;
                stack.push(node->left);
            }
            if (!left_vist && !right_visit)
            {
                ret.push_back(node->val);
                visit_set.insert(node);
                stack.pop();  
            }
        }
    }
};
