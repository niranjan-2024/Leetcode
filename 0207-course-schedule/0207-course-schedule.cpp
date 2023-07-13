class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int N = numCourses;
        vector<int> adj[N];
	    for(auto it : prerequisites){
	        adj[it[1]].push_back(it[0]);
	    }
	    
	    int indegree[N];
        for(int i=0;i<N;i++){
            indegree[i] = 0;
        }
        
	    for(int i=0;i<N;i++){
	        for(auto j : adj[i]){
	            indegree[j]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0;i<N;i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    int count = 0;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
            count++;
	        
	        for(auto neighbour:adj[node]){
	            indegree[neighbour]--;
	            if(indegree[neighbour] == 0){
	                q.push(neighbour);
	            }
	        }
	    }
	    
	    if(count == N){
	        return true;
	    }
	    return false;
    }
};