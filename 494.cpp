class Solution {
    public:
        int findTargetSumWays(vector<int>& nums, int target) {
            int n=nums.size();
            int sum=0;
            int mod=1e9+7;
            for(auto num : nums) sum+=num;
            if(sum-target<0 || (sum-target)%2!=0) return 0;
            int t=(sum-target)/2;
            vector<vector<int>> dp(n,vector<int> (t+1,0));
            if(nums[0]==0) dp[0][0]=2;
            else dp[0][0]=1;
            if(nums[0]!=0 && nums[0]<=t) dp[0][nums[0]]=1;
            for(int i=1;i<n;i++){
                for(int j=0;j<=t;j++){
                    int not_take=dp[i-1][j];
                    int take=0;
                    if(nums[i]<=j) take=dp[i-1][j-nums[i]];
                    dp[i][j]=(take+not_take)%mod;
                }
            }
            return dp[n-1][t];
        }
    };