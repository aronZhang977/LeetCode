class MinStack {
public:
    stack<int> stk;
    stack<int> min_stk;
    /** initialize your data structure here. */
    MinStack() {
        min_stk.push(INT_MAX);
    }
    
    void push(int x) {
        stk.push(x);
        min_stk.push(::min(min_stk.top(),x));
    }
    
    void pop() {
        stk.pop();
        min_stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int min() {
        return min_stk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */