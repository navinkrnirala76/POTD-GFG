/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    //Your code here
    if(!root) return {};
    vector<int> ans;
    vector<pair<Node*,int>> s1;
    vector<pair<Node*,int>> s2;
    // {node,level}
    s1.push_back({root,1});
    int s = 1; // to switch between stacks
    while(s1.size() || s2.size()) {
        if(s==1) {
            while(s1.size()) {
                auto it = s1.back();
                s1.pop_back();
                Node* node = it.first;
                int lvl = it.second;
                ans.push_back(node->data);
                if(node->right) s2.push_back({node->right,lvl+1});
                if(node->left) s2.push_back({node->left,lvl+1});
            }
            s=2;
        }
        if(s==2) {
            while(s2.size()) {
                auto it = s2.back();
                s2.pop_back();
                Node* node = it.first;
                int lvl = it.second;
                ans.push_back(node->data);  
                if(node->left) s1.push_back({node->left,lvl+1});
                if(node->right) s1.push_back({node->right,lvl+1});
            }
            s=1;
        }
    }
    return ans;
}
