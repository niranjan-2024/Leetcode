class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vector<pair<int,double>>> adjList(n);
        for(int i=0;i<edges.size();i++){
            adjList[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adjList[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        
        vector<int> visited(n,0);
        
        vector<double> maxAns(n,(double)0.0);
        maxAns[start] = 1.0;
        
        priority_queue<pair<double,int>> pq;
        pq.push({(double)1.0,start});
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            double probability = it.first;
            int node = it.second;
            
            if(!visited[node]){
                visited[node] = 1;
                
                for(auto &adjacentNode:adjList[node]){
                    if(maxAns[adjacentNode.first] < adjacentNode.second*probability){
                        maxAns[adjacentNode.first] = adjacentNode.second*probability;
                        pq.push({maxAns[adjacentNode.first],adjacentNode.first});
                    }
                }
            }
        }
        
        return maxAns[end];
    }
};