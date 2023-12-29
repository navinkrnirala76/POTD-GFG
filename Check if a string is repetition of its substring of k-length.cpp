//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int kSubstrConcat (int n, string s, int k)
	{
	    // Your Code Here
	    map<string,int> mp;
        if(n%k != 0)
            return 0;
        if(n%k == 0 && n/k == 2)
            return 1;
        else 
        {
            string temp = "";
            for(int i = 0; i<s.size(); i=i+k)
            {
                temp = "";
                int j = 0; 
                while(j < k)
                {
                    temp+=s[i];
                    j++;
                }
                mp[temp]++;
            }
            for(auto itr = mp.begin(); itr != mp.end(); itr++)
            {
                if(itr->second >= (n/k) - 1)
                    return true;
            }
        }
        return false;
	}
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		int k; cin >> k;
        Solution  ob;
		cout << ob.kSubstrConcat (n, s, k) << endl;
	}
}
// } Driver Code Ends
