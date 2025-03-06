class Solution {
    public:
        bool solve(vector<int> &nums,vector<int> &ans,int ind,int target,int k){
            if(ind==nums.size()){
                for(int i=0;i<k;i++){
                    if(ans[i]!=target) return false;
                }
                return true;
            }
            for(int i=0;i<k;i++){
                if(ans[i]+nums[ind]<=target){
                    ans[i]+=nums[ind];
                    if(solve(nums,ans,ind+1,target,k)) return true;
                    ans[i]-=nums[ind];
                }
                if(ans[i]==0) break;
            }
            return false;
        }
        bool canPartitionKSubsets(vector<int>& nums, int k) {
            int sum=0;
            for(int num : nums) sum+=num;
            if(sum%k!=0) return false;
            int target=sum/k;
            sort(nums.rbegin(),nums.rend());
            if(nums[0]>target) return false;
            vector<int> ans(k,0);
            return solve(nums,ans,0,target,k);
        }
    };