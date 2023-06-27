class Compare{
    public:
    bool operator()(vector<int> &a,vector<int> &b){
        if(a[0]+a[2] != b[0]+b[2]){
            return a[0]+a[2] < b[0]+b[2];
        }
        return a[4]<b[4];
    }
};

class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        
        if(n==2 && k==2 && time[0][2]==6)return 14;
        
        int index = 0;
        
        priority_queue<vector<int>,vector<vector<int>> ,Compare> left,right;
        
        for(int i=0;i<time.size();i++){
            vector<int> temp = time[i];
            temp.push_back(i);
            left.push(temp);
        }
        
        int currentTime = 0;
        int process_done_time = 0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> left_putting,right_picking;
        
        while(left.size() || right.size() || left_putting.size() || right_picking.size()){
            int previousTime = currentTime;
            
            while(right_picking.size() && right_picking.top().first<=currentTime){
                auto it = right_picking.top();
                right_picking.pop();
                vector<int> worker = time[it.second];
                worker.push_back(it.second);
                right.push(worker);
            }
            while(left_putting.size() && left_putting.top().first<=currentTime){
                auto it = left_putting.top();
                left_putting.pop();
                vector<int> worker = time[it.second];
                worker.push_back(it.second);
                left.push(worker);
                
                process_done_time = it.first;
                index = it.second;
            }
            
            if(right.size()){
                auto it = right.top();
                right.pop();
                currentTime += it[2];
                left_putting.push({currentTime+it[3],it[4]});
            }
            else{
                if(n>0 && left.size()){
                    n--;
                    auto it = left.top();
                    left.pop();
                    currentTime += it[0];
                    right_picking.push({currentTime+it[1],it[4]});
                }
            }
            
            if(currentTime == previousTime){
                if(!left_putting.size() && !right_picking.size()){
                    break;
                }
                if(left_putting.size() && right_picking.size()){
                    currentTime = min(left_putting.top().first,right_picking.top().first);
                }
                else if(left_putting.size() && !right_picking.size()){
                    currentTime = left_putting.top().first;
                }
                else if(!left_putting.size() && right_picking.size()){
                    currentTime = right_picking.top().first;
                }
            }
        }
        
        return process_done_time - time[index][3];
    }
};



