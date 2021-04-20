/**
 * Definition for singly-linked list.
  
 */
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

/*
    双指针法
    先得  两链表长度，长链表先走 长度差 个 节点
    再同步遍历，所指相同即所求
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
            return nullptr;
        ListNode *pA = headA, *pB = headB;
        int countA = 0,countB = 0;
        while(pA)
        {
            pA = pA->next;
            ++countA;
        }
        while (pB)
        {
            pB = pB->next;
            ++countB;   
        }
        
        ListNode *pL = countA > countB ? headA : headB;
        ListNode *pS = countA > countB ? headB : headA;
        int countL = abs(countA - countB);
        
        while(countL--)
        {
            pL = pL->next;
        }

        while(pL)
        {
            if(pL == pS)
            {
                return pL;
            }
            pL = pL->next;
            pS = pS->next;
        }
        return nullptr;
    }
};

/*
    哈希表法
    把一条链放进哈希表
    另一条链顺序对照  第一个有相同的节点 即所求     
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
            return nullptr;
        set<ListNode*> hash;
        ListNode *pCur = headA;
        while(pCur)
        {
            hash.insert(pCur);
            pCur = pCur->next;
        }

        pCur = headB;
        while(pCur)
        {
            if(hash.end() != hash.find(pCur))
                return pCur;
            pCur = pCur->next;
        }
        return nullptr;
    }
};


//  自己思路写的   为啥效率这么低？
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
            return nullptr;

        set<ListNode*> hash;
        
        while(headA || headB)
        {
            if(headA)
            {
                if(hash.end() == hash.find(headA))
                {
                    hash.insert(headA);
                    headA = headA->next;
                }
                else{
                    return headA;
                }
            }
            if(headB)
            {
                if (hash.end() == hash.find(headB))
                {
                    hash.insert(headB);
                    headB = headB->next;
                }
                else
                {   
                    return headB;
                }
            }
        }
        return nullptr;
    }
};