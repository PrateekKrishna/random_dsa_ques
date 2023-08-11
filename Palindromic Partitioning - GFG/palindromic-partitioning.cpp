//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isPal(string s, int i, int j){
        while(i<=j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    int dp[1001];
    int func(string &s, int i){
        int n=s.size();
        if(i>=n) return 0;
        int ans=1e9;
        if(dp[i] != -1) return dp[i];
        for(int k=i; k<n; k++){
            if(isPal(s, i, k)){
                int tmp = 1 + func(s, k+1);
                ans=min(ans, tmp);
            }
        }
        return dp[i] = ans;
    }
    int palindromicPartition(string str)
    {
        memset(dp, -1, sizeof dp);
        return func(str, 0)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends