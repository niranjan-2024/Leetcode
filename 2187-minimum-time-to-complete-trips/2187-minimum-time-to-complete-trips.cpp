class Solution {
public:
    
    long long int tripsTillNow(vector<int> &time,long long int totalTime){
        long long int trips = 0;
        for(auto n:time){
            long long int timePerTrip = n;
            trips += (totalTime/timePerTrip);
        }
        return trips;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long int left = 1;
        long long int right = 1e14;
        
        while(left<right){
            long long int mid = left + (right-left)/2;
            if(tripsTillNow(time,mid) >= totalTrips){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        
        return left;
    }
};