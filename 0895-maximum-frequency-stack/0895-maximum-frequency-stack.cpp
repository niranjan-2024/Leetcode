class FreqStack {
public:
    
    unordered_map<int,int> frequency;
    unordered_map<int,stack<int>> same_frequency_stack;
    int max_frequency = 0;
    
    FreqStack() {}
    
    void push(int val) {
        frequency[val]++;
        max_frequency = max(max_frequency,frequency[val]);
        same_frequency_stack[frequency[val]].push(val);
    }
    
    int pop() {
        int most_frequent_top_element = same_frequency_stack[max_frequency].top();
        same_frequency_stack[max_frequency].pop();
        
        frequency[most_frequent_top_element]--;
        
        if(same_frequency_stack[max_frequency].size() == 0){
            max_frequency--;
        }
        
        return most_frequent_top_element;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */