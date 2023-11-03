//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    // code here
	     int max_val = *max_element(arr, arr + n);
 
unordered_set<int> square_set;
for (int i = 0; i < n; i++) {
    square_set.insert(arr[i] * arr[i]);
}
 
for (int i = 0; i <= max_val; i++) {
    for (int j = i + 1; j <= max_val; j++) {
        int a_square = i * i;
        int b_square = j * j;
        int c_square = a_square + b_square;
        if (square_set.find(c_square) != square_set.end() && square_set.find(a_square) != square_set.end() && square_set.find(b_square) != square_set.end()) {
            return true;
        }
    }
}
 
return false;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}

// } Driver Code Ends
