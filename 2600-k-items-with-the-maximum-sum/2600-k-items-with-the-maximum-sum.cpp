class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        return min(k,numOnes) - max(0,k-numZeros-numOnes);
    }
};