/*
 Offer 25. 合并两个排序的链表
输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

示例1：

输入:  
    1->2->4,
    1->3->4
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
        if(!l1 || !l2)
            return (!l1)?l2:l1;
        ListNode *pDummy = new ListNode(0);
        pDummy->next = (l1->val < l2->val) ? l1 : l2;

        ListNode *pHead = pDummy->next;
        if(l1 == pHead)
            l1 = l1->next;
        else   
            l2 = l2->next;

        while(l1 && l2)
        {
            if (l1->val <l2->val)
            {
                pHead->next = l1;
                pHead = pHead->next;
                l1 = l1->next;
            }
            else
            {
                pHead->next = l2;
                pHead = pHead->next;
                l2 = l2->next;
            }
        }
     
        if(l1)
            pHead->next = l1;
        if(l2)
            pHead->next = l2;
     
        return pDummy->next;
    }
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *pDummy = new ListNode(0), *pPre = pDummy;

        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                pPre->next = l1;
                pPre = pPre->next;
                l1 = l1->next;
            }
            else
            {
                pPre->next = l2;
                pPre = pPre->next;
                l2 = l2->next;
            }
        }
        if (l1)
            pPre->next = l1;
        if(l2)
            pPre->next = l2;
        return pDummy->next;    
        
    }
};
/*
链表单链表在插入和删除时，需要修改前驱结点的后继指针，这就形成了“邻居依赖”，
链表中第一个元素没有前驱结点，如果没有特殊处理，在插入和删除第一个结点时，就会出错。
所以我们可以申请一个头结点，作为原本的第一个结点的前驱结点，问题也就解决了。
但是在这种方式中，我们要插入或者删除一个结点时，要知道它的前驱结点地址，这往往是麻烦的。
另一个方式，也是我更喜欢的方式，是申请一个尾结点，作为原本最后一个结点的后继结点。
要删除某个元素时，我们不删除当前这个结点，而是用后继结点的数据覆盖当前结点的数据，再删除后继结点。
这种方式，不需要访问前驱结点，也就解决了获取前驱结点的困难。
插入元素也是同理。而最后一个结点没有后继结点，所以需要一个尾结点作为哨兵。
如果用的是双链表，就需要在头尾各加一个哨兵。
*/

