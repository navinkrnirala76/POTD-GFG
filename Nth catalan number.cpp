//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        //code here
        int cb = n;
        int ob = n;
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=0 ; i<=n ; i++){
            dp[0][i]=1;
        }
        for(int ob=1 ; ob<n+1 ; ob++){
            for(int cb=1 ; cb<n+1 ; cb++){
                if(ob==cb){
                    dp[ob][cb] = (dp[ob-1][cb])%1000000007;
                }
                else{
                    dp[ob][cb] = (dp[ob-1][cb] + dp[ob][cb-1])%1000000007;
                }
            }
        }
        return dp[n][n];
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends
