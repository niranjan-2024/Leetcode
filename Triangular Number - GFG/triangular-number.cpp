//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    public:
    
    int isTriangular(int N){
        if( N == 0 || N == 1){
            return true;
        }
        
        int prev = 1;

        for(int i=2;i<N;i++){
            prev += i;
            if(prev == N){
                return 1;
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        Solution ob;
        cout<<ob.isTriangular(N)<<"\n";
    }
}
// } Driver Code Ends