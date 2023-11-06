//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[])
    {
        // code here
         vector<int>ans;
        
        int dr1[]={0,0,1,-1,1,-1,1,-1};
        int dc1[]={1,-1,0,0,1,-1,-1,1};
        int dr2[]={0,0,-2,2,-2,-2,-2,-2,-1,-1,1,1,2,2,2,2};
        int dc2[]={2,-2,0,0,1,2,-1,-2,2,-2,-2,2,1,2,-1,-2};
        for(int k=0;k<q;k++){
            vector<int>v;
            v = queries[k];
            int i = v[1];
            int j = v[2];
            int hop = v[0];
            if(hop==1){
                int sum = 0;
                
                for(int x = 0;x<8;x++){
                    int nr = i+dr1[x];
                    int nc = j+dc1[x];
                    if(nr>=0 && nr<n && nc>=0 && nc<m){
                        sum+=mat[nr][nc];
                    }
                }
                ans.push_back(sum);
                
            }
            else{
                int sum = 0;
                
                for(int x = 0;x<16;x++){
                    int nr = i+dr2[x];
                    int nc = j+dc2[x];
                    if(nr>=0 && nr<n && nc>=0 && nc<m){
                        sum+=mat[nr][nc];
                    }
                }
                ans.push_back(sum);
                
            }
        }   return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, q, ty, i, j;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin>>mat[i][j];
        cin>>q;
        vector<int> queries[q];
        for(int k = 0;k < q;k++){
            cin>>ty>>i>>j;
            queries[k].push_back(ty);
            queries[k].push_back(i);
            queries[k].push_back(j);
        }
        
        Solution ob;
        vector<int> ans = ob.matrixSum(n, m, mat, q, queries);
        for(int u: ans)
            cout<<u<<"\n";
    }
    return 0;
}
// } Driver Code Ends
