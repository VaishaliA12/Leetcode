class Solution {
    public:
        bool solve(vector<int> &piles,int start,int end,bool turn,vector<vector<int>> &dp){
            if(start>end) return 0;
            if(dp[start][end]!=-1) return dp[start][end];
            if(turn){
                int case1=solve(piles,start+1,end,false,dp)+piles[start];
                int case2=solve(piles,start,end-1,false,dp)+piles[end];
                return dp[start][end]=max(case1,case2);
            }
            int case1=solve(piles,start+1,end,true,dp)-piles[start];
            int case2=solve(piles,start,end-1,true,dp)-piles[end];
            return dp[start][end]=max(case1,case2);
        }
        bool stoneGame(vector<int>& piles) {
            int n=piles.size();
            vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
            return solve(piles,0,n-1,true,dp);
        }
    };