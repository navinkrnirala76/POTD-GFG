//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        // code here
        int c1 = -1, c2 = -1;
        int minboy = INT_MAX;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] == x)
            {
                c1 = i;
                if (c2 != -1)
                {
                    minboy = min(minboy, abs(c1 - c2));
                }
            }
            else if (a[i] == y)
            {
                c2 = i;
                if (c1 != -1)
                {
                    minboy = min(minboy, abs(c1 - c2));
                }
            }
        }
        if (c1 == -1 or c2 == -1) return -1;
        else return minboy;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends
