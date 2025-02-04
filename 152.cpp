class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int curMin=1,curMax=1;
        for(int n : nums){
            int temp=curMax*n;
            curMax=max(max(n*curMax,n*curMin),n);
            curMin=min(min(temp,n*curMin),n);
            ans=max(ans,curMax);
        }
        return ans;
    }
};