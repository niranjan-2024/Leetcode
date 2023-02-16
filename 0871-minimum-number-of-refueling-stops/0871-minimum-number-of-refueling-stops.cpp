class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int n = stations.size();
        
        if(startFuel >= target){
            return 0;
        }
        
        if(n != 0 && startFuel >= stations[0][0]){
            long long checkFuel = startFuel;
            int fuelings = 0;
            
            for(int i=0;i<stations.size();i++){
                if(checkFuel < stations[i][0]){
                    return -1;
                }
                checkFuel += stations[i][1];
            }
            
            if(target > checkFuel){
                return -1;
            }
            
            int index = 0;
            int result;
            priority_queue<int> pq;
            
            for(result = 0;startFuel<target;result++){
                while(index<n && startFuel>=stations[index][0]){
                    pq.push(stations[index++][1]);
                }
                
                startFuel += pq.top();
                pq.pop();
            }
            
            return result;
        }
        
        return -1;
    }
};