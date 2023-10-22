//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution
{
    public:
    long long  numberOfPaths(int M, int N)
    {
        // Code Here
          if (M == 0 || N == 0) {
            return 0;
        }
        if(M == 1 || N == 1){
            return 1;
        }

        vector<long long> curr(N,0);
        vector<long long> prev(N,1);
    
        // Fill the dp table iteratively
        for (int i = M - 2; i >= 0; i--) {
            curr[N-1] = 1;
            for (int j = N - 2; j >= 0; j--) {
                curr[j] = (prev[j] + curr[j+1]) % 1000000007;
            }
            prev = curr;
        }
    
        return curr[0];
    }
};


//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N, M;
		cin>>M>>N;
		Solution ob;
	    cout << ob.numberOfPaths(M, N)<<endl;
	}
    return 0;
}
// } Driver Code Ends
