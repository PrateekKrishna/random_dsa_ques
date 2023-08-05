//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int dp[101][101];
    int func(int i, int j, string &s, string &t){
        // if(i<0&&j<0) return 1e9;
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]){
            return dp[i][j] = func(i-1, j-1, s, t);
        }else{
            int ins = func(i, j-1, s, t);
            int rem = func(i-1, j, s, t);
            int rep = func(i-1, j-1, s, t);
            return dp[i][j] = 1+min({ins, rem, rep});
        }
    }
    int editDistance(string s, string t) {
        memset(dp, -1, sizeof dp);
        return func(s.size()-1, t.size()-1, s, t);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends