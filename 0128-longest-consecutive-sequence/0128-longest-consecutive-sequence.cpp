class Solution {
public:
    int longestConsecutive(vector<int> &A) {
        int n = A.size();

        unordered_map<int, int> mpp; 
        int length = 0;

        for(int &i: A){
            if(mpp.find(i) != mpp.end()) continue;    
            mpp[i] = 1; 
            int total = 1;  

            if(mpp.find(i-1) != mpp.end() && mpp.find(i+1) != mpp.end()){
                total = mpp[i-1] + mpp[i+1] + 1;
                mpp[i - mpp[i-1]] = total;
                mpp[i + mpp[i+1]] = total;
            }
            else if(mpp.find(i-1) != mpp.end()){    
                total = mpp[i-1] + 1;
                mpp[i - mpp[i-1]] = total;
                mpp[i] = total;
            }
            else if(mpp.find(i+1) != mpp.end()){    
                total = mpp[i+1] + 1;
                mpp[i + mpp[i+1]] = total;
                mpp[i] = total;
            }

            length = max(length, total);
        }
        
        return length;
    }
};