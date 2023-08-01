//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
         if(A[0][0]==0||A[X][Y]==0)
            return -1;
        
        vector<vector<int>>vis(N,vector<int>(M,0));
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        vis[0][0]=1;
        vector<pair<int,int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            int dis=p.first;
            int r=p.second.first;
            int c=p.second.second;
            
            if(r==X&&c==Y)
            return dis;
            
            for(auto &d:dir){
                int x=d.first+r;
                int y=d.second+c;
                
                if(x>=0&&x<N&&y>=0&&y<M&&vis[x][y]==0&&A[x][y]==1){
                    pq.push({dis+1,{x,y}});
                    vis[x][y]=1;
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends
