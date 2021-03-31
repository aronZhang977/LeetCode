/*
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

 

示例 1：

输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
示例 2：

输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
*/

class CQueue {
private:
    stack<int> m_stk1, m_stk2;
public:
    CQueue() 
    {
        while(!m_stk1.empty())
            m_stk1.pop();
        while(!m_stk2.empty())
            m_stk2.pop();
    }
    //  这个地方要考虑边进边出
    void appendTail(int value) {
        while(!m_stk2.empty())
        {
            m_stk1.push(m_stk2.top());
            m_stk2.pop();
        }
        m_stk1.push(value);
    }
    
    int deleteHead() {
        if(m_stk1.empty())
            return -1;
        int delete_val = m_stk2.top();
        while (!m_stk1.empty())
        {
            m_stk2.push(m_stk1.top());
            m_stk1.pop();            
        }
        m_stk2.pop();

        return delete_val
    }}; 

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

