class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            int n=nums.size();
            sort(nums.begin(),nums.end());
            vector<int> dp(n,1);
            vector<int> hash(n,1);
            for(int i=0;i<n;i++){
                hash[i]=i;
                for(int j=0;j<i;j++){
                    if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]){
                        dp[i]=1+dp[j];
                        hash[i]=j;
                    }
                }
            }
            int ans=-1;
            int lastInd=-1;
            for(int i=0;i<n;i++){
                if(dp[i]>ans){
                    ans=dp[i];
                    lastInd=i;
                }
            }
            vector<int> res;
            res.push_back(nums[lastInd]);
            while(hash[lastInd]!=lastInd){
                lastInd=hash[lastInd];
                res.push_back(nums[lastInd]);
            }
            reverse(res.begin(),res.end());
            return res;
        }
    };