//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long long count(long long n)
    {
        return (long long)(n*(n+1))/2ll;
    }
    long countSubarrays(int a[], int n, int L, int R)
    {
        // Complete the function
        long long ans1 = 0;
        long long ans2 = 0;
        long long inc = 0;
        long long exc = 0;
        for(int i = 0; i < n; i++)
        {
            if(a[i] >= L) 
            {
                ans1 += count(exc);
                exc = 0;
            }
            else exc++;
            if(a[i] > R) 
            {
                ans2 += count(inc);
                inc = 0;
            }
            else inc++;
            // exc++;
            // inc++;
        }
        ans1 += count(exc);
        ans2 += count(inc);
        return ans2- ans1;
    }
};

//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends
