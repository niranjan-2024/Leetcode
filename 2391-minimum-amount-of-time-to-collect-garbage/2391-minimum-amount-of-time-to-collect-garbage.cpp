class Solution {
public:
    
    int collectGarbage(vector<string>& garbage, vector<int>& travel, char type){
        int tempPrev = 0;
        int cost = 0;
        
        for(int i=0;i<garbage.size();i++){
            int temp = 0;
            bool tempAdd = false;
            
            if(i>0){
                temp = travel[i-1];
            }
            
            for(int j=0;j<garbage[i].length();j++){
                if(garbage[i][j] == type){
                    cost += 1;
                    tempAdd = true;
                }
            }
            
            if(tempAdd == true){
                cost -= tempPrev;
                cost += temp;
                tempPrev = temp;
            }
        }
        
        return cost;
    }
    
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        for(int i=1;i<travel.size();i++){
            travel[i] += travel[i-1];
        }
        
        return collectGarbage(garbage,travel,'M') + collectGarbage(garbage,travel,'P') + collectGarbage(garbage,travel,'G');
    }
};