class MinStack {
public:
    stack<int> minElements;
    stack<int> minstack;
    
    MinStack() {
    }
    
    void push(int val) {
        if(minElements.empty() || minElements.top() >= val) minElements.push(val);
        minstack.push(val);
    }
    
    void pop() {
        if(minElements.top() == minstack.top()) minElements.pop();
        minstack.pop();
    }
    
    int top() {
        return minstack.top();
    }
    
    int getMin() {
        return minElements.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
