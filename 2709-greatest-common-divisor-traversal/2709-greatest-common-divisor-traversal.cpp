class unionFind{
    public:
    
    vector<int> parent;
    vector<int> rank;
    
    unionFind(int n)
    {
        parent = vector<int> (n);
        
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        
        rank = vector<int> (n,0);
    }
    
    int findParent(int i)
    {
        if(i==parent[i]){
            return i;
        }
        
        return parent[i] = findParent(parent[i]);
    }
    
    bool areconnected(int i,int j)
    {
        return (findParent(i)==findParent(j));
    }
    
    bool unify(int i,int j)
    {
        i = findParent(i);
        j = findParent(j);
        
        if(i==j){
            return false;
        }
        
        if(rank[i]>rank[j])
        {
            parent[j] = i;
            rank[i]++;
        }
        else
        {
            parent[i] = j;
            rank[j]++;
        }
        
        return true;
    }
    
    int components()
    {
        int count = 0;
        
        for(int i = 0;i<parent.size();i++)
        {
            if(i==parent[i]){
                count++;
            }
        }
        
        return count;
    }

};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        unionFind uf(n);
        
        unordered_map<int,vector<int>> adj;

        for(int i=0;i<n;i++)
        {
            int num = nums[i];

            if((num&1)==0){
                adj[2].push_back(i);
            }
            
            while((num&1)==0){
                num/=2;
            }

            for(int j=3;j*j<=num;j+=2)
            {
                if(num%j==0){
                    adj[j].push_back(i);
                }
                
                while(num%j==0){
                    num/=j;
                }
            }

            if(num>2){
                adj[num].push_back(i);
            }
            
        }

        for(auto [key,vec] : adj)
        {
            for(int i=1;i<vec.size();i++)
            {
                uf.unify(vec[0],vec[i]);
            }
        }
        
        return uf.components()==1 ? true : false;
    }
};