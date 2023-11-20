class Solution {
public:
    vector<string> garbageG;
    vector<int> travelG;
    
    int collectGarbage(char type){
        int tempPrev = 0;
        int cost = 0;
        
        for(int i=0;i<garbageG.size();i++){
            int temp = 0;
            bool tempAdd = false;
            
            if(i>0){
                temp = travelG[i-1];
            }
            
            for(int j=0;j<garbageG[i].length();j++){
                if(garbageG[i][j] == type){
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
        
        garbageG = garbage;
        travelG = travel;
        
        return collectGarbage('M') + collectGarbage('P') + collectGarbage('G');
    }
};