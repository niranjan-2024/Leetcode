class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        sort(begin(meetings), end(meetings));
        
        vector<int> meetsCount(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> occupied;
        priority_queue<int, vector<int>, greater<int>> empty;
        
        for(int i=0; i<n; i++){
            empty.push(i);
        }
        
        for(auto& meet : meetings) {
            
            long long currTime = meet[0];
            
            while(occupied.size()) {
                if(currTime < occupied.top().first){
                    break;
                }

                auto [time, room] = occupied.top();
                occupied.pop();
                empty.push(room);
            }
            
            int roomNum = -1;
            
            if(empty.size()) {
                roomNum = empty.top();
                empty.pop();
                occupied.push({ meet[1], roomNum });
            }
            else if(occupied.size()) {
                auto [time, room] = occupied.top();
                occupied.pop();   
                
                roomNum = room;
                
                long long endTime = time + meet[1] - meet[0];
                
                occupied.push({endTime, roomNum});
            }
            
            if(roomNum != -1){
                meetsCount[roomNum]++;
            }
        }
        
        int idx = -1, maxVal = 0;
        
        for(int i=0; i<n; i++) {
            if(meetsCount[i] > maxVal) {
                idx = i;
                maxVal = meetsCount[i];
            }    
        }
        
        return idx;
    }
};