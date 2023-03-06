/**
 * @param {number[]} nums
 * @return {number}
 */
var numIdenticalPairs = function(nums) {
    const map = {};
    let ans = 0;
    
    for(let num of nums){
        if(map[num]){
            ans += map[num];
            map[num] += 1;
        }
        else{
            map[num] = 1;
        }
    }
    
    return ans;
};