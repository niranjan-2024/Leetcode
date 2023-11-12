class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target){
            return 0;
        }
        
        unordered_map<int,unordered_set<int>> graph;
        for(int i=0;i<routes.size();i++){
            for(auto stations : routes[i]){
                graph[stations].insert(i);
            }
        }
        
        unordered_set<int> visited;
        queue<int> q;
        
        for(auto route:graph[source]){
            q.push(route);
            visited.insert(route);
        }
        
        int leastDist = 1;
        
        while(q.size()){
            int size = q.size();
            
            for(int i=0;i<size;i++){
                int route = q.front();
                q.pop();
                
                int startingStop = -1;
                
                for(auto busStop : routes[route]){
                    if(startingStop == -1){
                        startingStop = busStop;
                    }
                    else if(startingStop == busStop){
                        break;
                    }
                    
                    if(busStop == target){
                        return leastDist;
                    }
                    
                    for(auto possible_routes : graph[busStop]){
                        if(!visited.count(possible_routes)){
                            visited.insert(possible_routes);
                            q.push(possible_routes);
                        }
                    }
                }
            }
            
            leastDist++;
        }
        
        return -1;
    }
};
















