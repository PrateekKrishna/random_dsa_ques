//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[51][51];
    int func(int i, int j, int n, int m, vector<vector<int>> &grid){
        if(i<0 || i>=n || j<0 || j>=m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int up = grid[i][j] + func(i-1, j+1, n, m, grid);
        int right = grid[i][j] + func(i, j+1, n, m, grid);
        int down = grid[i][j] + func(i+1, j+1, n, m, grid);
        
        return dp[i][j] = max(up, max(right, down));
    } 
    int maxGold(int n, int m, vector<vector<int>> &grid)
    {
        memset(dp, -1, sizeof dp);
        int ans=0;
        for(int i=0; i<n; i++){
            ans=max(ans, func(i, 0, n, m, grid));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends