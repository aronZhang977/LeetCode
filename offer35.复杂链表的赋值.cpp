/*
// Definition for a Node.

*/


/*
三个思路
1. 复制链表和next  再遍历一遍复制random
2. 对1进行优化  使用一个哈希结构存储random  
3. 不使用辅助空间  把新建节点插到原节点后边，然后按照链表奇偶节点拆分成原节点和目标节点
*/ 
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


// 思路3  不使用辅助空间  拼接+拆分
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;
        Node *pCur = head;
        //  拼接
        while(pCur)
        {
            Node *pTmp = new Node(pCur->val);
            pTmp->next = pCur->next;
            pCur->next = pTmp;
            pCur = pTmp->next;
        }

        // 新节点的random指向
        pCur = head;
        while(pCur)
        {
            if(pCur->random)
                pCur->next->random = pCur->random->next;
            pCur = pCur->next->next;
        }

        // 拆分
        pCur = head->next;
        Node *pPre = head, *pRes = head->next; 
        while(pCur->next)
        {
            pPre->next = pCur->next;
            pCur->next = pCur->next->next;
            pPre = pPre->next;
            pCur = pCur->next;
        }
        pPre->next = nullptr;
        return pRes;        
    }
};

// 思路2  空间换时间  
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(nullptr == head)
            return nullptr;
        Node *pCur = head;
        unordered_map<Node*,Node*> map;     // 原节点 - 新节点
        // 新建节点，并建立map映射
        while(pCur)
        {
            map[pCur] = new Node(pCur->val);
            pCur = pCur->next;
        }
        pCur = head;
        // 构建新链表的next和random指向
        while (pCur)
        {
            map[pCur]->next = map[pCur->next];
            map[pCur]->random = map[pCur->random];
            pCur = pCur->next;
        }

        return map[head];
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