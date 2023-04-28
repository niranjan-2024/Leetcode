class DisjointSet {
    public:
    vector<int> rank, parent, size; 
    DisjointSet(int n) {
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

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 

class Solution {
public:
    
    bool isSimilar(string &a,string &b){
        if(a.size() != b.size()){
            return false;
        }
        
        int swaps = 0;
        
        for(int i=0;i<a.size();i++){
            if(a[i] != b[i]){
                swaps++;
            }
            if(swaps>2){
                return false;
            }
        }
        
        return true;
    }
    
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        DisjointSet dsu(n);
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isSimilar(strs[i],strs[j])){
                    dsu.unionBySize(i,j);
                }
            }
        }
        
        int ans = 0;
        
        for(int i=0;i<n;i++){
            if(dsu.parent[i] == i){
                ans++;
            }
        }
        
        return ans;
    }
};