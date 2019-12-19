
/* 

合并k个有序列表

方法1  暴力解
遍历所有链表，将所有结点的值放到一个数组中
将这个数组排序，然后遍历所有元素得到正确的顺序
用遍历得到的值，创建一个新的有序链表

方法2 逐一比较
比较k个节点  获得最小的值的节点
将选中节点接在最终有序链表的后边

方法三  两两合并链表
将合并k个链表的问题转换成合并两个链表k-1次

方法四  分治法  
将k个链表配对并将同一对中的链表合并
第一轮合并以后 k个链表被合并成了k/2个链表，平均长度为 2N/k
重复这一过程，直到得到有序链表

*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL) {}
    /* data */
};

class Solution {
public:
    ListNode *mergeTwoList(ListNode *l1, ListNode *l2)
    {
        ListNode* pHead = new ListNode(0);
        ListNode *pCur = pHead;
        while (l1 || l2)
        {
            ListNode *temp;
            if (l1 && l2)
                temp = l1->val < l2->val ? l1 : l2;
            else if (l1)
                temp = l1;
            else
                temp = l2;
            pCur->next = temp;
            pCur = pCur->next;
            temp == l1 ? l1 = l1->next : l2 = l2->next;
        }
        return pHead->next;
    }
    ListNode *merge(int l,int r,vector<ListNode*>& v)
    {
        if(l>r) return nullptr;
        if(l==r) return v[l];
        if(r==l+1) return mergeTwoList(v[l],v[r]);
        int m=l+(r-l>>1);
        return mergeTwoList(mergeKLists(lists),mergeKLists(lists));

    }

//分治
ListNode* mergeKLists(vector<ListNode*>& lists,int begin, int end)
{
    if(end<begin) return NULL;
    if(end == begin) return lists[begin];

    int mid = (begin + end) / 2;
    ListNode* p1 =mergeKLists(lists,begin,mid);
    ListNode* p2 = mergeKLists(lists,mid+1,end);

    ListNode head(0);
    ListNode* cur=&head;
    while(p1 && p2)
    {
        if(p1->val < p2->val)
        {
            cur->next = p1;
            p1 = p1->next;
        }else{
            cur->next = p2;
            p2 = p2->next; 
        }
        cur = cur->next;
    }
     
    if(p1) cur->next = p1;
    else if(p2) cur->next = p2;
    return head.next;
}
ListNode* mergeKLists(vector<ListNode*> lists)
{
    return mergeKLists(lists,0,lists.size()-1);
}
    

//两两合并
ListNode* mergeKLists(vector<ListNode*>& lists)
{
    int size=lists.size();
    if(size == 0)
    return NULL;
    if(size == 1)
    return lists[0];
    
    int begin = 0;
    ListNode* last=lists[0];
    while(size!=1)
    {
        mergeTwoList(last,lists[++begin]);
        size--;
    }

}
ListNode *mergeTwoList(ListNode *l1, ListNode *l2)
{

    ListNode *pHead = new ListNode(-1);
    ListNode *pt = pHead;
    if (l1 == NULL)
        return l2;
    else if (l2 == NULL)
        return l1;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            pt->next = l1;
            l1 = l1->next;
        }
        else
        {
            pt->next = l2;
            l2 = l2->next;
        }
        pt = pt->next;
    }
    if (l1->next == NULL)
        pt->next = l2;
    if (l2->next == NULL)
        pt->next = l1;
    return pHead->next;
}












};