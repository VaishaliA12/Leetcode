class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target+1,0);
        dp[0]=1;
        for(int t=1;t<=target;t++){
            for(int i=0;i<nums.size();i++){
                int temp=nums[i];
                if(t-temp>=0) dp[t]+=dp[t-temp];
            }
        }
        return dp[target];
    }
};