/*
 Offer 25. 合并两个排序的链表
输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

示例1：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *pCur = l1, *pPre = l1->next;
        while(pPre && l2)
        {
            //pPre->val > l2->val
            if(pCur->val <= l2->val)
            {
                ListNode *pTemp = ;
                

            }
        }

        pCur->next = l2;

        return l1;
    }


