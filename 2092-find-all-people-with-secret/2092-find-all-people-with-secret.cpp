struct UnionFind
{
    vector<int> parents;
    vector<bool> knows;
    
    UnionFind(const int& n): parents(vector<int>(n)), knows(vector<bool>(n,false))
    {
        for(int i=0; i<n; i++){
            parents[i] = i;
        }
        
        knows[0] = true;
    }
    
    int find(int p)
    {
        if (parents[p] == p){
            return p;
        }
        else{
            return find(parents[p]);
        }
    }
    
    void merge(int p1, int p2)
    {
        int pr1 = find(p1);
        int pr2 = find(p2);
        if (pr1 != pr2)
        {
            parents[pr1] = min(pr1,pr2);
            parents[pr2] = min(pr1,pr2);
        }
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        auto comp = [](const vector<int>& m1, const vector<int>& m2)
        {
            return m1[2]<m2[2];
        };
        
        sort(meetings.begin(), meetings.end(), comp);
        
        UnionFind uf(n);
        uf.merge(0, firstPerson);
        uf.knows[firstPerson] = true;
        
        for(int i=0; i<meetings.size(); i++)
        {
            int time = meetings[i][2];
            int index = i;
            
            while (i<meetings.size() && meetings[i][2] == time)
            {
                uf.merge(meetings[i][0], meetings[i][1]);
                i++;
            }
            
            while (index < i)
            {
                int par1 = uf.find(meetings[index][0]);
                int par2 = uf.find(meetings[index][1]);
                
                if (par1 != 0  && par2 != 0)
                {
                    uf.parents[meetings[index][0]] = meetings[index][0];
                    uf.parents[meetings[index][1]] = meetings[index][1];
                }
                
                index++;
            }
            
            i--;
        }
        
        vector<int> res;
        
        for(int i=0; i<n; i++){
            if (uf.find(i) == 0){
                res.push_back(i);
            }
        }
        return res;
    }
};