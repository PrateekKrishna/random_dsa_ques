//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  long long dp[1001][1001];
    long long func(int i, int coins[], int n, int sum){
        if(sum==0) return 1;
        if(i<0) return 0;
        if(dp[i][sum] != -1) return dp[i][sum];
        long long np = func(i-1, coins, n, sum);
        long long p=0;
        if(sum - coins[i] >=0 ){
            p = func(i, coins, n, sum-coins[i]);
        }
        return dp[i][sum] = p+np;
    }
    long long int count(int coins[], int N, int sum) {
        memset(dp, -1, sizeof dp);
        return func(N-1, coins, N, sum);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends