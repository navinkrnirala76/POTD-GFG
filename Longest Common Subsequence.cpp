//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int solve(int i,int j ,string& a,string& b,int n,int m,  vector<vector<int>>&dp)
    {
        if(i==n || j == m)
        {
            return 0;
            
        }
        
        if(dp[i][j]!=-1)
        {
          return dp[i][j];  
        }
        int take=0,nottake=0;
        if(a[i]==b[j])
        {
           take=  1+solve(i+1,j+1,a,b,n,m,dp); 
        }
        else
        {
            nottake =  max(solve(i+1,j,a,b,n,m,dp),solve(i,j+1,a,b,n,m,dp));
        }
        
        return dp[i][j] = max(take,nottake);
       
       
    }
    int solvetab(string& a,string& b,int n,int m)
    {
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
         
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                int take=0,nottake=0;
                if(a[i]==b[j])
                {
                   take=  1+dp[i+1][j+1]; 
                }
                else
                {
                    nottake =  max(dp[i+1][j],dp[i][j+1]);
                }
                
                dp[i][j] = max(take,nottake);
               
            }
        }
        
        return dp[0][0];
       
       
    }
    
    int solvetabOptimal(string& a,string& b,int n,int m)
    {
        vector<int>curr(m+1,0);
        vector<int>next(m+1,0);
         
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                int take=0,nottake=0;
                if(a[i]==b[j])
                {
                   take=  1+next[j+1]; 
                }
                else
                {
                    nottake =  max(next[j],curr[j+1]);
                }
                
                curr[j] = max(take,nottake);
               
            }
            
            next = curr;
        }
        
        return next[0];
       
       
    }
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        //  return solve(0,0,s1,s2,n,m,dp);
        // return solvetab(s1,s2,n,m);
        return solvetabOptimal(s1,s2,n,m);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends
