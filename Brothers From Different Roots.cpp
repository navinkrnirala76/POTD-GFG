void count(Node* ptr , unordered_map<int,bool>&mp,int& ans,int& x){    
        int comp = x-ptr->data;
        if(mp[comp])++ans;
        if(ptr->left==nullptr&&ptr->right==nullptr)return;
        if(ptr->left)count(ptr->left,mp,ans,x);
        if(ptr->right)count(ptr->right,mp,ans,x);
    }
    
    void dfs(Node* ptr,unordered_map<int,bool>&mp ){
        mp[ptr->data]=true;
        if(ptr->left==nullptr&&ptr->right==nullptr)return;
        if(ptr->left)dfs(ptr->left,mp);
        if(ptr->right)dfs(ptr->right,mp);
    }
    
public:
    int countPairs(Node* root1, Node* root2, int x)
    {
        unordered_map<int,bool>mp;
        dfs(root1,mp);
        int ans=0;
        count(root2,mp,ans,x);
        return ans;
    }
