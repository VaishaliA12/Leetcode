class Solution {
    public:
        int mod=1e9+7;
        long long solve(int n,int goal,int k,vector<vector<int>> &dp){
            if(n==0 && goal==0) return 1;
            if(n==0 || goal==0) return 0;
            if(dp[n][goal]!=-1) return dp[n][goal];
            long long pick=solve(n-1,goal-1,k,dp)*n;
            long long not_pick=solve(n,goal-1,k,dp)*max(n-k,0);
            return dp[n][goal]=(pick+not_pick)%mod;
        }
        int numMusicPlaylists(int n, int goal, int k) {
            vector<vector<int>> dp(n+1,vector<int> (goal+1,-1));
            return solve(n,goal,k,dp);
        }
    };