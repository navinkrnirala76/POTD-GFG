//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	int is_bleak(int n)
	{
	    // Code here.
	    int cnt=0;
        for(int i=n-sqrt(n);i<=n;i++)
        {
            int a=i;
            while(a>0)
            {
                if(a&1)
                cnt++;
                a=a>>1;
            }
           if(n==(i+cnt))
           return 0;
           cnt=0;
        }
        
        return 1;
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends
