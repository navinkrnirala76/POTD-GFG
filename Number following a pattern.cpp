//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        string ans="";

        for(int i=0;i<=S.size();i++)

        {

            ans.push_back('1'+ i);

        }

        for(int i=0;i<=S.size();i++)

        {

            if(S[i]=='D')

            {

              auto beg=ans.begin()+i;

              while(i<S.size() and S[i]=='D')

              {

                  i++;

              }

              auto end=ans.begin()+i+1;

             reverse(beg,end);

            }

        }

        return ans;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
