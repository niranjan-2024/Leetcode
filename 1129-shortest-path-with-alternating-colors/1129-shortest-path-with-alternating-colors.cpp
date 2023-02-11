class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> adj(n);
        
        for(auto redEdge : redEdges){
            adj[redEdge[0]].push_back({redEdge[1],0});
        }
        
        for(auto blueEdge : blueEdges){
            adj[blueEdge[0]].push_back({blueEdge[1],1});
        }
        
        vector<int> answer(n,-1);
        vector<vector<bool>> visited(n,vector<bool>(2));
        queue<vector<int>> q;
        
        q.push({0,0,-1});
        visited[0][1] = visited[0][0] = true;
        answer[0] = 0;
        
        while(!q.empty()){
            auto front = q.front();
            int node = front[0];
            int steps = front[1];
            int prevColor = front[2];
            q.pop();
            
            for(auto &[neighbour,color] : adj[node]){
                if(!visited[neighbour][color] && color != prevColor){
                    visited[neighbour][color] = true;
                    q.push({neighbour,steps+1,color});
                    if(answer[neighbour] == -1){
                        answer[neighbour] = steps + 1;
                    }
                }
            }
        }
        
        return answer;
    }
};