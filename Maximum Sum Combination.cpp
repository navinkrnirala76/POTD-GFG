//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b) {
        // code here
       vector<int> ans;
       sort(a.rbegin(),a.rend());
        sort(b.rbegin(),b.rend());
        priority_queue<pair<int,pair<int,int>>> p;
        p.push({a[0]+b[0],{0,0}});
        set<pair<int,int>> st;
        
        while(!p.empty()){
            auto it=p.top();
            int val=it.first;
            
            int i=it.second.first;
            int j=it.second.second;
            ans.push_back(val);
            p.pop();
            if(ans.size()==k)return ans;
           
            if(i+1<n && j<n){
                  if(st.find({i+1,j})==st.end()){
                       p.push({a[i+1]+b[j],{i+1,j}});
                       st.insert({i+1,j});
                  }
                
            }
            if(i<n && j+1<n) {
             if(st.find({i,j+1})==st.end()){
                 p.push({a[i]+b[j+1],{i,j+1}});
                  st.insert({i,j+1});
             }
             
            }
            
        }
        return  ans;
       
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
