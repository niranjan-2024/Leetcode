class Solution {
public:
    
    unordered_map<string, unordered_map<string,double>> buildGraph(vector<vector<string>>& equations,vector<double>& values){
        unordered_map<string, unordered_map<string,double>> graph;
        
        for(int i=0;i<equations.size();i++){
            string dividend = equations[i][0];
            string divisor = equations[i][1];
            double value = values[i];
            
            graph[dividend][divisor] = value;
            graph[divisor][dividend] = 1.0/value;
        }
        
        return graph;
    }
    
    void dfs(string start,string &destination,unordered_map<string, unordered_map<string,double>> &graph,unordered_set<string> &visited,double &ans_query,double temp){
        if(visited.find(start) != visited.end()){
            return;
        }
        
        visited.insert(start);
        
        if(start == destination){
            ans_query = temp;
            return;
        }
        
        for(auto adjacent : graph[start]){
            dfs(adjacent.first,destination,graph,visited,ans_query,temp*adjacent.second);
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string,double>> graph = buildGraph(equations,values);
        vector<double> ans;
        
        for(auto query:queries){
            string dividend = query[0];
            string divisor = query[1];
            
            if(graph.find(dividend) == graph.end() || graph.find(divisor) == graph.end()){
                ans.push_back(-1.0);
            }
            else{
                unordered_set<string> visited;
                double ans_query = -1;
                double temp = 1.0;
                
                dfs(dividend,divisor,graph,visited,ans_query,temp);
                
                ans.push_back(ans_query);
            }
        }
        
        return ans;
    }
};