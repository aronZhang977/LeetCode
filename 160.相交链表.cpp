/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


// 用哈希表标记一条链 遍历另一条  有相同的就返回

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
            return nullptr;
        set<ListNode*> set;
        
        while(headA)
        {
            set.insert(headA);
            headA = headA->next;
        }

        while(headB)
        {
            auto it = set.find(headB);
            if(it != set.end())
            {
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }
};

 // 方法1 统计两链的长度，长的先走差值  然后一起走找相同
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
            return nullptr;

        int countA = 0,countB = 0;
        ListNode* pTmp = headA;
        while(pTmp)
        {
            ++countA;
            pTmp = pTmp->next;
        }
        pTmp = headB;
        while(pTmp)
        {
            ++countB;
            pTmp = pTmp->next;
        }

        if(countA > countB)
        {
            for(int i = 0; i < countA - countB ; ++i)
            {
                headA = headA->next;
            }
        }
        else
        {
            for(int i = 0; i< countB - countA ; ++i)
            {
                headB = headB->next;
            }
        }

        while(headA && headB)
        {
            if(headA == headB)
                return headA;
        }
        return nullptr;
    }
};
// @lc code=end

