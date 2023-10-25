//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
      int solve(int N, int W, int val[], int wt[] , vector<int> &dp){
        
        if(W == 0){
            return 0;
        }
        if(W<0){
            return INT_MIN;
        }
        if(dp[W] != -1){
            return dp[W];
        }
        
        int maxprofit = 0;
        for(int i=0;i<N;i++){
            
            int include = 0;
            include = val[i] + solve(N,W-wt[i],val,wt,dp);
            maxprofit = max(include,maxprofit);
            
        }
        dp[W] = maxprofit;
        return dp[W];
        
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<int> dp(W+1,-1);
        return solve(N,W,val,wt,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends
