/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 // 方法1：将值复制到数组中，然后双指针
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vals;
        while (head != nullptr)
        {
            vals.emplace_back((head->val));
            head = head->next;
        }
        for(int i = 0, j = vals.size() - 1; i < j; ++i,--j)
        {
            if(vals[i] != vals[j])
            {
                return false;
            }
        }
        return true;
    }
};

 // 方法2：递归
class Solution {
    private:
    ListNode* frontPointer;
public:
    bool check(ListNode* currentNode)
    {
        if(currentNode != nullptr)
        {
            if(!check(currentNode->next))
            {
                return false;
            }
            if(currentNode->val != frontPointer->val)
            {
                return false;
            }
            frontPointer = frontPointer->next;
        }
    return true;
    }
    bool isPalindrome(ListNode* head) {
        frontPointer = head;
        return check(head);
    }
};

//O(n) 时间复杂度和 O(1) 空间复杂度 的解法
// 方法3：快慢指针
 /*
    1.先用快慢指针找中间点
    2.用反转指针反转后半部分
    3.比较两部分值
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr)
            return true;
         // 找到前半部分链表的尾节点并反转后半部分链表
        ListNode *firstHalf = findHalf(head);
        ListNode *secondHalf = reverseList(firstHalf->next);
    
        ListNode *p1 = head;
        ListNode *p2 = secondHalf;
        bool res = true;
        while(res && p2 != nullptr)
        {
            if(p1->val != p2->val)
                res = false;
            p1 = p1->next;
            p2 = p2->next;
        }
        // 还原链表
        firstHalf->next = reverseList(secondHalf);
        return res;
    }

    // 反转链表
    ListNode* reverseList(ListNode* head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while(curr != nullptr)
        {
            ListNode *nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;            
        }
        return prev;
    }

    // 快慢指针找中点
    ListNode* findHalf(ListNode* head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast->next != nullptr &&fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }    
        return slow;
    }    
};
// @lc code=end

