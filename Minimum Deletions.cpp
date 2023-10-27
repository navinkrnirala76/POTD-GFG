//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int n;
   string s;
   
   vector<vector<int>>dp;
   int solve(int i,int j)
    {
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]!=s[j])
        {
            int ans1= 1+solve(i+1,j);
            int ans2= 1+solve(i,j-1);
            return dp[i][j]=min(ans1,ans2);
        }
        
        return dp[i][j]= solve(i+1,j-1);
    }
    int minimumNumberOfDeletions(string S) { 
        // code here
        
        n=S.length();
        s=S;
        dp.resize(n,vector<int>(n,-1));
        return solve(0,n-1);
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends
