//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        // Your code goes here
        int cnt_1=0, cnt_0=0, max_0=0;
        
        for(int i=0; i<n; i++)
        {
            if(a[i] == 0) 
            {
                cnt_0++;
                max_0 = max(max_0, cnt_0);
            }
            else
            {
                cnt_1++;
                cnt_0--;
            }
            if(cnt_0 < 0) cnt_0 = 0;
        }
        return max_0 + cnt_1;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends
