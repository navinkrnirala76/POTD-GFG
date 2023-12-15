//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		int nthPoint(int n){
		    // Code here
		     if(n == 1 || n == 2)return n;
                int a = 1;
                int b = 1;
                int c = 0;
                for(int i = 1; i < n ; i++){
                    c = (a+b)% 1000000007;
                    a = b;
                    b = c;
                }
                return c;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
