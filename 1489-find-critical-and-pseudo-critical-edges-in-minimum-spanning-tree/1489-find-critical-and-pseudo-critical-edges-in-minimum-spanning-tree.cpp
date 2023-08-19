class DSU{
    public:
    vector<int> parent,rank;
    
    DSU(int n){
        parent.resize(n,0);
        rank.resize(n,0);
        
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    
    int Find(int x){
        return parent[x] = parent[x] == x ? x : Find(parent[x]);
    }
    
    bool Union(int x,int y){
        int xParent = Find(x);
        int yParent = Find(y);
        
        if(xParent != yParent){
            rank[xParent] < rank[yParent] ? parent[xParent] = yParent : parent[yParent] = xParent;
            rank[xParent] += rank[xParent] == rank[yParent];
            return true;
        }
        
        return false;
    }
};

class Solution {
public:
    
    int getMST(int n,vector<vector<int>> &edges,int excludeEdge = -1,int includeEdge = -1){
        DSU dsu(n);
        int weight = 0;
        
        if(includeEdge != -1){
            weight += edges[includeEdge][2];
            dsu.Union(edges[includeEdge][0],edges[includeEdge][1]);
        }
        
        for(int i=0;i<edges.size();i++){
            if(i == excludeEdge){
                continue;
            }
            
            auto &edge = edges[i];
            if(dsu.Find(edge[0]) == dsu.Find(edge[1])){
                continue;
            }
            
            dsu.Union(edge[0],edge[1]);
            weight += edge[2];
        }
        
        for(int i=0;i<n;i++){
            if(dsu.Find(i) != dsu.Find(0)){
                return 1e9+7;
            }
        }
        
        return weight;
    }
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i=0;i<edges.size();i++){
            edges[i].push_back(i);
        }
        
        sort(edges.begin(),edges.end(),[](const vector<int> &a,const vector<int> &b){
           return a[2] < b[2]; 
        });
        
        int original_mst = getMST(n,edges,-1);
        
        vector<int> critical,non_critical;
        
        for(int i=0;i<edges.size();i++){
            if(original_mst < getMST(n,edges,i)){
                critical.push_back(edges[i][3]);
            }
            else if(original_mst == getMST(n,edges,-1,i)){
                non_critical.push_back(edges[i][3]);
            }
        }
        
        return {critical,non_critical};
    }
};