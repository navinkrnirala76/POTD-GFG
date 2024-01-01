//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
         int n=nums.size();
        if(n&1)return false;
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            int val=nums[i]%k;
            if(val==0){
                if(mp.find(0)==mp.end())mp[0]++;
                else mp[0]--;
                continue;
            }
            int check=k-val;
            if(mp.find(check)==mp.end())mp[val]++;
            else mp[check]--;
        }
        for(auto it:mp){
           // cout<<it.second<<" "<<endl;
            if(it.second>0)return false;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends
