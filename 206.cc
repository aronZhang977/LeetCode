/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)
        {
            return nullptr;
        }
        ListNode *p,*r;
        p = head->next;
        head->next = nullptr;
        while(p!=nullptr)
        {
            r=p->next;
            p->next = head;
            head = p;
            p = r;
        }
        return head; 
    }
};