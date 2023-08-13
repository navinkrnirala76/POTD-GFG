//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        sort(nums.rbegin(),nums.rend());
        stack<int>st;
    
        for(int i=0;i<nums.size();i++)
        {
            // Check if the stack is empty or the top of the stack == current element 
               //if TRUE then push it in the stack

            if(st.empty()||st.top()!=nums[i])
            st.push(nums[i]);
            else
            st.pop();
        }
        vector<int>ans;

//         This is for getting the elements left in the stack to our answer array 
        while(!st.empty())
        {
            int x=st.top();
            ans.push_back(x);
            st.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends
