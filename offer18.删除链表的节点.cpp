
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/// 这道题不知道为什么 free和delete都会报错  
// 双指针
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *pCur = head, *pPre = head;
        if(val == pCur->val)
        {
            pCur = pCur->next;
           // free(pPre);
            return pCur;
        }
        while(pCur)
        {
            if(val == pCur->val)
            {
                pPre->next = pCur->next;
                //free(pCur);
                break;
            }
            pPre = pCur;
            pCur = pCur->next;
        }
        return head;
    }
};

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
    ListNode* deleteNode(ListNode* head, int val) {
        if (!head)
            return NULL;
        else if (head->val == val)
        {
            head = head->next;
        }
        else
        {
            ListNode *p = head;
            while(p->next && p->next->val != val)
                p = p->next;
            if(p->next)
            {
                p->next = p->next->next;
            }
        }
        return head;
    }
};