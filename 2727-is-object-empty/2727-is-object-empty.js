/**
 * @param {Object | Array} obj
 * @return {boolean}
 */
var isEmpty = function(obj) {
    for(const it in obj){
        return false;
    }
    
    return true;
};