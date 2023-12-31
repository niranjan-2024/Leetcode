class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int res = INT_MIN;
        
        for(int i = 0;i<s.size();i++)
        {
            char a = s[i];
            for(int j=i+1;j<s.size();j++)
            {
                if(a==s[j])
                {
                    res = max(res,(j-i-1));
                }
            }
        }

        return max(res,-1);
    }
};