/**
 * @param {string} s
 * @param {string} goal
 * @return {boolean}
 */
var rotateString = function(s, goal) {
    const str = goal+goal;
    if(s === str){
        return false;
    }
    if(str.includes(s)){
        return true;
    }
    return false;
};