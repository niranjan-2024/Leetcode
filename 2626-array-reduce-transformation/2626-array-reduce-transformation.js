/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    if(nums.length){
        nums.forEach((x)=>{
            init = fn(init,x);
        });
    }
    
    return init;
};