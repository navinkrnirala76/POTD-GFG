//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
         vector<vector<int>> temp;

    // Create a vector of vectors with finish time, start time, and meeting index
    for (int i = 0; i < N; i++) {
        temp.push_back({F[i], S[i], i + 1});
    }

    // Sort the vector of vectors based on finish time
    sort(temp.begin(), temp.end());

    vector<int> res;
    res.push_back(temp[0][2]); // Add the first meeting to the result
    int end_time = temp[0][0]; // Set the end time to the finish time of the first meeting

    // Iterate through the sorted meetings and select non-overlapping meetings
    for (int i = 1; i < N; i++) {
        if (temp[i][1] > end_time) {
            res.push_back(temp[i][2]); // Add the meeting to the result
            end_time = temp[i][0]; // Update the end time
        }
    }

    // Sort the result vector
    sort(res.begin(), res.end());

    return res; 
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
