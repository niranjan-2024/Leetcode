class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>> pq;
        priority_queue<pair<int,int>> temp;
        
        for(int i=0;i<profits.size();i++){
            pq.push({profits[i],capital[i]});
        }
        
        while(k>0 && !pq.empty()){
            if(pq.top().second <= w){
                w += pq.top().first;
                pq.pop();
                k--;
            }
            else{
                while(!pq.empty() && pq.top().second > w){
                    temp.push({pq.top().first,pq.top().second});
                    pq.pop();
                }
                
                if(pq.empty()){
                    break;
                }
                
                w += pq.top().first;
                pq.pop();
                k--;
                
                while(!pq.empty()){
                    temp.push({pq.top().first,pq.top().second});
                    pq.pop();
                }
                
                swap(pq,temp);
            }
        }
        
        return w;
    }
};