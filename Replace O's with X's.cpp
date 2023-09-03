//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        int delx[]={1,0,-1,0};
           int dely[]={0,1,0,-1};
           vector<vector<char>>ans(n,vector<char>(m,'X'));
           vector<vector<bool>>visit(n,vector<bool>(m,false));
           queue<pair<int,int>>q;
           for(int i=0;i<n;i++){
               
               for(int j=0;j<m;j++){
                   
                   if(i==0 || j==0 || i==n-1 || j==m-1){
                       
                       if(mat[i][j]=='O'){
                           
                           visit[i][j]=true;
                           q.push({i,j});
                           ans[i][j]='O';
                       }
                       
                   }
                   
               }
               
           }
           
           
           while(q.empty()==false){
               
               int x=q.front().first;
               int y=q.front().second;
               
               q.pop();
               for(int i=0;i<4;i++){
                   
                   int row=x+delx[i];
                   int col=y+dely[i];
                   if(row>=0 && row<n && col>=0 && col<m && visit[row][col]==false && mat[row][col]=='O'){
                       
                       visit[row][col]=true;
                       q.push({row,col});
                       ans[row][col]='O';
                       
                   }
                   
               }
               
               
           }
           
           return ans;
           
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
