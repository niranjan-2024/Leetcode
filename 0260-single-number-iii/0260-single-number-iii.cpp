class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long int xorOfTwoSingles = accumulate(nums.begin(),nums.end(),0,bit_xor<int>());
        
        long long int differenceInBitsOfSingles = ((xorOfTwoSingles)&(-xorOfTwoSingles));
        
        vector<int> result = {0,0};
        
        for(int num : nums){
            if((num & differenceInBitsOfSingles) == 0){
                result[0] = result[0]^num;
            }
            else{
                result[1] = result[1]^num;
            }
        }
        
        return result;
    }
};