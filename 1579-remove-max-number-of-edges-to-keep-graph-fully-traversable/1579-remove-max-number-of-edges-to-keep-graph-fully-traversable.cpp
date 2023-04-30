class DisjointSet {
    public:
    vector<int> rank, parent, size; 
    int nodes;
    
    DisjointSet(int n) {
        nodes = n;
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    int unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return 0; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
        nodes--;
        return 1;
    }
    
    bool isConnected(){
        return nodes == 1;
    }
}; 

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet alice(n);
        DisjointSet bob(n);
        
        int edgesRequired = 0;
        
        for(vector<int> &edge:edges){
            if(edge[0] == 3){
                edgesRequired += (alice.unionBySize(edge[1],edge[2]) | bob.unionBySize(edge[1],edge[2]));
            }
        }
        
        for(vector<int> &edge:edges){
            if(edge[0] == 1){
                edgesRequired += alice.unionBySize(edge[1],edge[2]);
            }
            else if(edge[0] == 2){
                edgesRequired +=  bob.unionBySize(edge[1],edge[2]);
            }
        }
        
        if(alice.isConnected() && bob.isConnected()){
            return edges.size() - edgesRequired;
        }
        
        return -1;
    }
};