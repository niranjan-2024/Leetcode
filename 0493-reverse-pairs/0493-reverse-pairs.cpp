#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        pbds set;
        int n = nums.size();
        int ans = 0;

        for(int i=n-1;i>=0;i--){
            if(nums[i]%2 == 0){
                int count = set.order_of_key(nums[i]/2);
                ans += count;
            }
            else{
                int count = set.order_of_key(((long long)nums[i]+1)/2);
                ans += count;
            }
            set.insert(nums[i]);
        }

        return ans;
    }
};