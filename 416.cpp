class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum=0;
        for(int i=0;i<nums.size();i++) totalSum+=nums[i];
        if(totalSum%2==1) return false;
        else{
            int n=nums.size();
            int k=totalSum/2;
            vector<vector<bool>> dp(n,vector<bool>(k+1,false));
            for(int i=0;i<n;i++) dp[i][0]=true;
            if(nums[0]<=k) dp[0][nums[0]]=true;
            for(int i=1;i<n;i++){
                for(int target=1;target<=k;target++){
                    bool notTaken=dp[i-1][target];
                    bool taken=false;
                    if(nums[i]<=target) taken=dp[i-1][target-nums[i]];
                    dp[i][target]=notTaken||taken;
                }
            }
            return dp[n-1][k];
        }
    }
};