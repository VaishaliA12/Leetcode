class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n=nums.size();
        vector<long long> sum(n);
        sum[0]=nums[0];
        for(int i=1;i<n;i++) sum[i]=sum[i-1]+nums[i];
        vector<int> left(n),right(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
            left[i]=st.empty()?0:st.top()+1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
            right[i]=st.empty()?n-1:st.top()-1;
            st.push(i);
        }
        long long ans=0;
        const int mod=1e9+7;
        for(int i=0;i<n;i++){
            long long a=left[i];
            long long b=right[i];
            long long sub_sum=sum[b]-(a>0?sum[a-1]:0);
            long long min_pro=nums[i]*sub_sum;
            ans=max(ans,min_pro);
        }
        return ans%mod;
    }
};