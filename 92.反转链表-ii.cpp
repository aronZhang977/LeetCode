/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
 // 一次遍历，滑动窗口，设置哨兵防止从第一个开始反转
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 设置 dummyNode 防止从第一个开始反转
        ListNode *pDummyNode = new ListNode(-1);
        pDummyNode->next = head;
        ListNode *pPre = pDummyNode;
        for(int i = 0; i < left - 1; ++i)
        {
            pPre = pPre->next;
        }
        ListNode *pCur = pPre->next;
        ListNode *pNext;
        for(int i = 0; i < right - left; ++i)
        {
            pNext = pCur->next;
            pCur->next = pNext->next;
            pNext->next = pPre->next;
            pPre->next = pNext;
        }
        return pDummyNode->next;
    }
};
// @lc code=end

