class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        int mx=1,ans=0;
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[i]){
                    if(1+dp[j]>dp[i]){
                        dp[i]=1+dp[j];
                        cnt[i]=cnt[j];
                    }
                    else if(1+dp[j]==dp[i]) cnt[i]+=cnt[j];
                }
            }
            mx=max(mx,dp[i]);
        }
        for(int i=0;i<n;i++){
            if(dp[i]==mx) ans+=cnt[i];
        }
        return ans;
    }
};