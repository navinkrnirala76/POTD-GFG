//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
         long long int sumArr[n] = {0};
        
        sumArr[0] = a[0];
        
        for (int i = 1; i < n; i++)
        {
            auto SumUptoN = sumArr[i-1] + a[i];
            
            auto maxx = max(SumUptoN, a[i]);
            
            sumArr[i] = maxx;
        }
        
        long long int sumK = 0;
        
        long long int result = 0;
        
        for (int i = 0; i < k; i++)
        {
            sumK += a[i];
        }
        result = sumK;

        for (int i = k; i < n; i++)
        {
            sumK += a[i];
            sumK -= a[i - k];
            
            long long int possibleSum = sumK + sumArr[i - k];
            
            long long int resulHere = max(possibleSum, sumK);
            
            result = max(result, resulHere);
        }
        
        return result;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends
