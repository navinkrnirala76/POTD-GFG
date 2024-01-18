//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        // code here
          vector<pair<int , int>>v ;
        for( int i = 0 ; i < n ; i++ )
        {
            if( gallery[i] != -1 ) 
            {
                v.push_back({ max( 0 , i - gallery[i]) , min( n , i + gallery[i] ) }) ;
            }
            
        }
        
        sort( v.begin() , v.end() ) ;
        int ans = 0 , i = 0 , start = 0 ;
        
        while( start < n )
        {
            int maxi = INT_MIN ;
            while( i < v.size() )
            {
                if( v[i].first > start ) break ;
                maxi = max( maxi , v[i].second ) ;
                i++ ;
            }
            
            if( maxi < start ) return -1 ;
            ans++ ;
            start = maxi + 1 ;
        }
        
        return ans ;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends
