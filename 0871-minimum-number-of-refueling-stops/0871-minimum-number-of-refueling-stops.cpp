class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int n = stations.size();
        
        if(startFuel >= target){
            return 0;
        }
        
        if(n != 0 && startFuel >= stations[0][0]){            
            int index = 0;
            int result;
            priority_queue<int> pq;
            
            for(result = 0;startFuel<target;result++){
                while(index<n && startFuel>=stations[index][0]){
                    pq.push(stations[index++][1]);
                }
                
                if(pq.empty()){
                    return -1;
                }
                
                startFuel += pq.top();
                pq.pop();
            }
            
            return result;
        }
        
        return -1;
    }
};