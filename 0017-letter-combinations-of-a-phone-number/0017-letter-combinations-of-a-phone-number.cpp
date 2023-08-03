class Solution {
public:
    
    vector<string> mp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }

        vector<string> result;
        result.push_back("");

        for(auto digit:digits){
            vector<string> temp;
            for(auto c : mp[digit - '0']){
                for(auto s:result){
                    temp.push_back(s+c);
                }
            }

            result.swap(temp);
        }

        return result;
    }
};