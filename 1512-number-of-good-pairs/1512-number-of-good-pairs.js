/**
 * @param {number[]} nums
 * @return {number}
 */
var numIdenticalPairs = function(nums) {
    const object = {};
    let ans = 0;
    
    for(const num of nums){
        if(object[num]){
            ans += object[num];
            object[num] += 1
        }
        else{
            object[num] = 1;
        }
    }
    
    return ans;
};