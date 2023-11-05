class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int maxElement = *max_element(arr.begin(),arr.end());
        
        if(k >= arr.size()){
            return maxElement;
        }
        
        int current_winner = arr[0];
        int current_streak = 0;
        
        for(int i=1;i<arr.size();i++){
            if(current_winner > arr[i]){
                current_streak++;
            }
            else{
                current_winner = arr[i];
                current_streak = 1;
            }
            
            if(current_streak == k || current_winner == maxElement){
                return current_winner;
            }
        }
        
        return current_winner;
    }
};