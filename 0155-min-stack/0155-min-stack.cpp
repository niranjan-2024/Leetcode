class MinStack {
public:
    
    vector<int> st;
    vector<int> mini;
    
    MinStack() {}
    
    void push(int val) {
        st.push_back(val);
        if(mini.size() == 0 || val<=mini.back()){
            mini.push_back(val);
        }
    }
    
    void pop() {
        if(st.back() == mini.back()){
            mini.pop_back();
        }
        st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return mini.back();
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