//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    vector<string> ans;
    void solve(string s, int l, int r){
        if(l >= r){
            ans.push_back(s);
            return;
        }
        for(int i = l; i<r; i++){
            swap(s[l], s[i]);
            solve(s, l+1, r);
            swap(s[l], s[i]);
        }
    }
    
    vector<string> permutation(string S)
    {
        //Your code here
         int i = 0;
        int j = S.length();
        ans.clear();
        solve(S, i, j);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends
