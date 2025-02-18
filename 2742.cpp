class Solution {
    public:
        int solve(vector<int> &cost,vector<int> &time,int i,int j,vector<vector<int>> &dp){
            if(j<=0) return 0;
            if(i>=cost.size()) return 1e9;
            if(dp[i][j]!=-1) return dp[i][j];
            int not_take=solve(cost,time,i+1,j,dp);
            int take=cost[i]+solve(cost,time,i+1,j-time[i]-1,dp);
            return dp[i][j]=min(not_take,take);
        }
        int paintWalls(vector<int>& cost, vector<int>& time) {
            int n=cost.size();
            vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
            return solve(cost,time,0,n,dp);
        }
    };