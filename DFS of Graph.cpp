class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int v, vector<int> adj[], vector<int>& ans, vector<bool>& vis){
        
        if(vis[v]) return;
        
        vis[v] = true;
        ans.push_back(v);
        
        for(auto child : adj[v]){
            dfs(child, adj, ans, vis);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<bool> vis(V, false);
        
        dfs(0, adj, ans, vis);
        
        return ans;
    }
};
