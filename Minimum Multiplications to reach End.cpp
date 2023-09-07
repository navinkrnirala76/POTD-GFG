//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(start == end) return 0;
        int visited[100000]{0};
        queue<int> q;
        int count = 0;
        q.push(start);
        visited[start] = true;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int num = q.front(); q.pop();
                if(num == end){
                    return count; 
                }
                for(int change : arr){
                    int changedNum = (num * change)%100000;
                    if(!visited[changedNum]){
                        visited[changedNum] = 1;
                        q.push(changedNum);
                    }
                }    
            }
            count++;
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends
