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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }
        
        sort(queries.begin(),queries.end(),[](auto &first,auto &second){
          return first[2] < second[2];   
        });
        
        sort(edgeList.begin(),edgeList.end(),[](auto &first,auto &second){
          return first[2] < second[2];   
        });
        
        DisjointSet dsu(n);
        vector<bool> result(queries.size());
        
        int i = 0;
        
        for(vector<int> &q:queries){
            while(i<edgeList.size() && edgeList[i][2]<q[2]){
                dsu.unionBySize(edgeList[i][0],edgeList[i][1]);
                i++;
            }
            
            result[q[3]] = dsu.findUPar(q[0]) == dsu.findUPar(q[1]);
        }
        
        return result;
    }
};