//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
          vector<int>ar;
        int c=0;
        int j=1;
        int m=0;
        sort(arr,arr+n);
        for(int i=0;i<n;i++)
        {
            if(arr[i]==arr[j])
            {
                j=j+1;
            
                if(c!=1)
                {
                    ar.push_back(arr[i]);
                    c=1;
                    m=1;
                }
                i=i-1;
            }
            else
            {
                j=j+1;
                c=0;
                i=j-2;
            }
            
            
            
        }
        if(m==0)
        {
            ar.push_back(-1);
        }
        sort(ar.begin(),ar.end());
        return ar;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
