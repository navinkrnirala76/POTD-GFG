//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	     int n = grid.size(),m = grid[0].size(),len = word.length();
        bool isPresent = 1;
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == word[0]){
                    
                    //Right
                    for(int k=1; k<len; k++){
                        if(j+k>=m || grid[i][j+k] != word[k]){
                            isPresent = 0;break;
                        }
                    }
                    if(isPresent) {
                        ans.push_back({i,j});continue;
                    }
                    isPresent = 1;
                    
                    //left
                    for(int k=1; k<len; k++){
                        if(j-k<0 || grid[i][j-k] != word[k]){
                            isPresent = 0;break;
                        }
                    }
                    if(isPresent) {ans.push_back({i,j});continue;}
                    isPresent = 1;
                    
                    //up
                    for(int k=1; k<len; k++){
                        if(i-k<0 || grid[i-k][j] != word[k]){
                            isPresent = 0; break;
                        }
                    }
                    if(isPresent) {ans.push_back({i,j});continue;}
                    isPresent = 1;
                    
                    //down
                    for(int k=1; k<len; k++){
                        if(i+k>=n || grid[i+k][j] != word[k]){
                            isPresent = 0;break;
                        }
                    }
                    if(isPresent) {ans.push_back({i,j});continue;}
                    isPresent = 1;
                    
                    //w-n
                    for(int k=1; k<len; k++){
                        if(i-k<0 || j-k<0 || grid[i-k][j-k] != word[k]){
                            isPresent = 0;break;
                        }
                    }
                    if(isPresent) {ans.push_back({i,j});continue;}
                    isPresent = 1;
                    
                    //n-e
                    for(int k=1; k<len; k++){
                        if(i-k<0 || j+k>=m || grid[i-k][j+k] != word[k]){
                            isPresent = 0;break;
                        }
                    }
                    if(isPresent) {ans.push_back({i,j});continue;}
                    isPresent = 1;
                    
                    //e-s
                    for(int k=1; k<len; k++){
                        if(i+k>=n || j+k>=m || grid[i+k][j+k] != word[k]){
                            isPresent = 0;break;
                        }
                    }
                    if(isPresent) {ans.push_back({i,j});continue;}
                    isPresent = 1;
                    
                    //s-w
                    for(int k=1; k<len; k++){
                        if(i+k>=n || j-k<0 || grid[i+k][j-k] != word[k]){
                            isPresent = 0;break;
                        }
                    }
                    if(isPresent) ans.push_back({i,j});
                    isPresent = 1;
                }
            }
        }
        return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends
