//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
          for(int j=0;j<m;j++)
          {
              if(i==0||j==0||i==n-1||j==m-1)
              {
                  if(grid[i][j]==1)
                  {
                      q.push({i,j});
                      grid[i][j]=-1;
                  }
              }
          }
        }
        while(!q.empty())
        {
            int row[]={-1,0,1,0};
            int col[]={0,1,0,-1};
            int f=q.front().first;
            int s=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int r=row[i]+f;
                int c=col[i]+s;
                if(r<n&&r>=0&&c<m&&c>=0)
                {
                    if(grid[r][c]==1)
                    {
                        grid[r][c]=-1;
                        q.push({r,c});
                    }
                }
            }
            
        }
        int ans=0;
         for(int i=0;i<n;i++)
        {
          for(int j=0;j<m;j++)
          {
              
              
                  if(grid[i][j]==1)
                  {
                     ans++;
                  }
              
          }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends
