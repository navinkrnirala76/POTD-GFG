//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
       int checkPrime(int n){
        if(n==1){
            return 0;
        }
        if(n==2){
            return 1;
        }
        for(int i=2; i<=sqrt(n); i++){
            if(n%i == 0){
                return 0;
            }
        }
        return 1;
    }
    
    int sumDigit(int c){
        int sum = 0;
        while(c>0){
            int a = c%10;
            sum = sum+a;
            c = c/10;
        }
        return sum;
    }
    
    int smithNum(int n) {
        // code here
        vector<int> v;
        if(n==2){
            return 0;
        }
        else{
            for(int i=2; i<n; i++){
            int temp = n;
            
            int t=checkPrime(i);
            if(t==1){
                while(temp%i == 0 && temp>0){
                    v.push_back(i);
                    temp=temp/i;
                }
            }
        }
        }
        int sizee = v.size();
        int sum2= 0;
        for(int i=0; i<sizee; i++){
            sum2 += sumDigit(v[i]);
        }
        int sum=sumDigit(n);
        
        if(sum == sum2){
            return 1;
        }
        else{
            return 0;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends
