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
        
        int prev,curr = 0;
        prev = 1;

        for(int i=2;i<N;i++){
            curr = i+prev;
            if(curr == N){
                return 1;
            }
            prev = curr;
            curr = 0;
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