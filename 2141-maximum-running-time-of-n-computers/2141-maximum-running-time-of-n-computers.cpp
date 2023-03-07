class Solution {
public:
    
    bool isPossible(long long int n,vector<int>& batteries,long long int avg){
        long long int duration = 0;
        for(int ele : batteries){
            if(ele<avg){
                duration += ele;
            }
            else{
                duration += avg;
            }
        }
        
        return duration >= avg*n;
    }
    
    long long maxRunTime(int n, vector<int>& batteries) {
        
        
        long long int start = 0;
        long long int end = 0;
        
        for(int ele:batteries){
            end+=ele;
        }
        
        while(start<=end){
            long long avg = start + (end-start)/2;
            if(isPossible(n,batteries,avg)){
                start = avg+1;
            }
            else{
                end = avg-1;
            }
        }
        
        return start-1;
    }
};