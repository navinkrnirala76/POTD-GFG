//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int mx = 0;
	    vector<int> msis(arr, arr+n);
	    for(int i = 1;i<n;i++){
	        for(int j = 0;j<i;j++){
	            if(arr[i]>arr[j] && msis[i]<msis[j] + arr[i]) 
	                msis[i] = msis[j] + arr[i];
	        }
	    }
	    return *max_element(msis.begin(), msis.end());
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
