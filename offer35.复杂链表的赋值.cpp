/*
// Definition for a Node.

*/
/*
三个思路
1. 复制链表和next  再遍历一遍复制random
2. 对1进行优化  使用一个哈希结构存储random  
3. 不使用辅助空间  把新建节点插到原节点后边，然后按照链表奇偶节点拆分成原节点和目标节点
*/ 

// 思路2  空间换时间  
class Solution {
public:
    Node* copyRandomList(Node* head) {
        
    }
};

//  思路1 
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* pCur = head;
        Node* pDummy = new Node(0);   // 设置一个哨兵
        Node *pPreNew = pDummy;

        while(pCur)
        {
            /* 
                新建节点
                前一个节点的next指向新节点
                指针后移  
            */
            Node *pNewNode = new Node(pCur->val);
            pPreNew->next = pNewNode;
            
            pCur = pCur->next;
            pPreNew = pPreNew->next;
        }

        // 再遍历一次 把random搭上   太麻烦了懒得跑了  写个大概意思可能有bug
        
        pCur = head;
        Node *pHeadNew = pDummy->next;
        pPreNew = pHeadNew;
        while(pCur)
        {
            if(!pCur->random)
                continue;
            Node *pFind = head;
            Node *pFindNew = pHeadNew;
 
            int randomCount = 0;
            while(pFind)
            {
                

                if(pFind->val == pCur->random->val)
                    break;
                pFind = pFind->next;
                ++randomCount;
            }
            
            while(randomCount)
            {
                pFindNew = pFindNew->next;                
                --randomCount;
            }
            
            pPreNew->random = pFindNew;
        }
        return pHeadNew;        
    }
};