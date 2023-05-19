class Graph {
public:
    
    unordered_map<int,vector<pair<int,int>>> graph;
    int nodes;
    
    Graph(int n, vector<vector<int>>& edges) {
        for(auto it:edges){
            graph[it[0]].push_back({it[1],it[2]});
        }
        nodes = n;
    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,node1});
        
        vector<int> distance(nodes+1,1e9);
        distance[node1] = 0;
        
        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto neighbour:graph[node]){
                if(dist + neighbour.second < distance[neighbour.first]){
                    distance[neighbour.first] = dist + neighbour.second;
                    pq.push({distance[neighbour.first],neighbour.first});
                }
            }
        }
        
        if(distance[node2] == 1e9){
            return -1;
        }
        else{
            return distance[node2];
        }
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */