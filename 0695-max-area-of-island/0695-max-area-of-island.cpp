class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
   
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
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
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int dr[] = {1,0,-1,0};
        int dc[] = {0,-1,0,1};
        
        DisjointSet ds(n*m);
        int max_area = 0;
        
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                int Node = row*m+col;
                
                if(grid[row][col] == 1){
                    for(int i=0;i<4;i++){
                        int newRow = row+dr[i];
                        int newCol = col+dc[i];
                        
                        if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && grid[newRow][newCol]==1){
                            int adjacentNode = newRow*m+newCol;
                            
                            if(ds.findUPar(adjacentNode) != ds.findUPar(Node)){
                                ds.unionBySize(Node,adjacentNode);
                            }
                        }
                    }
                }
                else{
                    ds.size[Node] = 0;
                }
            }
        }
        
        for(int i=0;i<n*m;i++){
            max_area = max(max_area,ds.size[ds.findUPar(i)]);
        }
        
        return max_area;
    }
};