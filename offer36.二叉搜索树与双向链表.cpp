/*
    二叉搜索树转换成一个 有序的循环双向链表

    基于 二叉搜索树的中序遍历为递增序列

*/

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

// 二叉搜索树转换成一个 有序的循环双向链表
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root)
            return nullptr;
        dfs(root);
        m_pHead->left = m_pPre;
        m_pPre->right = m_pHead;
        return m_pHead;
    }
private:
    Node *m_pPre,*m_pHead;
    void dfs(Node *pCur)
    {
        if (nullptr == pCur)
            return;
        dfs(pCur->left);
        if (nullptr != m_pPre)
            m_pPre->right = pCur;
        else
            m_pHead = pCur;
        pCur->left = m_pPre;
        m_pPre = pCur;
        dfs(pCur->right);        
    }
};