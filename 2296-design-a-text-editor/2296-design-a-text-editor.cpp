class TextEditor {
public:
    
    stack<char> left;
    stack<char> right;
    
    TextEditor() {}
    
    void addText(string text) {
        for(auto &ch : text){
            left.push(ch);
        }
    }
    
    int deleteText(int k) {
        int count_deleted = 0;
        
        while(!left.empty() && k>0){
            left.pop();
            count_deleted++;
            k--;
        }
        
        return count_deleted;
    }
    
    string cursorLeft(int k) {
        while(!left.empty() && k>0){
            char ch = left.top();
            left.pop();
            right.push(ch);
            k--;
        }
        
        return cursor_shift();
    }
    
    string cursorRight(int k) {
        while(!right.empty() && k>0){
            char ch = right.top();
            right.pop();
            left.push(ch);
            k--;
        }
        
        return cursor_shift();
    }
    
    string cursor_shift(){
        string ans = "";
        int countMax = 10;
        
        while(!left.empty() && countMax>0){
            char ch = left.top();
            left.pop();
            ans += ch;
            countMax--;
        }
        
        reverse(ans.begin(),ans.end());
        
        for(auto ch:ans){
            left.push(ch);
        }
        
        return ans;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */