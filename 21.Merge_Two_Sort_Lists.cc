/*
合并两个有序链表
方法一 递归

方法二 迭代

 */

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    /* data */
};

class Solution
{
public:
    // 方法1 递归
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        else if (l2 == NULL)
            return l1;
        else if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    //递归方法  二路归并
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
        {
            return l2;
        }
        else if (l2 == NULL)
        {
            return l1;
        }
        else if (l1->val <= l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }

    //方法2 迭代
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *prehead = new ListNode(-1);
        ListNode *prev = prehead;
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val <= l2->val)
            {
                prev->next = l1;
                l1 = l1->next;
            }
            else
            {
                prev = prev->next;
            }
            prev->next = l1 != NULL ? l1 : l2;
            return prehead->next;
        }
    }
    //非递归方法
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
        {
            return l2;
        }
        else if (l2 == NULL)
        {
            return l1;
        }
        ListNode *ret = new ListNode(-1); //新建头结点
        //new的使用方法
        ListNode *curr = ret;

        while (l1 == NULL && l2 == NULL)
        {
            if (l1->val <= l2->val)
            {
                ret->next = l1;
                l1 = l1->next;
            }
            else
            {
                ret->next = l2;
                l2 = l2->next;
            }
        }
    }

