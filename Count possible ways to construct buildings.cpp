//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here
	    const int MOD = 1000000007;
        
        vector<long long>dp(N+3);
        dp[0]=0;
        dp[1]=1;
        
        for(int i=2;i<N+3;i++){
            dp[i] = ((dp[i-1]%MOD) + (dp[i-2]%MOD))%MOD;
        }
        
        return ((dp[N+2]%MOD)*(dp[N+2]%MOD))%MOD;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
