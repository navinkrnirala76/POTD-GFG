//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        // code here
        if(N<=1) return 0;
        
        long long sum = 1;
        int sqrtN = sqrt(N);
        
        for(int f=2;f<=sqrtN;f++){
            if(N%f==0) {
                sum+=f;
                if(f != N/f) sum+=N/f; //since the loop is only till sqrtN , this covers all the factors
            }
        }
        return sum == N ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends
