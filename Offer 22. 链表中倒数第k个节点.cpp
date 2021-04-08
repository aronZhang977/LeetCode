/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *pPre = head;
        for(int i = 0;i != k;++i)
        {
            pPre= pPre->next;
            if(NULL== pPre)
            {
                return head;
            }
        }
            
        while(NULL != pPre)
        {
            pPre = pPre->next;
            head = head->next;
        }

        return head;     

    }
};