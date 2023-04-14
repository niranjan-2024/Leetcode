/**
 * @param {any} o1
 * @param {any} o2
 * @return {boolean}
 */
var areDeeplyEqual = function(o1, o2) {
    if(o1 === o2){
        return true;
    }
    
    if(typeof o1 !== 'object' || o1 === null || typeof o2 !== 'object' || o2 === null){
        return false;
    }
    
    if(Array.isArray(o1) !== Array.isArray(o2)){
        return false;
    }
    
    const k1 = Object.keys(o1);
    const k2 = Object.keys(o2);
    
    if(k1.length !== k2.length){
        return false;
    }
    
    return k1.every(key => k2.includes(key) && areDeeplyEqual(o1[key],o2[key]));
};