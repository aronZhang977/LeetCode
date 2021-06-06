/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// 优化只用一个指针
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dum = new ListNode(0,head);
        ListNode *temp = dum;
        while(temp->next != NULL)
        {
            if(temp->next->val == val)
            {
                temp->next = temp->next->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        return dum->next;
    }
};


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr)
            return head;
        ListNode dum(-1);
        dum.next = head;
        ListNode *pre = &dum;

        while(cur)
        {
            if(cur->val == val)
            {
                pre->next = cur->next;
                cur = cur->next;
            }
            else
            {
                cur = cur->next;
                pre = pre->next;
            }            
        }

        return dum.next;
    }
};
// @lc code=end

