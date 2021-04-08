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
class Solution {
public:
    // 迭代
    ListNode* reverseList(ListNode* head) {
        ListNode *pCur = head;    
        ListNode *pPre = nullptr;
        while(pCur)
        {
            ListNode *pTemp = pCur->next;
            pCur->next = pPre;
            pPre = pCur;
            pCur = pTemp;
        }     

        return pPre;
    }
};