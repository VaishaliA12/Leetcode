class Solution {
public:
    int solve(int i,vector<int> &sum,vector<int> &dp){
        if(i==0) return sum[0];
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick=sum[i]+solve(i-2,sum,dp);
        int not_pick=0+solve(i-1,sum,dp);
        return dp[i]=max(pick,not_pick);
    }
    int deleteAndEarn(vector<int>& nums) {
        int n=10001;
        vector<int> sum(n,0);
        for(auto num : nums) sum[num]+=num;
        vector<int> dp(n,-1);
        return solve(sum.size()-1,sum,dp);
    }
};