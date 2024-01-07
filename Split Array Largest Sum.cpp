//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int splitArray(int arr[] ,int N, int K) {
        // code here
        int l = *max_element(arr,arr+N);
        int h = accumulate(arr,arr+N,0);
        int ans=0;
        while(l<=h){
            int mid =(l+h)/2;
            if(check(mid,arr,K,N)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
    bool check(int mid,int arr[],int K,int N){
        int total=1,sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
            if(sum>mid){
                sum=arr[i];
                total++;
            }
        }
        return total<=K;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
