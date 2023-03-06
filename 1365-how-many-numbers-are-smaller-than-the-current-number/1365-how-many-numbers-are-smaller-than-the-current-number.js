/**
 * @param {number[]} nums
 * @return {number[]}
 */
var smallerNumbersThanCurrent = function(nums) {
    let sorted = [...nums].sort((a,b)=>a-b);
    let map = {};
    let result = [];
    
    for(let i=0;i<sorted.length;i++){
        if(sorted[i] == sorted[i-1]) continue;
        map[sorted[i]] = i;
    }
    
    for(let i=0;i<sorted.length;i++){
        result[i] = map[nums[i]];
    }
    
    return result;
};