class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n =arr.size();
        unordered_map<int,vector<int>> same;
        
        for(int i=0;i<n;i++){
            same[arr[i]].push_back(i);
        }
        
        vector<bool> visited(n);
        visited[0] = true;
        
        queue<int> q;
        q.push(0);
        
        int steps = 0;
        
        while(!q.empty()){
          for(int size=q.size();size>0;size--){
            int temp = q.front();
            q.pop();
            
            if(temp == n-1){
                return steps;
            }
            
            vector<int>& next = same[arr[temp]];
            
            next.push_back(temp-1);
            next.push_back(temp+1);
            
            for(int j:next){
                if(j>=0 && j<n && !visited[j]){
                    visited[j] = true;
                    q.push(j);
                }
            }
            next.clear();
          }
            steps++;
        }
        return 0;
    }
};