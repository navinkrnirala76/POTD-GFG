//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        // Code here
        vector<int> ans;
        int r=matrix.size();
        int k=0;
        
        for(int i=0;i<r;i++)
        {
            k=0;
            for(int j=i;j>=0;j--)
            {
                ans.push_back(matrix[k++][j]);
            }
        }
        
        for(int i=1;i<r;i++)
        {
            k=i;
            for(int j=r-1;j>=i;j--)
            {
                ans.push_back(matrix[k++][j]);
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
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
