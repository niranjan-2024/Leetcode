class DSU{
    
    public:
    vector<int> parent;
    
    DSU(int n){
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    
    int findParent(int u){
        if(u == parent[u]){
            return u;
        }
        return findParent(parent[u]);
    }
    
    void Union(int u,int v){
        if(findParent(u) == findParent(v)){
            return;
        }
        parent[findParent(u)] = parent[findParent(v)];
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int,pair<int,int>>> v;
        
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                v.push_back({abs(points[i][1]-points[j][1])+abs(points[i][0]-points[j][0]),{i,j}});
            }
        }
        
        DSU d(points.size());
        sort(v.begin(),v.end());
        int costOfConnecting = 0;
        
        for(auto it:v){
            if(d.findParent(it.second.first) != d.findParent(it.second.second)){
                costOfConnecting += it.first;
                d.Union(it.second.first,it.second.second);
            }
        }
        
        return costOfConnecting;
    }
};