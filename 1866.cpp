class Solution {
    public:
        int mod=1e9+7;
        long long solve(int n,int k,vector<vector<int>> &dp){
            if(k>n || k==0) return 0;
            if(n<=2) return 1;
            if(dp[n][k]!=-1) return dp[n][k];
            long long ans=0;
            ans=(ans+solve(n-1,k-1,dp))%mod;
            ans=(ans+(n-1)*solve(n-1,k,dp))%mod;
            return dp[n][k]=ans;
        }
        int rearrangeSticks(int n, int k) {
            vector<vector<int>> dp(n+1,vector<int> (k+1,-1));
            return solve(n,k,dp);
        }
    };