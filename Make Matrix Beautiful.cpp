//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here  
        int sum=0,rs=0,cs=0;
       for(int i=0;i<n;i++){
           int s1=0,s2=0;
           for(int j=0;j<n;j++){
               sum+=matrix[i][j];
                s1+=matrix[i][j];
                s2+=matrix[j][i];
           }
           rs=max(rs,s1); cs=max(cs,s2);
       }
       return max(rs,cs)*n-sum;
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends
