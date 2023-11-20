class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int metal = 0;
        int glass = 0;
        int paper = 0;
        
        for(int i=1;i<travel.size();i++){
            travel[i] += travel[i-1];
        }
        
        int n = garbage.size();
        
        int tempMetalPrev = 0;
        int tempPaperPrev = 0;
        int tempGlassPrev = 0;
        
        for(int i=0;i<n;i++){
            int temp = 0;
            bool tempAdd = false;
            
            if(i>0){
                temp = travel[i-1];
            }
            
            for(int j=0;j<garbage[i].length();j++){
                if(garbage[i][j] == 'M'){
                    metal += 1;
                    tempAdd = true;
                }
            }
            
            if(tempAdd == true){
                metal -= tempMetalPrev;
                metal += temp;
                tempMetalPrev = temp;
            }
        }
        
        for(int i=0;i<n;i++){
            int temp = 0;
            bool tempAdd = false;
            
            if(i>0){
                temp = travel[i-1];
            }
            
            for(int j=0;j<garbage[i].length();j++){
                if(garbage[i][j] == 'P'){
                    paper += 1;
                    tempAdd = true;
                }
            }
            
            if(tempAdd == true){
                paper -= tempPaperPrev;
                paper += temp;
                tempPaperPrev = temp;
            }
        }
        
        for(int i=0;i<n;i++){
            int temp = 0;
            bool tempAdd = false;
            
            if(i>0){
                temp = travel[i-1];
            }
            
            for(int j=0;j<garbage[i].length();j++){
                if(garbage[i][j] == 'G'){
                    glass += 1;
                    tempAdd = true;
                }
            }
            
            if(tempAdd == true){
                glass -= tempGlassPrev;
                glass += temp;
                tempGlassPrev = temp;
            }
        }
        
        // cout<<"metal "<<metal<<endl;
        // cout<<"paper "<<paper<<endl;
        // cout<<"glass "<<glass<<endl;
        
        return (metal + paper + glass);
    }
};