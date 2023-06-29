class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int x = -1;
        int y = -1;
        int n = grid.size();
        int m = grid[0].size();
        int max_len = -1;
        int steps = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char ch = grid[i][j];
                if(ch == '@'){
                    x = i;
                    y = j;
                }
                if(ch>='a' && ch<='f'){
                    max_len = max(ch-'a'+1,max_len);
                }
            }
        }
        
        vector<int> start = {0,x,y};
        
        queue<vector<int>> q;
        q.push(start);
        
        unordered_set<string> visited;
        visited.insert(to_string(0)+" "+to_string(x)+" "+to_string(y));
        
        vector<vector<int>> dirs {{-1,0},{1,0},{0,1},{0,-1}};
        
        while(!q.empty()){
            int size = q.size();
            
            for(int k=0;k<size;k++){
                vector<int> curr = q.front();
                q.pop();
                
                if(curr[0] == (1<<max_len)-1){
                    return steps;
                }
                
                for(auto &d : dirs){
                    int newI = curr[1] + d[0];
                    int newJ = curr[2] + d[1];
                    int keys = curr[0];
                    
                    if(newI>=0 && newI<n && newJ>=0 && newJ<m){
                        char ch = grid[newI][newJ];
                        
                        if(ch == '#'){
                            continue;
                        }
                        if(ch>='a' && ch<='f'){
                            keys |= 1<<(ch-'a');
                        }
                        if(ch >= 'A' && ch <= 'F' && ((keys>>(ch-'A'))&1) == 0){
                            continue;
                        }
                        if(!visited.count(to_string(keys)+" "+to_string(newI)+" "+to_string(newJ))){
                            visited.insert(to_string(keys)+" "+to_string(newI)+" "+to_string(newJ));
                            q.push({keys,newI,newJ});
                        }
                    }
                }
            }
            
            steps++;
        }
        
        return -1;
    }
};