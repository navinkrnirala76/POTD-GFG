//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    private:
        void dfs(int V, vector<int> adj[], vector<bool>& vis, int i, int &c){
            vis[i]=true;
            c++;
            for(const auto& it: adj[i]){
                if(!vis[it]){
                    dfs(V, adj, vis, it, c);
                }
            }
            
        }
        
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	      vector<bool> vis(V, false);
	    int ans;
	    int c=0;
	    for(int i=0; i<V; ++i){
	        if(!vis[i]){
	            dfs(V, adj, vis, i, c);
	            ans=i;
	            c=0;
	        }
	    }
	    vis.assign(V, false);
	    dfs(V, adj,vis, ans, c);
	    if(c==V) return ans;
	    return -1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
