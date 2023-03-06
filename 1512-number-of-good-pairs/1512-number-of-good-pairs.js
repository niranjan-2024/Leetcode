/**
 * @param {number[]} nums
 * @return {number}
 */
var numIdenticalPairs = function(nums) {
    const mapq = {};
    let ans = 0;
    
    for(const num of nums){
        if(mapq[num]){
            ans += mapq[num];
            mapq[num] += 1;
        }
        else{
            mapq[num] = 1;
        }
    }
    
    return ans;
};