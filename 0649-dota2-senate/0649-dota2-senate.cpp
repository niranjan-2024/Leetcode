class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        
        queue<int> R,D;
        
        for(int i=0;i<n;i++){
            senate[i] == 'R' ? R.push(i) : D.push(i);
        }
        
        while(!R.empty() && !D.empty()){
            int a = R.front(),b = D.front();
            R.pop(),D.pop();
            
            a<b ? R.push(a+n) : D.push(b+n);
        }
        
        return R.size() > D.size() ? "Radiant" : "Dire";
    }
};