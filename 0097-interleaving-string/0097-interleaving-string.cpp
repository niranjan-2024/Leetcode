class Solution {
public:
    
    unordered_map<string, bool> memo;

    bool solve(string &s1, string &s2, string &s3, int l1, int l2, int l3) {
        if (l1 < 0 && l2 < 0 && l3 < 0) {
            return true;
        }

        string key = to_string(l1) + "#" + to_string(l2) + "#" + to_string(l3);

        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        bool result = false;

        if (l1 >= 0 && s1[l1] == s3[l3] && l2 >= 0 && s2[l2] == s3[l3]) {
            result = solve(s1, s2, s3, l1 - 1, l2, l3 - 1) || solve(s1, s2, s3, l1, l2 - 1, l3 - 1);
        } else if (l1 >= 0 && s1[l1] == s3[l3]) {
            result = solve(s1, s2, s3, l1 - 1, l2, l3 - 1);
        } else if (l2 >= 0 && s2[l2] == s3[l3]) {
            result = solve(s1, s2, s3, l1, l2 - 1, l3 - 1);
        }

        memo[key] = result;

        return result;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length();
        int l2 = s2.length();
        int l3 = s3.length();
        
        if(l3 != l1+l2){
            return false;
        }
        
        return solve(s1,s2,s3,l1-1,l2-1,l3-1);
    }
};