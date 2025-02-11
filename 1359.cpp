class Solution {
    public:
        int countOrders(int n) {
            const int mod=1e9+7;
            vector<long long> dp(n+1,0);
            dp[0]=1;
            for(int i=1;i<=n;i++){
                dp[i]=dp[i-1]*(2*i-1)*i%mod;
            }
            return dp[n];
        }
    };