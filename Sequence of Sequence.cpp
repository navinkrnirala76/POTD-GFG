//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
     int solve(int val, int level, vector<vector<int>> &dp) {
        if (dp[val][level] != -1) {
            return dp[val][level];
        }
        
        dp[val][level] = 0;
        
        for (int i = val; i >= 1; --i) {
            if ((i / 2) == 0) {
                break;
            }
            dp[val][level] += solve(i/2, level - 1, dp);
        }
        
        return dp[val][level];
    }
public:
    int numberSequence(int m, int n){
        // code here
        vector<vector<int>> dp(m + 1, vector<int> (n, -1));
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = i;
        }
        
        for (int j = 0; j < n; ++j) {
            dp[0][j] = 0;
        }
        
        return solve(m, n - 1, dp);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends
