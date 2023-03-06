/**
 * @param {number[]} nums
 * @return {number[]}
 */
var smallerNumbersThanCurrent = function(nums) {
    let ordered = [...nums].sort((a,b)=>a-b);
    let maping = {};
    let ans = [];
    
    for(let i=0;i<ordered.length;i++){
        if(ordered[i] == ordered[i-1]) continue;
        maping[ordered[i]] = i;
    }
    
    for(let i=0;i<nums.length;i++){
        ans[i] = maping[nums[i]];
    }
    
    return ans;
};