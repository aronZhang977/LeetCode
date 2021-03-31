/*
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

示例 1：

输入：head = [1,3,2]
输出：[2,3,1]
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 是否可以改变链表的结构，如果可以的话，可以考虑用翻转链表然后从头到尾输出

// 方法1：栈
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> stk;
        vector<int> res;
        ListNode *p = head;
        while(p)
        {
            stk.push(p->val);
            p = p->next;
        }
        while(!stk.empty())
        {
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }  
};

// 方法2：回溯法
class Solution {
public:
    // 当链表非常长的时候，会导致函数调用的层级很深，从而有可能导致函数调用栈溢出。
    void back_tracking_method(vector<int> &res,ListNode* head)
    {
        if(NULL == head) 
            return;
        back_tracking_method(res,head->next);
        res.push_back(head->val);
    }

    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        back_tracking_method(res,head);
        return res;
    }
};

// 方法3：vector的insert特性
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        // 利用vector 中 insert 可以指定插入位置的特性
        ListNode *p = head;
        vector<int> res;
        while(p)
        {
            res.insert(res.begin(),p->val);
            p = p->next;
        }
        return res;
    }
};
/// 这个方法效率明显要比其他方法低

