/**
 * @param {string} word1
 * @param {string} word2
 * @return {string}
 */
var mergeAlternately = function(word1, word2) {
    let ans = "";
    
    let minLength = Math.min(word1.length,word2.length);
    for(let i=0;i<minLength;i++){
        ans += word1[i];
        ans += word2[i];
    }
    
    if(word1.length > word2.length){
        ans += word1.substring(minLength,word1.length+1);
    }
    else{
        ans += word2.substring(minLength,word2.length+1);
    }
    
    return ans;
};