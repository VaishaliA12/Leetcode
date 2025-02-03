class Solution {
public:
    int solve(vector<int> &nums){
        int n=nums.size();
        int prev1=nums[0],prev2=0;
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1) pick+=prev2;
            int not_pick=0+prev1;
            int curr=max(pick,not_pick);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> nums1(nums.begin()+1,nums.end());
        vector<int> nums2(nums.begin(),nums.end()-1);
        int ans1=solve(nums1);
        int ans2=solve(nums2);
        return max(ans1,ans2);
    }
};