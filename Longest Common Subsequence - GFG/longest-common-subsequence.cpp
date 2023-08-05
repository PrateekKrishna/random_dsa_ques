//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int dp[1001][1001];
    int func(int i, int j, string &s, string &t){
        if(i<0 || j<0) return 0;
        if(dp[i][j] !=-1) return dp[i][j];
        if(s[i] == t[j]) return dp[i][j] = 1 + func(i-1, j-1, s, t);
        else return dp[i][j] = max(func(i-1, j, s, t), func(i, j-1, s, t));
    }
    int lcs(int n, int m, string s1, string s2)
    {
        memset(dp, -1,sizeof dp);
        return func(n-1, m-1, s1, s2);
        // your code here
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends