unordered_map<Node*, Node*>parent;
    Node *start;
    function<void(Node*, Node*)> dfs = [&](Node* u, Node *par){
        if(!u)
            return;
        parent[u] = par;
        if(u -> data == node)
            start = u;
        dfs(u -> left, u);
        dfs(u -> right, u);
        
    };
    
    dfs(root, root);
    int ans = -1;
    while(k && parent[start] != start){
        start = parent[start];
        k--;
    }

    if(k == 0)
        ans = start -> data;
    return ans;
}
