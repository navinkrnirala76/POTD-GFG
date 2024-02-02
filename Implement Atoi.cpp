//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int  minus = 1 ;
        int j = 0 ;
        int length = 0 ;
        if(s[0]=='-'){j=1 ; minus = -1 ;}
       for(int i = j ; i<s.length();i++){ if(!(s[i]>='0' && s[i]<='9')) return -1 ; length++ ;}
       length=length-1;
       
       
       int index = j ;
       int ans = 0 ;
       while(length>=0)
       {
           ans = ans + (s[index++]-48)*pow(10,length);
           
           length--;
       }
       
       return ans*minus;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends
