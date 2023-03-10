class Solution {
public:
    int nextGreaterElement(int n) {
        string nums = to_string(n);
        next_permutation(nums.begin(),nums.end());
        auto ans = stoll(nums);
        return (ans>INT_MAX || ans<=n) ? -1 : ans;
    }
};