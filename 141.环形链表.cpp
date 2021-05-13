/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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



// 考虑短链  考虑 ->next 的有效性
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) 
        {
            return false;
        }

        ListNode* pCur = head;
        ListNode* pPre = head->next;
#if 1
        while(pCur != pPre)
        {
            if(nullptr == pPre || nullptr == pPre->next)  // 利用短路特性
                return false;
            pCur = pCur->next;
            pPre = pPre->next->next;
        }
        return true;    
#else
        while(pCur && pPre && pPre->next)
        {
            if(pCur == pPre)
                return true;
            pCur = pCur->next;
            pPre = pPre->next->next;
        }
        return false;        

#endif
    }
};


// 利用哈希存储  找到重复出现的节点
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> hash;
        
        while(head)
        {
            auto it = hash.find(head);
            if(it != hash.end())
            {
                return true;
            }
            hash.insert(head);
            head = head->next;
        }
        return false;
    }
};
// @lc code=end

