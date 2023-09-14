//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
         int sum=accumulate(arr,arr+N,0);
        if(sum&1) return 0; 
       
            sum/=2; 

// Just write code for checking whether target sum , i.e

// sum can be obtained from given array or not using dp.

 


            vector<vector<int>>dp(N+1,vector<int>(sum+1,0));


            dp[0][0]=1; 


            for(int i=1; i<=N; i++){
                for(int j=1; j<=sum; j++){
                    if(arr[i-1]>j){
                        dp[i][j]=dp[i-1][j];
                    }
                    else dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
                }
            }
            
            for(int i=1; i<=N; i++){
                if(dp[i][sum]) return sum; 
            }
            return 0; 
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
