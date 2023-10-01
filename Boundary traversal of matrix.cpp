//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
        // code here
        vector<int> ans;
        for(int i=0;i<m;i++){
            if(matrix[0][i] != -1){
                ans.push_back(matrix[0][i]);
                matrix[0][i] = -1;
            }
        }
        for(int i=1;i<n;i++){
            if(matrix[i][m-1] != -1){
                ans.push_back(matrix[i][m-1]);
                matrix[i][m-1] = -1;
            }
        }
        for(int i=1;i<m;i++){
            if(matrix[n-1][m-i-1] != -1){
                ans.push_back(matrix[n-1][m-i-1]);
                matrix[n-1][m-i-1] = -1;
            }
        }
        for(int i=1;i<n-1;i++){
            if(matrix[n-i-1][0] != -1){
                ans.push_back(matrix[n-i-1][0]);
                matrix[n-i-1][0] = -1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
