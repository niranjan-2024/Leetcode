class Solution {
public:
    
    bool isValid(vector<int> &dist,int speed,double hour){
        double time = 0;
        
        for(int i=0;i<dist.size();i++){
            time = ceil(time);
            time += (double)dist[i]/speed;
            
            if(time>hour){
                return false;
            }
        }
        
        return true;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if(hour < dist.size()-1){
            return -1;
        }
        
        long left=1 , right=1e7;
        
        while(left <= right){
            long mid = (left+right)/2;
            
            if(isValid(dist,mid,hour)){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        
        return left > 1e7 ? -1 : left;
    }
};