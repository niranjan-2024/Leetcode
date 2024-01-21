class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0;
        
        vector<int> PLE(n,-1) , NLE(n,n);
        stack<int> P,N;
        
        for(int i=n-1;i>=0;i--){
            while(!P.empty() && arr[i] < arr[P.top()]){
                PLE[P.top()] = i;
                P.pop();
            }
            P.push(i);
        }
        
        for(int i=0;i<n;i++){
            while(!N.empty() && arr[i] <= arr[N.top()]){
                NLE[N.top()] = i;
                N.pop();
            }
            N.push(i);
        }
        
        for(int i=0;i<n;i++){
            sum = sum + (long long)((long long)arr[i]*(long long)(abs(PLE[i]-i))*(abs(NLE[i]-i)))%1000000007;
        }
        
        return sum%1000000007;
    }
};