class MinStack {
public:
    vector<int> stack;
    int ptr;
    
    MinStack() {
        ptr=0;
    }
    
    void push(int val) {
        ptr++;
        stack.push_back(val);
    }
    
    void pop() {
        ptr--;
        stack.pop_back();
    }
    
    int top() {
        return stack[stack.size()-1];
    }
    
    int getMin() {
        int min = INT_MAX;
        
        for(int i=0;i<stack.size();i++)
            if(stack[i]<=min) min = stack[i];
        
        return min;
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